save={}
x=[int(i) for i in input().split()]
for i in range(x[0]):
    tem=[int(i) for i in input().split()]
    a=tem[0]
    b=tem[1]
    
    try:
        save[a].append(b)
        
    except:
        save[a]=[]
        save[a].append(b)
    
    try:
        save[b].append(a)
        
    except:
        save[b]=[]
        save[b].append(a)
is_find=False
def mapfind(save,path,start,targe):
    #print(path,targe)
    out=False
    global is_find
    if not is_find :
        for i in save[path[0]]:
            if i==targe:
                is_find=True
                return True
            elif i==start or i in path:
                pass
            else :
                out=out or mapfind(save,[i]+path,start,targe)
        return out 
    else:
        return False
print("Yes!" if mapfind(save,[x[1]],x[1],x[2]) else "No!")

