import sys
# 包含最外面的那一個無限向外延展的區域。
def n(cn):

	counter=0
	for i in range(1,cn-1):
		# print(i)
		counter+=i*2
	return cn*2+counter
for i in sys.stdin:
	print(n(int(i)))

