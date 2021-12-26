# 014
# 輸入一字串，
# 1. 印出該字串中的小寫字母 (注意:若沒有字串中沒有小寫字母則輸出'No lowercase letters')
# 2. 計算該字串有幾個字元?
# 3. 計算該字串中大寫字元的數量

# Sample Input
# I have a pen, I have an apple.

# Sample Output
# haveapenhaveanapple
# 30
# 2
low=""
high=0
intext=input()
for x in range(len(intext)):
    i=intext[x]
    if i.isupper():
        high+=1
    if i.islower():
        low+=i

print (low if len(low)!=0 else "No lowercase letters")
print(len(intext))
print(high)
