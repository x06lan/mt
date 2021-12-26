# input_type=int(input())
run=int(input())
def num(q):
    w=""
    for x in range(q,0,-1):
        w+=str(x)
    return w
for x in range(run,0,-1):
    print("#"*run,end="")
    print(num(x))
    run+=1
