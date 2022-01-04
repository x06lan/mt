save={}
times,start,mid,targe=input().split()
for i in range(int(times)):
    a,b=input().split()
    if a not in save:save[a]=[]
    if b not in save:save[b]=[]
    if b not in save[a]:save[a].append(b)
    if a not in save[b]:save[b].append(a)
kill=False
def dfs(save,path,start,mid,targe):
    ch=save[path[0]]
    out=[]
    tem=[]
    for i in ch:
        if i not in path:
            if i==targe and mid in path :
                global kill
                kill=True
                return [[i]+path]
            else:
                tem.append(i)
    if kill:
        return out
    for i in tem:
        out += dfs(save,[i]+path,start,mid,targe)
    return out 
out=dfs(save,[start],start,mid,targe)
if len(out)==0:
    print("No way!")
else:
    sm=out[0]
    for i in out:
        if len(i)<len(sm):
            sm=i
    sm.reverse()
    print(len(sm)-1)
    print("-".join([str(i)for i in sm ]))