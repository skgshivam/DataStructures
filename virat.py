n = eval(input())
r = eval(input())
def factorial(n):
    if n == 1 :
        return 1
    else :
        return n * factorial(n-1)
print(int(factorial(n)/(factorial(r)*factorial(n-r))))