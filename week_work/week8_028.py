def check(indata,divi,loss):
    return indata % divi == loss
def main():
    dd=list(map(int,input().split()))
    # print(dd)
    status=True
    count=0
    while status:
        if check(count,dd[0],dd[0+1]) and check(count,dd[2],dd[2+1]) and check(count,dd[4],dd[4+1]):
            break
        count+=1
    print(count)
#-------------my1---- 

def Euclidean(a,b):
    count=0
    while a>0 and b>0:
        # print(count)
        tem=a%b
        a=b
        b=tem
        count+=1
    return a
def Chinese_remainder_theorem(para):
    # print(para)

    if len(para)==2:
        return para[1]
    x =Euclidean(para[0],para[2])
    x=para[0]*int(para[2]/x)
    for i in range(x):
        # print(i)
        if check(i,para[0],para[1]) and check(i,para[2],para[3]):
            return Chinese_remainder_theorem([x,i]+para[4::])
# -------------from web ----
# from functools import reduce
# def chinese_remainder(m, a):
#     sum = 0
#     prod = reduce(lambda acc, b: acc*b, m)
#     for n_i, a_i in zip(m, a):
#         p = prod // n_i
#         sum += a_i * mul_inv(p, n_i) * p
#     return sum % prod
# def mul_inv(a, b):
#     b0 = b
#     x0, x1 = 0, 1
#     if b == 1: return 1
#     while a > 1:
#         q = a // b
#         a, b = b, a%b
#         x0, x1 = x1 - q * x0, x0
#     if x1 < 0: x1 += b0
#     print(x1)
#     return x1
# if __name__ == '__main__':
#     m= [3,4,7]
#     a = [1,1,0]
#     print(chinese_remainder(m, a))
print(Chinese_remainder_theorem([3,2,5,3,7,2,4,3]))
# print(Chinese_remainder_theorem([3,1,4,1,7,0]))
# print(chinese_remainder([3,5,7],[2,3,2]))
# main()