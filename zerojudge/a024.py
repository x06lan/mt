def main():
	# 必須使用輾轉相除法
	x=[int(i) for i in input().split()]
	max_math=1
	a=x[0]
	b=x[1]
	big=0
	while b!=0 and a!=0:
		# print(a,b,big)
		big=a%b
		a=b
		b=big
		
	return a
if __name__:
	print(main())