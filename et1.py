def deal_req(req,data):
    req=[i.split() for i in req.split("+")]
    count={i:0 for i in data}
    for school_key in data:
        school=data[school_key]
        for i in req:
            fit_req=True
            for j in i:
                if j[0]=="!":
                    if j[1:]  in  school:
                        fit_req=False
                else:
                    if j not in school:
                        fit_req=False
            if fit_req:
                count[school_key]+=1
        if count[school_key]==0:
            del count[school_key]
    return  dict(sorted(count.items(),key=lambda k : k[1],reverse=True))

if __name__=="__main__":
    sc_n=int(input())
    data={}
    for i in range(sc_n):
        school_info=input().split()
        data[school_info[0]]=school_info[1:]
    req=input()
    ans=deal_req(req,data)
    print(" ".join([",".join([i,str(ans[i])])for i in ans]))

