
k=0
count=[]
while True:
    try:
        q=int(input())
        get_input=[int(i) for i in input().split(" ")]
        
        save=get_input
        count.append(0)
        for j in range(len(save)-1):
            for i in range(0,len(save)-j-1):
                x =save[i]
                y =save[i+1]
                
                if x>y:
                    count[k]+=1
                    tem=x
                    save[i]= y
                    save[i+1]= x
        k+=1
        
    except:
        break

# print(count)
for number in count:
    print("Minimum exchange operations : {}".format(number))
