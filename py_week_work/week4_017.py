input_type=int(input())
run=int(input())
def type_1(run):
    for x in range(1,run+1):
        
        if x<(run+1)/2 :
            print("*"*(x))
        else:
            print("*"*int(((run+1))-x))
def type_2(run):
    for x in range(run):
        if x<=(run-1)/2:
            print("."*int((run-1)/2-x),end="")
            print("*"*(x+1))
        else :
            print("."*int(x-(run-1)/2),end="")
            print("*"*(run-x))
def type_3(run):
    for x in range(run):
        if x<=(run-1)/2:
            print("."*int((run-1)/2-x),end="")
            print("*"*(1+x*2))
        else :
            print("."*int(x-(run-1)/2),end="")
            print("*"*(run-x-1)*2+"*")

if input_type==1:
    type_1(run)
elif input_type==2:
    type_2(run)
else :
    type_3(run)