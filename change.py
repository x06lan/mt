# from typing import Counter

# counter={}
words=input().split(" ")
counter ={  x:words.count(x) for x in set(words)}
print('max: ', max(counter))
print('min: ', min(counter))



# a = input().split()
# d = {}
# for x in a:
#     try:
#         d[x] += 1
#     except:
#         d[x] = 1

# print('max: ', max(d))
# print('min: ', min(d))

# words = input().split()
# counter={}
# for word in set(words):
#     counter[word] = words.count(word)
#     print(word)
# print('max: ', max(counter))
# print('min: ', min(counter))