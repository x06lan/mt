save={"0":0,"1":1,"2":1}
def findmap(data,targe):
    for i in data:
        if i==str(targe):
            return data[i]
    return None
def F(data,n):
    # print(n)
    if findmap(data,n)==None:
        data[str(n)]=F(data,n-1)+F(data,n-2)
    return data[str(n)]
i=int(input())
out=[]
while i!=-1:
    out.append(str(F(save,i)))
    i=int(input())
for i in out:
    print(i)
