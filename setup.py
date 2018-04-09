from distutils.core import setup, Extension

module1 = Extension('xyzzy', sources=['demo.c'])

setup(
    name='Python_xyzzy',
    version='1.0',
    description='This is a demo package',
    ext_modules=[module1],
)
