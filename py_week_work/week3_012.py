import math
# 語音 網內 0.08 0.07 0.06
# (元/秒) 網外 0.1393 0.1304 0.1087
# 市話(元/秒) 0.1349 0.1217 0.1018
# 簡訊 網內 1.1287 1.1127 0.9572
# (元/則) 網外 1.4803 1.2458 1.1243

rate= [[0.08, 0.07, 0.06],
 [0.1393, 0.1304, 0.1087],
 [0.1349, 0.1217, 0.1018],
 [1.1287, 1.1127, 0.9572],
 [1.4803, 1.2458, 1.1243],
 [183,383,983]]
input_save=[]
save_type=""
tem=100000
for x in range(5):
    input_save.append(int(input()))
for x in range(3):
    out=0.0
    for y in range(5):
        out=out+input_save[y]*rate[y][x]
    if out<rate[5][x]:
        out=rate[5][x]
    # print(out)
    if out<tem:
        tem=out
        save_type=rate[5][x]
print("Type {}".format(save_type))

