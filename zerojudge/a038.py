import sys
def revers(number):
	out=""
	for i in range(len(number)-1,-1,-1):
		out+=number[i]
	return int(out)
for s in sys.stdin:
	print(revers(s))
