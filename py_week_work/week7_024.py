# 數字字串從高位數往低位數看過去，每一位數字只會相等或變大，例如：9、234、777、11222233等數字都有這性質，稱階梯數字。給定一正整數 N>0，找出不大於N的階梯數字共有幾個。
# 輸出說明: 一個不大於N的階梯數字總個數。

# 範例輸入 #1
# 25
# 23456
# 54321
# 88888888
# 9999999999999999999999999999

# 範例輸出 #1
# 22
# 1365
# 1875
# 24301
# 124403619



# 124403610

# 執行少於二秒
# 1. N<10^5
# 2. N<10^18
# 3. N<10^100000

# -->"執行時間過長"會導致測試失敗<--
from typing import Counter


def q1(n):
    out=1
    for x in range(1,n+1):
        out*=x
    return out
# def cnm(n,m):
    
#     return int(q1(n)/q1(m)/q1(n-m))
def nstart_len(n,l):
    n=9-n
    m=l-1
    return int(q1(n+m)/q1(m)/q1(n))
    # return cnm(n+m,n)
def main(x):
    x=str(x)
    # x=input()


    # n 開頭 L長 階梯的數字 的數量 cnm(9-n+(L-1),9-n)
    # for i in range(1,len(x)+1):
    #     for j in range(9):

    #         # n=9-i
    #         # m=j+n
    #         total+=cnm(i-2+j,j-1)

    total=0
    # 長度 １ ＋ 長度 ２ ＋ 長度 ３ ....+長度 len-1
    # print(nstart_len(6,5))
    for i in range(1,len(x)):
        for j in range(1,10):
            # print(i,j)
            total+=nstart_len(j,i)

    for i in range(1,int(x[0])):
        # print(i,len(x))
        total+= nstart_len(i,len(x))
    tem=int(x[0])
    Counter=0
    position=len(x)
    for i in x:
        a=int(i)
        if a>=tem:
            for j in range(tem,a):
                total+=nstart_len(j,position)
                # print(j,position,nstart_len(j,position),total)
            tem=a    
            Counter+=1
        if Counter==len(x) and position==1:
            total+=1
        position-=1
    print(total)
main(input())