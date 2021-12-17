def deal(data,number,save):
    
    if len(data)==0:
        return save
    tem=data[0]
    if tem.isalpha():
        if tem.islower():
            tem=tem.upper()
            save[0]+=tem
        elif tem.isupper():
            tem=tem.lower()
            save[0]+=tem
    if len(save[0])%number==0:
        save.insert(0,"")
    return deal(data[1:len(data)],number,save)
x=input().split()
y=deal(x[0],int(x[1]),[""])
print("/".join([i for i in y if i!="" ]))
