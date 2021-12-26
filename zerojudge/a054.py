dic = { "A": 10, 
"B": 11,"C": 12,"D": 13,
"E": 14,"F": 15,"G": 16,
"H": 17,"I": 34,"J": 18, 
"K": 19,"L": 20,"M": 21,
"N": 22, "O": 35, "P": 23,
"Q": 24, "R": 25,"S": 26,"T": 27,
"U": 28,"V": 29,"W": 32,"X": 30,
"Y": 31,"Z": 33,
}

x=input()
out=""
count=0
for i in range(1,9):
	# print(i,x[8-i],int(x[8-i])*i)
	count+=int(x[8-i])*i
for key in dic:
	value=str(dic[key])
	d1=int(value[1])*9
	d2=int(value[0])
	g=(count+d1+d2)%10+int(x[len(x)-1])
	g=g%10
	if g==0:
		# print(key,count,d1,d2)
		out=out+key
print(out)