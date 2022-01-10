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
def print_table(data):
    print("\n".join([" ".join([str(j) for j in i]) for i in data]))
def deal_input(value):
    i=value//3
    j=value%3
    return i,j
data=[[0]*3 for i in range(3)]
who_frist=int(input())-1
step=[int(i)-1 for i in input().split()]
human=1
bot=2
side_change=[[human,bot],[bot,human]]
out=[]
have_error=False

for i in range(len(step)):
    value=step[i]
    tem=i%2
    #print(i,value)
    i1,j1=deal_input(value)
    if  data[i1][j1]!=0:
        print("Error")
        have_error=True
    else:
        data[i1][j1]=side_change[who_frist][tem]
        if 3 in find_line(data,side_change[who_frist][tem]):
            if side_change[who_frist][tem]==2:
                if not have_error:print("OK")
                print_table(data)
                print("Computer win")
                break
            else:
                if not have_error:print("OK")
                print_table(data)
                print("Player win")
                break
    if i==len(step)-1:
        if 0 not in  data[0]and 0 not in  data[1] and 0 not in data[2]:
            print_table(data)
            print("Tie")

        else:
            print_table(data)
            print("Undecided")

