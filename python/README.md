### Python extension for `xyzzy.h`


This is an example of a C extension for the lib/zyzzy.h custom C11 library.


1 - Set the xyzzy.h on the C11 include path

    
    $ export C_INCLUDE_PATH=${C_INCLUDE_PATH}:../lib/


2 - Install the python module

    
    $ python setup.py build
    $ python setup.py install


3 - You can use it 

    
    $ python main.py
