import sys
def tobin(number):
	out=""
	while number>0:
		out=str(number%2)+out
		number=number//2
	return out
for s in sys.stdin:
	print(tobin(int(s)))
