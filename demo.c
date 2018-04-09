/* Example of embedding Python in another program */

#include "Python.h"

/* A static module */

/* 'self' is not used */
static PyObject* xyzzy_foo(PyObject *self, PyObject* args)
{
    return Py_BuildValue("s", "42");
}

static PyMethodDef xyzzy_methods[] = {
    {"foo",             xyzzy_foo,      METH_NOARGS,    "Return the meaning of everything."},
    {NULL,              NULL,           0,              NULL}           /* sentinel */
};

static PyModuleDef xyzzy_definition = {
    PyModuleDef_HEAD_INIT,
    "xyzzy",
    "A Python module that prints 'hello world' from C code.",
    -1,
    xyzzy_methods
};

PyObject* PyInit_xyzzy(void) {
    Py_Initialize();
    return PyModule_Create(&xyzzy_definition);
}
