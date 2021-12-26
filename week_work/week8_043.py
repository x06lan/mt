
x=int(input())
save={}
point={}
for i in range(x):
    tem=[j for j in input().split()]
    save[tem[0]]=[]
    save[tem[0]]=tem[1:len(tem)]
    point[tem[0]]=0
x=[i for i in input().split("+")]
def deal(data,intype):
    tem=[i for i in intype.split(" ")]
    out=True
    for i in tem:
        if i!="":
            tem2=i
            if tem2[0]=="!":
                tem2=tem2[1:len(tem2)]
            have=tem2 in data
            if "!" in i:
                out=out and not have  
            else :
                out=out and have
    return 1 if out else 0 
for i in save:
    for j in x:
        point[i]+=deal(save[i],j)
count=0
# print(point.items())
point=dict(sorted(point.items(), key=lambda item: item[1],reverse=True))
# print(point)
for i in point:
    count+=1
    if count==len(point):
        print(i+","+str(point[i]),end="")
    else:
        print(i+","+str(point[i])+" ",end="")
