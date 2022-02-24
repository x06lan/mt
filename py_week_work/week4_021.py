x =int(input())
y =int(input())
total=0
x=x if x%2==0 else x+1
for i in range(x,y+1,2):
    total+=i
print(total)









