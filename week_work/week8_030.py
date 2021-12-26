
def main():
    x1=input().split()
    x2=[int(i)for i in input().split()]
    x3={v:x1[i] for i,v in enumerate(x2)}
    # print(x3)
    for i in sorted(x2):
        print(x3[i],end="")
main()