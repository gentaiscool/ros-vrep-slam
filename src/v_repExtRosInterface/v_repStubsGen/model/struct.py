from .param import Param, ParamStruct

class Struct(object):
    def __init__(self, plugin, node):
        if node.tag != 'struct':
            raise ValueError('expected <struct>, got <%s>' % node.tag)
        self.plugin = plugin
        self.name = node.attrib['name']
        self.description = node.find('description')

        if self.name in Param.mapping.keys():
            raise ValueError('<struct> name cannot be any of '
                    + ', '.join('"%s"' % n for n in Param.mapping.keys()))

        self.fields = []
        for fieldNode in node.findall('param'):
            field = Param.factory(fieldNode)
            if field.skip:
                raise ValueError('cannot use "skip" option in <struct>')
            self.fields.append(field)

        Param.register_type(self.name, lambda node: ParamStruct(node, self.name))

