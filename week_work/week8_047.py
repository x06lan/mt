def edf(command,content):
    c=command.split()
    ct=c[0]
    
    if "ADD_W_AFTER" in ct:
        i=int(c[1])
        n=int(c[2])
        w=c[4]
        content[i].insert(n+1,w)
        pass
    elif"ADD_W_FRONT"in ct:
        i=int(c[1])
        n=int(c[2])
        w=c[4]
        content[i].insert(n,w)
        pass
    elif "ADD_S_AFTER"in ct:
        i=int(c[1])
        w=c[2]
        content.insert(i+1,w)
        pass
    elif "ADD_S_FRONT" in ct:
        i=int(c[1])
        w=c[2]
        content.insert(i,w)
        pass
    elif "INSERT_AFTER" in ct:
        key=c[1]
        w=c[2]
        save=[]
        for i in range(len(content)):
            for j in i:
                if content[i][j]==key:
                    content[i].insert(j+1,w)
    elif "INSERT_FRONT" in ct:
        key=c[1]
        w=c[2]
        save=[]
        for i in range(len(content)):
            for j in i:
                if content[i][j]==key:
                    content[i].insert(j,w)
    
    return content


x,y=input().split()
x=int(x)
y=int(y)
text=[]
for i in range(x):
    text.append(input.split())
for i in range(y):
    text=edf(input(),text)
print()
