# def max_sort(indata):

    
def main():
    dd=list(map(int,input().split()))
    x1=[]
    x2=[]
    for i in dd:
        if i%2:
            x1.append(i)
        else:
            x2.append(i)
    x3=sorted(x1)+sorted(x2,reverse=True)
    print(x3)
main()