def find_line(data,side):
    out=[]
    path=[]
    for i in range(len(data)):
        tem=data[i]
        out.append(tem.count(side))
    for i in range(len(data)):
        tem=[data[0][i],data[1][i],data[2][i]]
        out.append(tem.count(side))
    tem=[data[0][0],data[1][1],data[2][2]]
    out.append(tem.count(side))
    tem=[data[0][2],data[1][1],data[2][0]]
    out.append(tem.count(side))
    return out
def find_s(data,side,emeny):
    init=[]
    for i in range(len(data)):
        for j in range(len(data[i])):
            if data[i][j]!= emeny and data[i][j]!= side:
                newdata=copy.deepcopy(data)
                newdata[i][j]=side
                if 3 in  find_line(newdata,side):
                    return [True,i,j]
                elif j!=2 or i!=2:
                    init=[False,i,j]
    return init
import copy
data=[[0]*3 for i in range(3)]
#data.append([int(i)for i in input().split()])
#data.append([int(i)for i in input().split()])
#data.append([int(i)for i in input().split()])
ix=input()
bot=2
human=1
while ix!="":
    i=int(ix[0])
    j=int(ix[1])
    data[i][j]=human
    if 3 in  find_line(data,human):
        print("you win")
        break
    tem1=find_s(data,bot,human)
    tem2=find_s(data,human,bot)
    if len(tem1)==0:
        print("tie")
        break
    if data[1][1]==0:
        data[1][1]=bot
    elif tem1[0]:
        data[tem1[1]][tem1[2]]=bot
    elif tem2[0]:
        data[tem2[1]][tem2[2]]=bot
    else:
        data[tem1[1]][tem1[2]]=bot
    if 3 in find_line(data,bot):
        print("you lose")
        break
    print(data[0])
    print(data[1])
    print(data[2])
    ix=input()
