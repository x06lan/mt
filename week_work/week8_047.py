def edf(command,content):
    c=command
    ct=c[0]
    #print(ct)
    if "ADD_W_AFTER" in ct:
        i=int(c[1])-1
        n=int(c[2])-1
        w=c[3]
        content[i].insert(n+1,w)
        pass
    elif"ADD_W_FRONT"in ct:
        i=int(c[1])-1
        n=int(c[2])-1
        w=c[3]
        content[i].insert(n,w)
        pass
    elif "ADD_S_AFTER"in ct:
        i=int(c[1])-1
        del c[0]
        del c[0]
        for k in c:
            content[i].append(k)
        pass
    elif "ADD_S_FRONT" in ct:
        i=int(c[1])-1
        del c[0]
        del c[0]
        for k in c:
            content[i].insert(0,k)
        pass
    elif "INSERT_AFTER" in ct:
        key=c[1]
        w=c[2]
        save=[]
        for i in range(len(content)):
            for j in range(len(content[i])):
                if content[i][j]==key:
                    content[i].insert(j+1,w)
    elif "INSERT_FRONT" in ct:
        key=c[1]
        w=c[2]
        save=[]
        for i in range(len(content)):
            for j in range(len(content[i])-1,-1,-1):
                if content[i][j]==key:
                    content[i].insert(j,w)
    elif "DEL_W" in ct:
        i=int(c[1])-1
        j=int(c[2])-1
        del content[i][j]
    elif "DEL_L" in ct:
        i=int(c[1])-1
        del content[i]
    elif "REPLACE" in ct:
        key=c[1]
        w=c[2]
        save=[]
        for i in range(len(content)):
            for j in range(len(content[i])):
                if content[i][j]==key:
                    content[i][j]=w
    elif "COUNT" in ct:
        total=0
        for i in content:
            total+=len(i)
    return content


x,y=input().split()
x=int(x)
y=int(y)
text=[]
for i in range(x):
    text.append(input().split())
for i in range(y):
    command=input().split()
    # print(text)
    text=edf(command,text)
    if "COUNT" in command[0]:
        total=0
        for i in text:
            total+=len(i)
        print(total)
for i in text:
    print(" ".join(i))

