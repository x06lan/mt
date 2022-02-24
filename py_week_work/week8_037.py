import sys
def merge(a,b):
    out=[]
    if (a[0]<=b[1] and b[0]<=a[0] ) or ( a[1]<=b[1] and b[0]<=a[1])  :
        if a[0]>b[0]:
            out.append(b[0])
        else:
            out.append(a[0])
        if a[1]>b[1]:
            out.append(a[1])
        else:
            out.append(b[1])
        return True ,out
    else:
        if (a[0]<b[0] and  a[1]>b[1]) or (b[0]<a[0] and  b[1]>a[1]):
            return True ,[max(a[0],b[0]),max(a[1],b[1])]
        return  False ,[a,b]

def all_combo(data):
    is_all_merge=True
    out=[]
    for i in range(len(data)):
        this_merge=True
        for j in range(1,len(data)-i):
            is_merge,ans=merge(data[i],data[i+j])
            if is_merge and  not ans in out :
                is_all_merge=False
                this_merge=False
                out.append(ans)
        if this_merge:
            in_out=True
            for j in out:
                is_merge,ans=merge(data[i],j)
                if is_merge :
                    in_out=False
            if in_out:
                out.append(data[i])
    if is_all_merge:
        return out
    else:
        return all_combo(out)
def rewrite(data):
    res=data.copy()
    any_m=True
    for i in range(1,len(data)) :
        is_merge,re_ans=merge(data[i-1],data[i])
        if is_merge:
            any_m=False
            res.append(re_ans)
            try:
                res.remove(data[i-1])
            except:
                pass
            res.remove(data[i])
    res=sorted(res,key=lambda x:x[0])

    if any_m:
        return res
    else:
        return  rewrite(res)
ilen=int(input())

save=[]
for i in range(ilen):
    x=[int(i)for i in input().split(',')]
    save.append(x)
save=sorted(save,key=lambda x:x[0])
# out=all_combo(save)
out =rewrite(save)
for i in out:
    print(",".join([str(j) for j in i]))