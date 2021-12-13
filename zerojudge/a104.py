import sys
def main():
    x=int(input())
    arr=[int(i) for i in input().split()]
    for i in range(x-1):
        # a1=arr[i]
        for j in range(i+1,x):
            if arr[i]>arr[j]:
                tem=arr[i]
                arr[i]=arr[j]
                arr[j]=tem
    print(" ".join([str(i) for i in arr]))
try:
    while True :
        main()
except:
    pass
# for i in range(x):
    # d=main()
#     out.append("Case {}: {}".format(i+1,d))
# for i in out:
#     print(i)