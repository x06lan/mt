save=[]
roomn,meets=input().split()
meets=int(meets)
roomn=int(roomn)
for i in range(meets):
    index,start,end=input().split()
    start=int(start)
    end=int(end)
    #save[index]=[start,end]
    save.append([start,end])
    # save[index]
print(save)
#room=[[False for j in range(12)]for i in range(roomn)]
def col(data,targe):
    # print(data)~
    # print(targe)    
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
tem=[ [1, 4], [4, 10], [3, 9]]
print(col(tem,[4,11]))
def check(save_meet,meets):
    out=[]
    if len(meets)==0:
        total=0
        for i in save_meet:
            for j in i:
                total+=j[1]-j[0]
        return [total]
    tem2=meets.pop(0)
    for i in range(len(save_meet)):
        tem=save_meet.copy()
        ck=col(tem[i],tem2)
        if not ck:
            tem[i].append(tem2)
            out+=check(tem,meets)
    out+=check(save_meet,meets)
    return out
emty_room=[[]for i in range(roomn)]
print(check(emty_room,save))