def listword(instr):
    tem=list(instr)
    tem.reverse()
    return instr=="".join(tem)
def recode(instr,save):
    #print(instr)
    if len(instr)==0:
        return save
    for i in range(1,len(instr)+1):
        if listword(instr[0:i]) and instr[0:i] not in save:
            #print(0,instr[0:i])
            save.append(instr[0:i])
    return recode(instr[1:len(instr)],save)
x=input()
y=recode(x,[])
print(y)
y=sorted(y,key=lambda x: ord(x[0]))
print("#".join(y))
