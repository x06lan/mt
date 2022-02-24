save={}
times,start,mid,targe=input().split()
for i in range(int(times)):
    a,b=input().split()
    if a not in save:save[a]=[]
    if b not in save:save[b]=[]
    if b not in save[a]:save[a].append(b)
    if a not in save[b]:save[b].append(a)
seen=[]

def dfs(save,path,targe):
    st=path[0]
    out=[]
    global seen
    for i in save[st]:
        if i not in seen:
            seen.append(i)
            newpath=[i]+path
            if i==targe:
                return newpath
            else:
                out+=dfs(save,newpath,targe)
    return out
tem=dfs(save,[start],targe)