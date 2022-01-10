import copy
def col(data,targe,maxnumber):
    if targe[2]>maxnumber:
        return True
    for i in data:
        if len(i)==0:
            pass
        elif targe[0]>=i[0] and targe[0]>=i[1]:
            pass
        elif i[0]>=targe[0] and i[0] >=targe[1]:
            pass
        else:
            return True
    return False
def check(rooms,meets ):
    if len(meets)==0:
        total=0
        for i in rooms:
            for j in i:
                total+=j[1]-j[0]
        return [total]
    out=[]
    newmeet=copy.deepcopy(meets)
    meet=newmeet.pop(0)
    for i in range(len(rooms)):
        temrooms=copy.deepcopy(rooms)
        ck=not col(temrooms[i],meet,maxnumber_arr[i])
        if ck:
            temrooms[i]+=[meet]
            out+=check(temrooms,newmeet)
    out+=check(rooms,newmeet)
    return out

if __name__=="__main__":
    save=[]
    roomn,meets=input().split()
    meets=int(meets)
    roomn=int(roomn)
    maxnumber_arr=[]
    for i in range(roomn):
        maxnumber_arr.append(int(input().split()[1]))
    for i in range(meets):
        index,number,start,end=input().split()
        start=int(start)
        number=int(number)
        end=int(end)
        save.append([start,end,number])
    emty_room=[[]for i in range(roomn)]
    gm=check(emty_room,save)
    print(max(gm))