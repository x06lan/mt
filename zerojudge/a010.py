import sys
x=int(input())
# x="pz"
out=""
while x>1:

	for i in range(2,x+1):
		if x%i==0:
			x=x//i
			out+="{},".format(i)
			break

# print(out)
tem=out.split(",")
count=0
del tem[-1]
out=""
for i in tem:
	if i!= count and i.isnumeric():

		if tem.count(i)==1:
			out+="{}".format(i) 
		else:
			out+="{}^{}".format(i,tem.count(i)) 
		if i!= tem[-1]:
			out+=" * "	
		count=i
print(out)

