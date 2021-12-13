def main():
	x=input()
	if len(x)%2==1:
		b=(len(x)-1)//2
	else:
		b=len(x)//2


	for i in range(b):
		if  x[i]!=x[len(x)-i-1]:
			return "no"
	return "yes"
if __name__:
	print(main())