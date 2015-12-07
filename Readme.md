Python/C API quick start
=========================

A quick example of Python 2.7 modules implemented in C using the Python/C API.

```
make all
python -c "import hello; hello.say_hello('World')"
python -c "import fib; print fib.fib(5)"
make clean
```

Note that the best way to distribute a Python module is to use a `setup.py`
file. The Makefile is here only to debunk Python's magic.


## Steps

1. Write a `foobarmodule.c` C file.
   Note the `#include <Python.h>` at the beginning of example files.
2. Compile `foobarmodule.c` and produce a `foobar.so` file.
   See the Makefile for details.
3. Put `foobar.so` in a folder listed in the Python path.
4. Load the module from Python with `import foobar`.
