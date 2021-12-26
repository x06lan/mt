import sys
# 包含最外面的那一個無限向外延展的區域。
def n(cn):
	
	counter=0
	for i in range(1,cn+1):
		# print(i)
		tem=0
		if i<=10:
			tem=6
		elif i<=20:
			tem=2
		elif i<=40:
			tem=1
		else :
			counter=100	
			break
		counter+=tem
	
	return int(counter)
for i in sys.stdin:
	print(n(int(i)))
