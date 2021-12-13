def bsort(data):
    for i in range(len(data)-1):
        for j in range(len(data)-i-1):
            # print(i,i+j+1)

            tem=data[i+j+1]
            if data[i]>data[i+j+1]:
                tem=data[i+j+1]
                data[i+j+1]=data[i]
                data[i]=tem
            # else:
                # break
    return data
print(bsort([5,1,5,7,2,8,-4]))
