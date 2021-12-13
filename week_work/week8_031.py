def bin2num(indata):
    res=0
    for i in range(len(indata)-1,-1,-1):
        res+=(2**i)*int(indata[len(indata)-i-1])
    return res
def num2bin(indata):
    x=bin(indata)
    return str(x)[2::]
def c(indata,count):
    count+=1 
    # print(indata)
    if indata%2==1:
        indata+=1
    indata=indata//2
    if indata<=1:
        if count==1:
            return 0
        return count
    else:
        return c(indata,count)

def main():
    x=input()
    out=[]
    while x!="-1":
        x=bin2num(x)
        # print(x)
        out.append(c(x,0))
        x=input()
    for i in out:
        # print(i)
        x=num2bin(i)
        x="0"*(4-len(x))+x
        print(x)
        
main()