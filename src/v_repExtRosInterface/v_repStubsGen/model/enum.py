class Enum(object):
    def __init__(self, plugin, node):
        if node.tag != 'enum':
            raise ValueError('expected <enum>, got <%s>' % node.tag)
        self.plugin = plugin
        self.name = node.attrib['name']
        self.item_prefix = node.attrib.get('item-prefix', '')
        self.base = int(node.attrib.get('base', 0))
        self.items = [n.attrib['name'] for n in node.findall('item')]

