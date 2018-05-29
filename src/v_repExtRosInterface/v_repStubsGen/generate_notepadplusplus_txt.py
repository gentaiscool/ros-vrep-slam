from sys import argv, exit
import re
from parse import parse

if len(argv) != 3:
    print('usage: {} <reference.xml> <out-txt-file>'.format(argv[0]))
    exit(1)

plugin = parse(argv[1])

functions = []
variables = []

with open(argv[2], 'w') as ftxt:
    for cmd in plugin.commands:
        if plugin.short_name:
            func = 'sim{}.{}'.format(plugin.short_name, cmd.name)
        else:
            func = '{}{}'.format(plugin.command_prefix, cmd.name)
        functions.append(func)

    for enum in plugin.enums:
        for item in enum.items:
            if plugin.short_name:
                prefix = 'sim{}.{}.'.format(plugin.short_name, enum.name)
            else:
                prefix = enum.item_prefix
            variables.append(prefix+item)

    ftxt.write('{}\n\n{}\n'.format(' '.join(functions), ' '.join(variables)))

