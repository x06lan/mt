def dealmath(value,command):
    ans=0
    if command=="*":ans= value[0]*value[1]
    elif command=="/":ans= value[0]/value[1]
    elif command=="+":ans= value[0]+value[1]
    elif command=="-":ans= value[0]-value[1]
    elif command=="%":
        ans= value[0]%value[1]
        if value[0]<0:
            ans= -(-value[0]%value[1])
    else:ans= 0
    return int(ans)
d=input().split()
total=0
tem=0
if d[1] in ["*","/","%"]:tem=int(d[0])
else:total=int(d[0])
for i in range(1,len(d),2):
    sign=d[i]
    value=int(d[i+1])
    nextsign="+"
    if i<len(d)-2:
       nextsign=d[i+2]
    # print(total,tem)
   #print(tem,sign,value,total,nextsign)
    if nextsign in ["*","/","%"]:
       tem=dealmath([tem,value],sign)
    else:
       total+=dealmath([tem,value],sign)
       tem=0
print(total)