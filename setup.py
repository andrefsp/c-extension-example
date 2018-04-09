from distutils.core import setup, Extension

module1 = Extension('xyzzy', sources=['_python_ext.c'])

setup(
    name='Python_xyzzy',
    version='1.0',
    description='This is a demo package',
    ext_modules=[module1],
)
