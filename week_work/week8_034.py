save={"0":0,"1":1}
def findmap(data,targe):
    for i in data:
        if i==str(targe):
            return data[i]
    return None
def kn(data,n):

    if findmap(data,n)==None:
        data[str(n)]=2*kn(data,n-1)+3*kn(data,n-2)
    return data[str(n)]
i=input()
try:
    i=int(i)
    if i<2:
        raise ValueError
    print(kn(save,i))

except:
    print( "Error")