
def fib(n):
    "Calculate the Fibonacci numbers (in Python)."
    if n <= 1:
        return n
    else:
        return fib(n-1) + fib(n-2)
