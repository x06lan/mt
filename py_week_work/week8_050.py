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
        total=sum([ j[1]-j[0] for i in rooms for j in i])
        return [total]
    out=[]
    newmeet=copy.deepcopy(meets)
    meet=newmeet.pop(0)
    for i in range(len(rooms)):
        new_rooms=copy.deepcopy(rooms)
        ck=not col(new_rooms[i],meet,maxnumber_arr[i])
        if ck:
            new_rooms[i]+=[meet]
            out+=check(new_rooms,newmeet)
    out+=check(rooms,newmeet)
    return out

if __name__=="__main__":
    save_meets=[]
    maxnumber_arr=[]
    roomn,meetn=map(int,input().split())
    for i in range(roomn):
        maxnumber_arr.append(int(input().split()[1]))
    for i in range(meetn):
        index,number,start,end=map(int,input().split())
        save_meets.append([start,end,number])
    emty_room=[[]for i in range(roomn)]
    gm=check(emty_room,save_meets)
    print(max(gm))