from .param import Param

class ScriptFunction(object):
    def __init__(self, plugin, node):
        if node.tag != 'script-function':
            raise ValueError('expected <script-function>, got <%s>' % node.tag)
        self.plugin = plugin
        self.name = node.attrib['name']
        self.description = node.find('description')

        self.clear_stack_after_reading_input = True

        self.params = []
        self.mandatory_params = []
        self.optional_params = []
        self.params_min = 0
        self.params_max = 0
        for paramNode in node.findall('params/param'):
            param = Param.factory(paramNode)
            self.params_max += 1
            if param.skip:
                self.clear_stack_after_reading_input = False
            elif param.write_in:
                if param.mandatory():
                    self.params_min += 1
                    self.mandatory_params.append(param)
                elif param.optional():
                    self.optional_params.append(param)
        self.params = self.mandatory_params + self.optional_params

        self.returns = []
        for paramNode in node.findall('return/param'):
            param = Param.factory(paramNode)
            if param.write_out:
                self.returns.append(param)

    def c_arg_list(self, defaults=False, pre_args=[], post_args=[]):
        if isinstance(pre_args, str): pre_args = [pre_args]
        if isinstance(post_args, str): post_args = [post_args]
        args = [p.declaration_with_default() if defaults else p.declaration() for p in self.params]
        args = list(pre_args) + args + list(post_args)
        return ', '.join(args)
