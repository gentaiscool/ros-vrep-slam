# V-REP Stubs generator

This utility is used to generate boilerplate code for V-REP Lua callbacks.
It reads an XML file containing a description of the callbacks, script
functions, and enums, and it produces a pair of C++ source/header files.

What you need:
- Python interpreter (2.7 or greater)
- xsltproc program in your PATH (an XSLT processor) if you want to generate documentation (windows binary available [here](https://github.com/fferri/xsltproc-win/raw/master/xsltproc-win.zip))

Usage:

```text
$ python generate.py --help
usage: generate.py [-h] [--xml-file XML_FILE] [--lua-file LUA_FILE]
                   [--gen-stubs] [--gen-lua-xml] [--gen-reference-xml]
                   [--gen-reference-html] [--gen-lua-calltips]
                   [--gen-notepadplusplus-stuff] [--gen-deprecated-txt]
                   [--gen-all]
                   output_dir

Generate various things for V-REP plugin.

positional arguments:
  output_dir            the output directory

optional arguments:
  -h, --help            show this help message and exit
  --xml-file XML_FILE   the XML file with the callback definitions
  --lua-file LUA_FILE   an optional LUA file containing docstrings
  --gen-stubs           generate C++ stubs
  --gen-lua-xml         generate XML translation of Lua docstrings
  --gen-reference-xml   generate merged XML (from callbacks.xml and lua.xml)
  --gen-reference-html  generate HTML documentation (from reference.xml or
                        callbacks.xml)
  --gen-lua-calltips    generate C++ code for Lua calltips
  --gen-notepadplusplus-stuff
                        generate syntax hilighting stuff for notepad++
  --gen-deprecated-txt  generate deprecated functions mapping for V-REP
  --gen-all             generate everything
```

See [v_repExtPluginSkeletonNG](https://github.com/fferri/v_repExtPluginSkeletonNG) for an example of a V-REP plugin using this framework.

