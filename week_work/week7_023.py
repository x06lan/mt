
import random
player=0
computer=0
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
player+=key[input()]
computer+=key[input()]
yes_or_no=input()
computer_no=0
while  True  :
    takecard=0
    if yes_or_no =="Y":
        player+=key[input()]
        takecard+=1

    if computer<=8 or computer<player and computer_no==0:
        computer+=key[input()]
        takecard+=1
    else :
        computer_no=1
        
    if computer>10.5 and player>10.5 :
        computer=0
        player=0
        break
    elif computer>10.5:
        computer=0
        break
    elif player>10.5:
        player=0
        break
    if yes_or_no!= "Y":
        if  takecard==0:
            break
    else:
        yes_or_no=input()


print("%.1lf vs. %.1lf"%(player,computer))

if computer==player:
    print("It's a tie")
elif computer>10.5 or (player<=10.5 and player>computer):
    print("player wins")
else:
    print("computer wins")



