
key={
    "A":1,
    "2":2,
    "3":3,
    "4":4,
    "5":5,
    "6":6,
    "7":7,
    "8":8,
    "9":9,
    "10":10,
    "J":0.5,
    "K":0.5,
    "Q":0.5,
}
def getcard(number):
    yes_or_no=input()
    if yes_or_no=="Y":
        card=input()
        data[number]+=key[card]
        if data[number]>10.5:
            data[number]=0
            return True,True
        else:
            return True,False
    else:
        return False,False


peo=int(input())+1
bat=[int(i) for i in input().split()]
data=[key[i] for i in input().split()]
cardsc=[0 for i in range(peo)]
data.append(0)

for i in range(0,peo):
    card_counter=1
    # print("ep",i)
    while True:
        if card_counter==5 or (card_counter==2 and data[i]==10.5):
            cardsc[i]=card_counter
            break
        if i==peo-1 and card_counter==1:
            card=input()
            data[i]+=key[card]
        else:
            yesorno,boom=getcard(i)
            if (not yesorno) or boom:
                cardsc[i]=card_counter
                break
        card_counter+=1

# print(data)
hostwin=0
for i in range(len(data)-1):
    x=data[i]
    if x>10.5:
        x=0
    if cardsc[i]==2 and x==10.5 :
        print("Player{} +{}".format(i+1,bat[i]))
        hostwin-=bat[i]
    elif cardsc[i]>=5:
        print("Player{} +{}".format(i+1,bat[i]))
        hostwin-=bat[i]
    elif x>data[len(data)-1]:
        hostwin-=bat[i]
        print("Player{} +{}".format(i+1,bat[i]))
    elif x==data[len(data)-1]:
        print("Player{} -{}".format(i+1,bat[i]))
        hostwin+=bat[i]
    else:
        hostwin+=bat[i]
        print("Player{} -{}".format(i+1,bat[i]))

 
print("Bank +{}".format(hostwin) if hostwin>0 else "Bank {}".format(hostwin))
    
