/* Example of embedding Python in another program */

#include "Python.h"

// Add custom library
#include <xyzzy.h>


/* A static module */

static PyObject* xyzzy_custom_str_len(PyObject *self, PyObject* args) {
    char *str;

    if (!PyArg_ParseTuple(args, "s", &str))
        return NULL;

    // Use method from custom library
    int custom_len = custom_str_len(str);

    return Py_BuildValue("i", custom_len);
}

/* 'self' is not used */
static PyObject* xyzzy_custom_str(PyObject *self, PyObject* args)
{
    char *str;

    if (!PyArg_ParseTuple(args, "s", &str))
        return NULL;

    // Use method from custom library
    char *new_str = custom_str(str);

    return Py_BuildValue("s", new_str);
}

static PyMethodDef xyzzy_methods[] = {
    {"custom_str",             xyzzy_custom_str,      METH_VARARGS,   "Returns whatever you pass."},
    {"custom_str_len",         xyzzy_custom_str_len,  METH_VARARGS,   "Returns string length."},
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
