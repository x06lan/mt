x=[int(i ) for i in input().split()]
g=(x[0]*2+x[1])%3
out=""
if g==0:
	out="普通"
elif g==1:
	out="吉"
else:
	out="大吉"
print(out)