from sys import argv, exit
import re
from parse import parse

if len(argv) != 3:
    print('usage: {} <callbacks.xml> <out-txt-file>'.format(argv[0]))
    exit(1)

plugin = parse(argv[1])

functions = []
variables = []

with open(argv[2], 'w') as ftxt:
    for cmd in plugin.commands:
        if plugin.short_name:
            fold = '{}{}'.format(plugin.command_prefix, cmd.name)
            fnew = 'sim{}.{}'.format(plugin.short_name, cmd.name)
            ftxt.write('{},{},\n'.format(fold, fnew))

    for enum in plugin.enums:
        for item in enum.items:
            if plugin.short_name:
                vold = 'sim_{}_{}{}'.format(plugin.name.lower(), enum.item_prefix, item)
                vnew = 'sim{}.{}.{}'.format(plugin.short_name, enum.name, item)
                ftxt.write('{},{},\n'.format(vold,vnew))

