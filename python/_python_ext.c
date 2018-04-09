/* Example of embedding Python in another program */

#include "Python.h"
#include <string.h>

/* A static module */

static PyObject* xyzzy_str_len(PyObject *self, PyObject* args) {
    char *str;

    if (!PyArg_ParseTuple(args, "s", &str))
        return NULL;

    return Py_BuildValue("i", strlen(str));
}

/* 'self' is not used */
static PyObject* xyzzy_str(PyObject *self, PyObject* args)
{
    char *str;

    if (!PyArg_ParseTuple(args, "s", &str))
        return NULL;

    return Py_BuildValue("s", str);
}

static PyMethodDef xyzzy_methods[] = {
    {"str",             xyzzy_str,      METH_VARARGS,   "Returns whatever you pass."},
    {"str_len",         xyzzy_str_len,  METH_VARARGS,   "Returns string length."},
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
