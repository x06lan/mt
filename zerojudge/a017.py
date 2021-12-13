# import sys
# def math(arg):
# 	d="".join(arg)
# 	c=0
# 	c=eval(d)
# 	c=str(int(c))
# 	return [c]
# def eqtion(arg):
# 	front=0
# 	back=0
# 	for i in range(len(arg)):
# 		j=arg[i]
# 		if j=="(":
# 			front=i
# 		if j==")":
# 			back=i

# 	if front==back and front==0:
# 		return math(arg)
# 	else:
# 		inside=arg[front+1:back]
# 		rearg=arg[:front]
# 		rearg+=eqtion(inside)
# 		rearg+=(arg[back+1:]) 
# 		# print(rearg)
# 		return eqtion(rearg)

# out=[]
# count=0
# try:
# 	while True:
# 		x=input().split()
# 		out.append(eqtion(x)[0])

# 	pass
# except :
# 	for i in out:
# 		print(i)
# 	pass

# 整除是重點

import sys
for s in sys.stdin:

      print(eval(s.replace("/", "//")))