def quick(data):
    bigger=[] 
    smell=[]
    if len(data)<=1:
        return data
    targe=data.pop(0)
    for i in data:
        if i>targe:
            bigger.append(i)
        else:
            smell.append(i)
    return quick(smell) +[targe] +quick(bigger)
    # if len(smell) ==0:
    #     return [targe] +quick(bigger)
    # elif len(bigger)==0:
    #     return quick(smell) +[targe] 
    # else:
    #     return quick(smell) +[targe] +quick(bigger)
print(quick([5,1,5,7,2,8,-4]))