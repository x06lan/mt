first=""
save={}
data=[[1,0],[0,1]]
for i in data:
    a=i[0]
    b=i[1]
    if a==first or first=="":
        first=b
    try:
        tem=save[b]
    except:
        save[b]=[]
    save[b].append(a)
 

def allpath(text,data,num):

    if num==len(text):
        # print("@",text)
        return [text]
    out=[]
    try:
        tem=save[text[0]]
    except:
        tem=[]
            # print(teㄅㄅ
    count=0
    for i in tem:
        out=out+allpath([i]+text,data,num)
        out=out+allpath(tem[count:len(tem)]+text,data,num)
        count+=1
    # print(out)
    return out
# print(first,save)
out=allpath([first],save,2)
print(list(out))
