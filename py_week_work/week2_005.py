import math
g=[[x+y for y in range(5) ]for x in range(6)]

s=lambda x,y :x if x>y else [z**2 for z in range(y)]
print(s(1,0))
b=3
c=4
print( [b, c][c > b])
print(c > b and c or b)

in_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 8, 7]
print('array before:', in_list)
array = {i: i * 2 for i in in_list if i % 2 != 0}  # 字典推導表示式
print('array after:', array)
# print(s)
t=lambda x: [i for i in range(x) if i %2!= 0  ]
# print(list(range(5)))
gg=[print("4")]
# gg[0]()
f = lambda x:[y for y in range(x)] 
print(f(5))
print(f)
