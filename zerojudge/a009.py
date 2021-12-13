import sys
x=input()
# x="pz"
g=list(x.encode('ascii'))
# for i in range
# for i in range(25):
x= [ chr(j-7) for j in g]
print("".join(x))


