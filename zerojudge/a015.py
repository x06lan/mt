import sys
out=[]
count=0
try:
	while True:
		x=[int(i) for i in input().split()]
		y=x[1]
		data=[]

		for i in range(x[0]):
			inarr=[int(j) for j in input().split()]
			data.append(inarr)
		for i in range(y):
			d=[]
			out.append("")
			for j in range(x[0]):
				if j==0:
					out[count]+="{}".format(data[j][i])
					# print("{}".format(data[j][i]),end="")
				else:
					out[count]+=" {}".format(data[j][i])
					# print(" {}".format(data[j][i]),end="")
				d.append(data[j][i])
			# print("")
			# out[count]+="\n"

			# out.append(d)
			count+=1
	pass
except :
	for i in out:
		print(i)
	pass


# print(out)