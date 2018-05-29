from .param import Param

class Command(object):
    def __init__(self, plugin, node):
        if node.tag != 'command':
            raise ValueError('expected <command>, got <%s>' % node.tag)
        self.plugin = plugin
        self.name = node.attrib['name']

        descnode = node.find('description')
        self.description = '' if descnode is None else '' if descnode.text is None else descnode.text

        self.clear_stack_after_reading_input = True
        self.clear_stack_before_writing_output = True

        help_in_args = []
        help_out_args = []

        self.params = []
        self.mandatory_params = []
        self.optional_params = []
        self.params_min = 0
        self.params_max = 0
        for paramNode in node.findall('params/param'):
            param = Param.factory(paramNode)
            help_in_args.append(param)
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
            help_out_args.append(param)
            if param.skip:
                self.clear_stack_before_writing_output = False
            elif param.write_out:
                self.returns.append(param)

        self.help_in_args_v = ['%s %s' % (p.htype(), p.name) + ('=%s' % p.hdefault() if p.default is not None else '') for p in help_in_args]
        self.help_out_args_v = ['%s %s' % (p.htype(), p.name) for p in help_out_args]
        self.help_in_args_text = ','.join(self.help_in_args_v)
        self.help_out_args_text = ','.join(self.help_out_args_v) + ('=' if help_out_args else '')
        self.help_text = '{}{}{}({})'.format(self.help_out_args_text, plugin.command_prefix, self.name, self.help_in_args_text)

        self.documentation = ''
        if self.description.strip():
            self.documentation = '\\n\\n' + self.description.strip()
            while self.documentation[-2:] == '\\n':
                self.documentation = self.documentation[:-2]

    def c_arg_list(self, defaults=False, pre_args=[], post_args=[]):
        if isinstance(pre_args, str): pre_args = [pre_args]
        if isinstance(post_args, str): post_args = [post_args]
        args = [p.declaration_with_default() if defaults else p.declaration() for p in self.params]
        args = list(pre_args) + args + list(post_args)
        return ', '.join(args)
