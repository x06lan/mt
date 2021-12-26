import math
x=int(input())
def main():
    a=int(input())
    b=int(input())
    tem=a**0.5
    tem=math.floor(tem)
    if tem**2<a**2:
        # a=a**0.5
        a=tem+1
    else:
        a=tem
    b=b**0.5
    b=math.floor(b)
    counter=0
    # print(a,b)
    for i in range(a,b+1):
        counter+=i**2
    return counter
out=[]
for i in range(x):
    d=main()
    out.append("Case {}: {}".format(i+1,d))
for i in out:
    print(i)