import math

a=int(input())
b=int(input())
c=int(input())


def price_a(count,price):
    out=0
    if count>20:
        out=count*price*0.8
    elif count>15:
        out=count*price*0.9
    elif count>10:
        out=count*price*0.95
    else:
        out=count*price
    return out
def price_b(count,price):
    out=0
    if count>20:
        out=count*price*0.75
    elif count>15:
        out=count*price*0.85
    elif count>10:
        out=count*price*0.9
    else:
        out=count*price
    return out
def price_c(count,price):
    out=0
    if count>20:
        out=count*price*0.8
    elif count>15:
        out=count*price*0.8
    elif count>10:
        out=count*price*0.85
    else:
        out=count*price
    return out
out1=price_a(a,30)
out2=price_b(b,70)
out3=price_c(c,40)
out4=out3+out2+out1
if a+b+c>=30:
    out4=out4*0.87

print("%.0f"%out4)