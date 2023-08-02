# Declaration of variables
CC = gcc
CC_FLAGS = -shared -fPIC -I/usr/include/python3.10 \
	-Wall -Wextra -Wno-unused-parameter -O2 -g

# File names
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:module.c=.so)

# Main target
all: $(OBJECTS)

# Object files
%.so: %module.c
	$(CC) $(CC_FLAGS) $< -o $@

run: $(OBJECTS)
	python -c "import fib; print(fib.fib(5))"
	python -c "import hello; hello.greet('Foobar')"

# To remove generated files
clean:
	rm -f *.so

.PHONY: all run clean
