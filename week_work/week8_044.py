point=[20*10**4,4*10**4,10**4,4*10**3,10**3,200]
full=[10**7,200*10**4]
codef=[]
code3=[]
codehead=[]
out=0
for i in range(2):
    codef.append(input())
codehead=[i for i in input().split(" ")]
code3=[i for i in input().split(" ")]
x=int(input())
def dealhead(targe,value,point):
    for i in range(len(targe)-3):
        if targe[i:len(targe)]==value[i:len(value)]:
            return point[i]
    return 0

for i in range(x):
    i=input()
    add_v=[]
    for j in codehead:
        add_v+=[dealhead(j,i,point)]
    for j in range(len(codef)):
        if i==codef[j]:
            add_v+=[full[j]]
    for j in code3:
        if i[5:len(i)]==j:
            add_v+=[200]
    # print(max(add_v))
    out+=max(add_v)
print(out)

