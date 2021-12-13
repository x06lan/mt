import sys
out=[]
for x in sys.stdin:
	x=int(x)
	if x%4==0 :
		if x%100!=0 or x%400==0:
			out.append("閏年")
		else:
			out.append("平年")
	else:
		out.append("平年")

	if x=="":
		break
for i in out:
	print(i)
