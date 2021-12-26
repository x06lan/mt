x=list(input())
y=list(input())
x.reverse()
y.reverse()
updi=False
a=max(x,y)
b=min(x,y)
out=[]
for i in range(len(a)):
	tem1=int(a[i])
	try:
		tem2=int(b[i])
		pass
	except :
		tem2=0
	tem=tem1+tem2
	tem= tem+1 if updi else tem
	out.insert(0,str(tem%10))
	updi= tem/10>=1
	if updi and len(a)-1==i:
		out.insert(0,str(1))
	# print(out)
print("".join(out))



