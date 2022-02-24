import math
pork =["A","2","3","4","5","6","7","8","9","10","j","q","k"]
point =[1,2,3,4,5,6,7,8,9,10,0.5,0.5,0.5]

def to_point(x):
    position=pork.index(x)
    # position=pork.index(x)
    return point[position]

def getSum(x,y,z):
    p1=to_point(x)
    p2=to_point(y)
    p3=to_point(z)
    return p1+p2+p3
def compare(x,y):
    if x>10.5:
        x=0
    if y>10.5:
        y=0
    print(x)
    print(y)
    a=abs(x-10.5)
    b=abs(y-10.5)
    
    if a >b:
        print("B Win")
    elif a<b:
        print("B Win")
    else :
        print("Tie")

a=(input())
b=(input())
c=(input())

a1=(input())
b2=(input())
c3=(input())


sum1=getSum(a,b,c)
sum2=getSum(a1,b2,c3)
compare(sum1,sum2)
    