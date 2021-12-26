import math

a= input()
b= input() 
x= input() 
y= input() 


c=a+b
d=c.replace(x,y)
# print(c)
print (len(c)+len(d))
e=d[0:3:1]+d[-3::1]
print(e*3)
# print (a.replace(" "+b," "+c+" "+b))
# print (a.replace(" "+b,""))
