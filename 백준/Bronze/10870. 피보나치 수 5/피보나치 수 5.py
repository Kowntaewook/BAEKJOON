n2 = int(input())

def fib1(n1):
    a , b = 0 , 1
    for i in range(n1):
        a,b = b,a + b
    return a
print(fib1(n2))