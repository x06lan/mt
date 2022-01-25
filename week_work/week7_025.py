def get_key():
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
    "J":11,
    "K":12,
    "Q":13,
    }
    flower=[
        "S",
        "H",
        "D",
        "C"
    ]
    return key,flower
def same_card(cards):
    x=set(cards)
    if len(cards)!=len(x):
        return False
    else:
        return True

def same_number(cards):
    key ,flower=get_key()
    number=[i[0:-1] for i in cards]
    cards_number="".join(number)
    out=[]
    for x in key:
        if cards_number.count(x)!=0:
            out.append([cards_number.count(x),key[x]])
    return out
def same_flower(cards):
    key ,flower=get_key()

    number=[i[-1] for i in cards]
    cards_number="".join(number)
    if cards_number.count(number[0])==len(number):
        return True
    else :
        return False
def flow(cards):
    # print(cards)
    key ,flower=get_key()

    number=[key[i[0:-1]] for i in cards]
    number=sorted(number)
    tem=0
    counter=0
    for x in number:
        # print(counter,counter!=0)
        if (x-tem!=1  or (tem==13 and x== 1))and counter!=0:
            return False
        else:
            tem=x
        counter+=1
    return True


def main():


    cards=input().split()
    length=len(cards)
    number_counter=sorted(same_number(cards),reverse=True)
    # flower_counter=sorted(same_flower(cards),reverse=True)

    # print(same_flower(cards))
    # print(number_counter)

    if length==1:
        # 散牌
        print(0)
    elif  number_counter[0][0]==2 and number_counter[1][0]==2:
        # 二對
        print(2)
    elif number_counter[0][0] ==2:
        # 一對
        print(1)
    elif number_counter[0][0] ==3 and number_counter[1][0]==2:
        # 葫蘆
        print(6)
    elif number_counter[0][0]==3:
        # 三條
        print(3)
    elif number_counter[0][0]== 4:
        # 四條
        print(7)

    elif flow(cards):
        if  same_flower(cards):
            # 同花順子
            print(8)
        else :
            print(4)

    elif  same_flower(cards):
            # 同花
            print(5)
    else:
        print(0)

main()

