def find_sum(targe,data):
    con=[]
    count=0

    for i in data:
        # print("+",end="")
        count+=1
        if targe==i:
            con.append([i]) 
        else:
            child=find_sum(targe-i,data[count::])
            if len(child)!=0:
                for j in child:
                    j.append(i) 
                    con.append(j)
    return con       
print(find_sum(7,[7,1,5,7,2,8,-4]))