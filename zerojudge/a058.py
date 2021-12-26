
out=[0,0,0]
x=int(input())
for i in range(x):
	d=int(input())
	g=d%3
	out[g]+=1
print(" ".join([str(i)for i in out]))
