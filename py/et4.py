import copy
def find_line(data,side):
    out=[]
    for i in data:
        out.append(i.count(side))
    for i in range(len(data)):
        out.append([data[0][i],data[1][i],data[2][i]].count(side))
    tem=[data[0][0],data[1][1],data[2][2]]
    out.append(tem.count(side))
    tem=[data[0][2],data[1][1],data[2][0]]
    out.append(tem.count(side))
    return out
def find_poss(data,side):
    last_poss=[]
    for i in range(len(data)):
        for j in range(len(data)):
            if data[i][j]!=0:
                new_table=copy.deepcopy(data)
                new_table[i][j]=side
                if 3 in find_line(data,side):
                    return True,[i,j]
                else:
                    last_poss=[i,j]
    return False,last_poss

table=lambda data: "\n".join([" ".join(map(str,i))for i in data ])
if __name__=="__main__":
    data=[[0]*3 for i in range(3)]
    who_f=int(input())
    step=list(map(int,input().split()))
    choo_side=[[1,2],[2,1]]
    choo_side=choo_side[who_f-1]
    counter=0
    for i in range(len(step)):
        side=choo_side[counter%2]
        number=step[i]-1
        loca=[number//3,number%3]
        if data[loca[0]][loca[1]]!=0:
            counter-=1
            print("error")
        else:
            data[loca[0]][loca[1]]=side
        if 3 in find_line(data,side):
            if side==1:
                print(table(data))
                print("p win")
            else:
                print(table(data))
                print("c win")
        else:
            if i==len(step)-1:
                print(table(data))
                win,step_1=find_poss(data,side)
                lost,step_2=find_poss(data,(side+1)%2)
                if win:
                    print(3*step_1[0]+step_1[2]+1)
                elif lost:
                    print(3*step_2[0]+step_2[2]+1)
                else:
                    print(3*step_1[0]+step_1[2]+1)
        counter+=1

