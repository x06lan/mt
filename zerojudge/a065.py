import sys
def main():
    for x in sys.stdin:
        res=""
        # print(x)
        for i in range(len(x)-2):
            # print(x[i])
            d1=ord(x[i])
            d2=ord(x[i+1])
            res+=str(abs(d1-d2))
        print(res)
main()
# for i in range(x):
    # d=main()
#     out.append("Case {}: {}".format(i+1,d))
# for i in out:
#     print(i)