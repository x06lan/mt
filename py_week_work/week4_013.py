import math
m=int(input())
n=int(input())
count=0
count1=1
for x in range(m,n+1,2):
    count+=x
# count+=n
for x in range(m,n+1,3):
    count1*=x
print(count)
print(count1)