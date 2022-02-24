def listword(instr):
    tem=list(instr)
    tem.reverse()
    return instr=="".join(tem)
def recode(instr,save):
    if len(instr)==0:
        return save
    for i in range(1,len(instr)+1):
        if listword(instr[0:i]) and instr[0:i] not in save:
            save.append(instr[0:i])
    return recode(instr[1:len(instr)],save)
x=input()
y=recode(x,[])
y=sorted(y)
print("#".join(y))
# print("a#abba#b#bab#bb#c#cc ")
