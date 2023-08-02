#include <Python.h>

int _fib(int n)
{
    printf("Debug: calling _fib(%d)\n", n);
    if (n <= 1)
        return n;
    else
        return _fib(n-1) + _fib(n-2);
}

/* Wrapped _fib function */
static PyObject* fib(PyObject* self, PyObject* args)
{
    int n;

    /* Parse the input, from Python integer to C int */
    if (!PyArg_ParseTuple(args, "i", &n))
        return NULL;
    /* If the above function returns -1, an appropriate Python exception will
     * have been set, and the function simply returns NULL
     */

    /* Construct the result: a Python integer object */
    return Py_BuildValue("i", _fib(n));
}

/* Define functions in module */
static PyMethodDef FibMethods[] = {
    {"fib", fib, METH_VARARGS, "Calculate the Fibonacci numbers (in C)."},
    {NULL, NULL, 0, NULL}  /* Sentinel */
};

/* Create PyModuleDef structure */
static struct PyModuleDef fibStruct = {
    PyModuleDef_HEAD_INIT,
    "fib",
    "",
    -1,
    FibMethods,
    NULL,
    NULL,
    NULL,
    NULL
};

/* Module initialization */
PyObject *PyInit_fib(void)
{
    return PyModule_Create(&fibStruct);
}
