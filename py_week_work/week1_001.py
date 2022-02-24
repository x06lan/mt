import math

a= input()
b= input() 

try:
    a=int(a)
    b=int(b)
    # print(a/b)
    print(a+b)
    print(a/b)
except ZeroDivisionError:
    print("divide by zero")
except:
    print("make sure input is integer")
finally:
    print("OK")

# 1978/08/23
# Sample Output
# kobe is born at year 1978 month 08 day 23 in Bryant family.