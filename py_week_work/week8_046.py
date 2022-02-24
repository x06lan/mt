import copy
save=[]
roomn,meets=input().split()
meets=int(meets)
roomn=int(roomn)
for i in range(meets):
    index,start,end=input().split()
    start=int(start)
    end=int(end)
    save.append([start,end])
def col(data,targe):
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
        ck=not col(temrooms[i],meet)
        if ck:
            temrooms[i]+=[meet]
            out+=check(temrooms,newmeet)
    out+=check(rooms,newmeet)
    return out

emty_room=[[]for i in range(roomn)]
gm=check(emty_room,save)
# print(gm)
print(max(gm))
