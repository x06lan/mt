dic = { "A": 10, "J": 18, "S": 26,
"B": 11, "K": 19, "T": 27,
"C": 12, "L": 20, "U": 28,
"D": 13, "M": 21, "V": 29,
"E": 14, "N": 22, "W": 32,
"F": 15, "O": 35, "X": 30,
"G": 16, "P": 23, "Y": 31,
"H": 17, "Q": 24, "Z": 33,
"I": 34, "R": 25
}
x=input()
value=dic[x[0]]
bit1=int(str(value)[0])
bit2=int(str(value)[1])*9+bit1
counter=0
for i in range(1,len(x)-1):
        counter+=int(x[9-i])*i
value=counter+bit2+int(x[len(x)-1])
# print(counter,bit2,int(x[len(x)-1]))
# print(value)
if value%10==0:
        print("real")
else:
        print("fake")

