import argparse
import os
import os.path
import errno
import re
import sys
import subprocess

from parse import parse
import model

parser = argparse.ArgumentParser(description='Generate various things for V-REP plugin.')
parser.add_argument('output_dir', type=str, default=None, help='the output directory')
parser.add_argument('--xml-file', type=str, default='callbacks.xml', help='the XML file with the callback definitions')
parser.add_argument('--lua-file', type=str, default=None, help='an optional LUA file containing docstrings')
parser.add_argument("--gen-stubs", help='generate C++ stubs', action='store_true')
parser.add_argument("--gen-lua-xml", help='generate XML translation of Lua docstrings', action='store_true')
parser.add_argument("--gen-reference-xml", help='generate merged XML (from callbacks.xml and lua.xml)', action='store_true')
parser.add_argument("--gen-reference-html", help='generate HTML documentation (from reference.xml or callbacks.xml)', action='store_true')
parser.add_argument("--gen-lua-calltips", help='generate C++ code for Lua calltips', action='store_true')
parser.add_argument("--gen-notepadplusplus-stuff", help='generate syntax hilighting stuff for notepad++', action='store_true')
parser.add_argument("--gen-deprecated-txt", help='generate deprecated functions mapping for V-REP', action='store_true')
parser.add_argument("--gen-all", help='generate everything', action='store_true')
args = parser.parse_args()

if args is False:
    SystemExit

self_dir = os.path.dirname(os.path.realpath(__file__))

def output(filename):
    return os.path.join(args.output_dir, filename)

def rel(filename):
    return os.path.join(self_dir, filename)

def runsubprocess(what, args):
    child = subprocess.Popen(args)
    child.communicate()
    if child.returncode != 0:
        print('failed to run %s' % what)
        sys.exit(1)

def runtool(what, *args):
    print('running %s' % what)
    runsubprocess(what, ['python', rel(what + '.py')] + list(args))

def runprogram(what, *args):
    print('running %s' % what)
    runsubprocess(what, [what] + list(args))

# check dependencies & inputs:
input_xml = args.xml_file
if args.gen_reference_xml:
    input_xml = output('reference.xml')
    args.gen_lua_xml = True
if args.gen_all:
    args.gen_stubs = True
    args.gen_lua_xml = True
    args.gen_reference_xml = True
    args.gen_reference_html = True
    args.gen_lua_calltips = True
    args.gen_notepadplusplus_stuff = True
    args.gen_deprecated_txt = True

# create output dir fi needed:
try:
    os.makedirs(args.output_dir)
except OSError as exc:
    if exc.errno == errno.EEXIST and os.path.isdir(args.output_dir):
        pass

plugin = parse(args.xml_file)

if args.gen_stubs:
    for ext in ('cpp', 'h'):
        runtool('external/pycpp/pycpp', '-p', 'xml_file=' + args.xml_file, '-i', rel('cpp/stubs.' + ext), '-o', output('stubs.' + ext), '-P', self_dir)

if args.gen_lua_xml:
    if not args.lua_file:
        print('no lua file defined. skipping lua_to_xml')
    else:
        runtool('lua_to_xml', args.lua_file, output('lua.xml'))

if args.gen_reference_xml:
    if not args.lua_file:
        input_xml = args.xml_file
        print('no lua file defined. skipping gen_reference_xml')
    else:
        runtool('merge_xml', args.xml_file, output('lua.xml'), output('reference.xml'))

if args.gen_reference_html:
    if os.name == 'nt':
        print('skipping xsltproc because a known bug on Windows')
    else:
        runprogram('xsltproc', '-o', output('reference.html'), rel('xsl/reference.xsl'), input_xml)

if args.gen_lua_calltips:
    if not plugin.short_name:
        print('plugin short-name not defined. skipping generate_lua_calltips')
    elif not args.lua_file:
        print('no lua file defined. skipping gen_lua_calltips')
    else:
        runtool('generate_lua_calltips', plugin.name, plugin.short_name, args.lua_file, output('lua_calltips.cpp'))

if args.gen_notepadplusplus_stuff:
    runtool('generate_notepadplusplus_xml', input_xml, output('np++.xml'))
    runtool('generate_notepadplusplus_txt', input_xml, output('np++.txt'))

if args.gen_deprecated_txt:
    runtool('generate_deprecated_txt', args.xml_file, output('deprecated_mapping.txt'))

