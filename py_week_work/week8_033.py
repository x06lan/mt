out=[]
def GCD(para):
    a=para[0]
    b=para[1]
    
    while a>=1 and b>=1:
        tem=a%b
        a=b
        b=tem
    if len(para)==2:
        return a
    return GCD([a]+para[2::])
# print(GCD([21,42,63]))
i=input()
while i!="-1":
    i=[int(j) for j in i.split()]
    out.append(str(GCD(i)))
    i=input()
for i in out:
    print(i)
