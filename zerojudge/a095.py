import sys
def main():
    for x in sys.stdin:
        res=""
        d=[int(i) for i in x.split()]
        n=d[0]
        m=d[1]
        # w=n-m
        if n!=m:
            print(m+1)
        else :
            print(m)

        # n=min(w,m)
        # for i in range()
        # print(n+1)
main()
# for i in range(x):
    # d=main()
#     out.append("Case {}: {}".format(i+1,d))
# for i in out:
#     print(i)