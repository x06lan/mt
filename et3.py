def dfs(pipe,path,mid,end):
    value=pipe[path[0]]
    out=[]
    for i in value:
        if i not in path:
            if mid in path and i==end:
                out.append([i]+path)
            out+=dfs(pipe,[i]+path,mid,end)
    return out

if __name__=="__main__":
    p_n,start,mid,end=map(int,input().split())
    pipe={}
    for i in range(p_n):
        a,b=map(int,input().split())
        if a not in pipe:pipe[a]=[]
        if b not in pipe:pipe[b]=[]
        if a not in pipe[b] :pipe[b].append(a)
        if b not in pipe[a] :pipe[a].append(b)
    out=dfs(pipe,[start],mid,end)
    ans=out[0]
    for i in out:
        if len(ans)>len(i):
            i.reverse()
            ans=i
    print("-".join(map(str,ans)))

