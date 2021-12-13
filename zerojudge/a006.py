import sys
x= [ int(i) for i in input().split()]
a=x[0]
b=x[1]
c=x[2]
if b**2-4*a*c>=0:
	d=b**2-4*a*c
	if d==0:
		print("Two same roots x={}".format(int(-b/(2*a))))
	else:
		d=d**0.5
		x1=-b+d
		x1=int(x1/(2*a))
		x2=-b-d
		x2=int(x2/(2*a))
		print("Two different roots x1={} , x2={}".format(x1,x2))

else:
	print("No real root")