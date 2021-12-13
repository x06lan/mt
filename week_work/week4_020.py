x =int(input())
is_prime=1

for i in range(2,x):
    # print(i)
    if x%i==0:
        is_prime=0
        break
if x==2:
    is_prime=1
if is_prime==1:
    print("{} is prime number".format(x))
else :
    print("{} is not prime number".format(x))
