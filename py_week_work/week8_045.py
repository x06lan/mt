save={}
times,start,mid,targe=input().split()
for i in range(int(times)):
    a,b=input().split()
    if a not in save:save[a]=[]
    if b not in save:save[b]=[]
    if b not in save[a]:save[a].append(b)
    if a not in save[b]:save[b].append(a)
kill=False
seen=[]
# print(save)
def wfs(save,node,path,targe):
    while len(node)!=0:
        tem=node.pop(0)
        newpath=path.pop(0)+[tem]

        if tem==targe :
            return newpath
        for i in save[tem]:
            if i not in newpath:
                node.append(i)
                path.append(newpath)
    return []
out=wfs(save,[start],[[]],mid)
out1=wfs(save,[mid],[[]],targe)
# print(out)
# print(out1)
if len(out)==0 or len(out1)==0:
    print("No way!")
else:
    out1.pop(0)
    sm=out+out1
    # sm.reverse()
    print(len(sm)-1)
    print("-".join([str(i)for i in sm ]))