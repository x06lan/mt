# inlist=[int(x) for x in input().split()] 

n=int(input())
inlist=[]
for x in range(n):
    i=int(input())
    inlist.append(i)
    inlist.sort()
print(inlist[-2])
print(inlist[0]*inlist[len(inlist)-1])
