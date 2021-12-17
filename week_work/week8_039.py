def recode(text,data,number,save):
    out=[]
    if len(text)==number:
        return [text]
    for i in range(len(data)):
        out+=recode(text+data[i],data[i+1:len(data)],number,save)
    return out 
x=input().split()
y=recode("",x[0],int(x[1]),[])
y=sorted(y)
print(" ".join(y))
