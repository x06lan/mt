import sys
g=input()
out=[]
for i in range(int(g)):
	line=input()
	x= [ int(i) for i in line.split()]
	if x[2]-x[1]==x[1]-x[0]:
		d=x[1]-x[0]
		out.append(line+" "+str(int(x[-1]+d)))
	elif x[2]/x[1]==x[1]/x[0]:
		d=x[1]/x[0]
		out.append(line+" "+str(int(x[-1]*d)))
for i in out:
	print(i)
