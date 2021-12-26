table={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
add=[['IV','IX','V','I'],['XL','XC','L','X'],['CD','CM','D','C'],['','','','M']]
# a [['4','9','5','1'],['40','90','50','10'],['400','900','500','C'],['','','','M']]

def ro2number(x):

	tem=0
	out=0
	for i in range(len(x)-1,-1,-1):
		n=x[i]
		m=x[i-1]
		if table[n]>=tem:
			out+=table[n]
			tem=table[n]
		else :
			out-=table[n]
	return out 
def deal_dige(dige,counter):
	status=0
	co=3
	out=""
	if dige==9:
		status=9
		co=1

	elif dige>=5:
		status=5
		co=2
	elif dige==4:
		status=4
		co=0
	if dige!=0 and status!=0:
		out=add[counter][co]+add[counter][3]*(dige-status)
	else:
		out=add[counter][3]*(dige-status)

	return out


def number2ro(x):
	text=str(x)
	count=len(text)
	out=""
	for i in range(len(text)):
		# print(count)
		count-=1
		dige=int(text[i])
		out+=deal_dige(dige,count)
	return out
# print(number2ro(15))
x=input()
out=[]
while x !="#":
	x=x.split()

	x1=ro2number(x[0])
	x2=ro2number(x[1])
	x3=abs(x1-x2)
	if x3==0:
		out.append("ZERO")
	else:
		out.append( number2ro(x3))
	x=input()
for i in out:
	print(i)
