from sys import argv, exit
import re

if len(argv) != 3:
    print('usage: {} <input-lua-file> <output-xml-file>'.format(argv[0]))
    exit(1)

luafile = argv[1]
outfile = argv[2]

fun = None
args, rets = [], []

with open(outfile, 'w') as fout:
    fout.write('<?xml version="1.0" encoding="UTF-8" standalone="no" ?>\n')
    fout.write('<plugin>\n')

    def processTableType(t):
        if '.' in t:
            table, itemtype = t.split('.')
            if table == 'table':
                return 'table" item-type="%s' % itemtype
        return t

    def output():
        if fun:
            f, fdesc = fun
            fout.write('    <command name="{}">\n'.format(f))
            fout.write('        <description>{}</description>\n'.format(fdesc))
            fout.write('        <params>\n')
            for (t, n, d) in args:
                t = processTableType(t)
                fout.write('            <param name="{}" type="{}">\n'.format(n, t))
                fout.write('                <description>{}</description>\n'.format(d))
                fout.write('            </param>\n')
            fout.write('        </params>\n')
            fout.write('        <return>\n')
            for (t, n, d) in rets:
                t = processTableType(t)
                fout.write('            <param name="{}" type="{}">'.format(n, t))
                fout.write('                <description>{}</description>\n'.format(d))
                fout.write('            </param>\n')
            fout.write('        </return>\n')
            fout.write('    </command>\n')

    with open(luafile, 'r') as f:
        for line in f:
            m = re.match(r'\s*--\s*@([^\s]+)\s+(.*)$', line)
            if m:
                tag, line = map(lambda s: s.strip(), m.groups())
                if tag == 'fun':
                    m = re.match(r'([^\s]+)\s*(.*)$', line)
                    if m:
                        name, description = map(lambda s: s.strip(), m.groups())
                        fun = (name, description)
                elif tag in ('arg', 'ret'):
                    m = re.match(r'([^\s]+)\s+([^\s]+)\s*(.*)$', line)
                    if m:
                        dtype, name, description = map(lambda s: s.strip(), m.groups())
                        if tag == 'arg':
                            args.append((dtype, name, description))
                        elif tag == 'ret':
                            rets.append((dtype, name, description))
            else:
                output()
                fun = None
                args, rets = [], []
        output()

    fout.write('</plugin>\n')

