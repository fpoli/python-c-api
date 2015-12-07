#include <Python.h>

static PyObject* greet(PyObject* self, PyObject* args)
{
    const char* name;

    /* Parse the input, from Python string to C string */
    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;
    /* If the above function returns -1, an appropriate Python exception will
     * have been set, and the function simply returns NULL
     */

    printf("Hello %s\n", name);

    /* Returns a None Python object */
    Py_RETURN_NONE;
}

/* Define functions in module */
static PyMethodDef HelloMethods[] = {
    {"greet", greet, METH_VARARGS, "Greet somebody (in C)."},
    {NULL, NULL, 0, NULL}  /* Sentinel */
};

/* Module initialization */
PyMODINIT_FUNC
inithello(void)
{
    (void) Py_InitModule("hello", HelloMethods);
}
