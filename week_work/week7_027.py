def powerword(password):
    counter=0    
    x="~!@#$%^&*<>_+="
    # password=set([i for i in password])
    for i in x :
        counter+=password.count(i)
    return counter
def number_counter(password):
    counter=0
    for x in range(10):
       counter+= password.count(str(x))
    return counter
def eng_counter(password):
    upc=0
    lowc=0
    for x in password:
        if x.isupper(): upc+=1
        if x.islower():lowc+=1
    return (upc,lowc)
def sp(password):
    tem=0
    for x in password:
        if x.isnumeric():
            if tem==1:
                return False
            else:
                tem=1
        else:
            tem=0
    return True
def allpoint(password):
    point=0
    upnumber,lownumber=eng_counter(password)
    number=number_counter(password)
    power=powerword(password)
    if sp(password)and number>=5:
        point+=10
    point+=lownumber
    point+=upnumber*2
    point+=number*3
    point+=power*5
    # print(upnumber,lownumber,number,power)
    return point
save=[]
text=input()
maxcounter=0
mincounter=0
maxpass=""
minpass=""
tem=0
while text!="-1":
 
    point=allpoint(text)
    if point>maxcounter:
        maxcounter=point
        maxpass=text
    if point <mincounter:
        minpass=text
        mincounter=point
    
    if tem==0:
        mincounter=point
        minpass=text

        # print(mincounter)

    tem+=1
    # print(tem)
    text=input()
print(maxpass,maxcounter)
print(minpass,mincounter)

