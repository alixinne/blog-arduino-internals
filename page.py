#!/usr/bin/env python

import sys
from pygments import highlight
from pygments.lexers.asm import CppObjdumpLexer as AssemblyLexer
from pygments.formatters import HtmlFormatter
from jinja2 import Template


def load_envs(name, formatter):
    with open(f"build/{name}.s") as f:
        with open(f"build/{name}-size.txt") as fsize:
            source = f.read()
            formatted = formatter(source)
            return {'name': name, 'source': source, 'formatted': formatted, 'size': fsize.read().rstrip()}


# Load .s files into context
html_formatter = HtmlFormatter()
def formatter(source): return highlight(source, AssemblyLexer(), html_formatter)


env_names = list(sys.argv[1:])
env_names.sort()

context = {'envs': list(map(lambda name: load_envs(name, formatter), env_names)),
           'style': html_formatter.get_style_defs('.highlight')}

# Format output
with open("page.html.j2") as tplf:
    template = Template(tplf.read())
    print(template.render(context))
