import math

a= input()
b= input() 

name_arr=a.split(" ")
day=b.split("/")


print("{} is born at year {} month {} day {} in {} family.".format(name_arr[0],day[0],day[1],day[2],name_arr[1]))

# Sample Input I:
# kobe Bryant
# 1978/08/23
# Sample Output
# kobe is born at year 1978 month 08 day 23 in Bryant family.