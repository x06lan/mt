# x=input().split()
# a=[int(i) for i in str(x[0])]
# b=[int(i) for i in str(x[2])]
# sign=x[1]

# lenght=max(len(a),len(b))
# c=[0 for i in range(lenght)]
# tem=0
# for i in range(lenght-1,-1,-1):
#     va=a[i]
#     vb=b[i]
#     if sign=="-" or sign=="+":
#         vc=eval("{}{}{}".format(va,sign,vb))
#         vc+=tem
#     c[i]=vc%10
#     tem=vc//10
# for i in c:
#     print(i,end="")



print(eval(input().replace('/','//')))
