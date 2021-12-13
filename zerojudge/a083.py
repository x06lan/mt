n=input().split(" ")
n= [int(x) for x in n]
# print(n)
s=n[1]
n=n[0]+1

print(n)
data=[""*n]
senta=[]
# better={x:[] for x in range(n)}
# eq={x:[] for x in range(n)}

def conpare(sen):
    if sen[0]==1:
        if data[sen[1]]=="":
            pass
    elif sen[0]==2:
        if data[sen[1]]=="":
            data[sen[1]]=3
        if data[sen[2]]=="":
            data[sen[1]]=2
    


fake_count=0
for x in range(s) :
    line=input().split()
    line=[int(i) for i in line]

    if line[1]>=n or line[2]>=n:
        fake_count+=1
    else :
        if line[0]==1 and line[1]!= line[2]:
            # eq[line[1]].append(line[2])

            senta.append(line)
            
        elif line[0]==2:
            if line[1]==line[2]:
                fake_count+=1
            else:
                # better[line[1]].append(line[2])
                senta.append(line)
for x in senta:




# for xkey in better:
#     x=better[xkey]
#     if len(x)!=0:
#         for ykey in x:
#             y=x[ykey]
              

print(senta)
print(fake_count)

