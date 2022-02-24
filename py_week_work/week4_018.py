input_type=int(input())
run=int(input())
def numlist(run):
    out=""
    for x in range(1,run+1):
        out+=str(x)
    for x in range(run-1,0,-1):
        out+=str(x)
    return out
def type_1(run):
    for x in range(1,run+1):
        print(numlist(x))
def type_2(run):
    for x in range(1,run+1):
        out=""
        out+="_"*(run-x)
        out+=numlist(x)
        out+="_"*(run-x)
        print(out)
def type_3(run):
    for x in range(run,0,-1):
        out=""
        out+="_"*(run-x)
        out+=numlist(x)
        out+="_"*(run-x)
        print(out)
if input_type==1:
    type_1(run)
elif input_type==2:
    type_2(run)
else :
    type_3(run)