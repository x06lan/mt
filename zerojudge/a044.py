import sys
# 包含最外面的那一個無限向外延展的區域。
def n(cn):
	
	counter=1
	for i in range(1,cn+1):
		# print(i)
		counter+=1+i*(i-1)/2
	return int(counter)
for i in sys.stdin:
	print(n(int(i)))
