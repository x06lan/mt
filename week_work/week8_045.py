save={}
d=[i for i in input().split()]
times=d[0]
start=d[1]
mid=d[2]
targe=d[3]
for i in range(int(times)):
    a,b=input().split()
    if a not in save:save[a]=[]
    if b not in save:save[b]=[]
    save[a].append(b)
    save[b].append(a)

import time
# print(start,mid,targe)
kill=False
# print(save)
def dfs(save,path,start,mid,targe):
    ch=save[path[0]]
    out=[]
    tem=[]
    for i in ch:
        if i not in path:
            # print(i)
            if i==targe and mid in path :
                global kill
                kill=True
                return [[i]+path]
            else:
                tem.append(i)
    if kill:
        return out
    for i in tem:
        if i not in path:
                out += dfs(save,[i]+path,start,mid,targe)
    return out 
out=dfs(save,[start],start,mid,targe)
# print(out)
if len(out)==0:
    print("No way!")
else:
    sm=out[0]
    for i in out:
        if len(i)<len(sm):
            sm=i
    # print(sm)
    sm.reverse()
    print(len(sm)-1)
    print("-".join([str(i)for i in sm ]))