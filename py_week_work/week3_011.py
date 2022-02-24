import math
data={}
for y in range(3):
    code=input()
    time=int(input())
    data[code]=[]
    for x in range(time):
        class_time=input()
        try:
            data[class_time]==None
        except:
            data[class_time]=[]
        data[class_time].append(code)
        
for x in data:
    if len(data[x])==2:
        
        print("{} and {} conflict on {}".format(data[x][0],data[x][1],x))