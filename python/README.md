This is an example of a C extension for the lib/zyzzy.h custom C11 library.


Set the xyzzy.h on the C11 include path

:::
    
    export C_INCLUDE_PATH=${C_INCLUDE_PATH}:../lib/


Install the python module

:::
    
    python setup.py build
    python setup.py install


You can use it 

:::
    
    python main.py
