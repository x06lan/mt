def col(rooms,meet):
    for i in rooms:
        if meet[0]>=i[1]and meet[1]>i[1]:
            pass
        elif i[0] >=meet[1]and i[1]>meet[1]:
            pass
        else:
            return True
    return False
import copy
def check(rooms,meets):
    if len(meets)==0:
        return  [sum([j[1]-j[0]for i in rooms for j in i])]
    new_meets=copy.deepcopy(meets)
    meet=new_meets.pop(0)
    out=[]
    for i in range(len(rooms)):
        room=rooms[i]
        if not col(room,meet):
            new_rooms=copy.deepcopy(rooms)
            new_rooms[i].append(meet)
            out+=check(new_rooms,new_meets)
    out+=check(rooms,new_meets)
    return out
if __name__=="__main__":
    room_n,meet_n=map(int,input().split())
    meets=[]
    for i in range(meet_n):
        index,start,end=map(int,input().split())
        meets.append([start,end])
    empty_room=[[] for i in range(room_n)]
    ans=check(empty_room,meets)
    print(max(ans))
