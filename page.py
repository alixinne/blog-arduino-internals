#!/usr/bin/env python

import sys
from pygments import highlight
from pygments.lexers.asm import CppObjdumpLexer as AssemblyLexer, CppLexer
from pygments.formatters import HtmlFormatter
from jinja2 import Template

known_envs_files = {'template': [
    'Templateduino.h', 'TemplateduinoAvr.h', 'TemplateduinoUno.h']}


def prefix_source(filename, name):
    with open(f"src/{name}/{filename}") as f:
        return f"// {filename}\n{f.read()}"


def make_cpp(name):
    files = []

    # Add known files for the target environment
    if name in known_envs_files:
        files.extend(known_envs_files[name])

    # Add entry point
    files.append("main.cpp")

    return '\n'.join(map(lambda filename: prefix_source(filename, name), files))


def load_envs(name, s_formatter, cpp_formatter):
    with open(f"build/{name}.s") as f:
        with open(f"build/{name}-size.txt") as fsize:
            source = f.read()
            formatted = s_formatter(source)
            cpp_formatted = cpp_formatter(make_cpp(name))
            return {'name': name, 'source': source, 'formatted': formatted, 'size': fsize.read().rstrip(), 'cpp_formatted': cpp_formatted}


# Create Pygments formatters
html_formatter = HtmlFormatter()
def s_formatter(source): return highlight(
    source, AssemblyLexer(), html_formatter)


def cpp_formatter(source): return highlight(source, CppLexer(), html_formatter)


# Process input
env_names = list(sys.argv[1:])
env_names.sort()

context = {'envs': list(map(lambda name: load_envs(name, s_formatter, cpp_formatter), env_names)),
           'style': html_formatter.get_style_defs('.highlight')}

# Format output
with open("page.html.j2") as tplf:
    template = Template(tplf.read())
    print(template.render(context))
