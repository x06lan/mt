# x=input()
x=input()
x=x.replace("[","(")
x=x.replace("]",")")
rx=""
last_text="3"
a=""
# for i in 
for i in range(len(x)):
    
    if x[i].isnumeric():
        if last_text.isnumeric()  :
            rx+=x[i]
        else:
            rx+="+"+x[i]        
    else:
        if i==0:
            rx+="'"+x[i]+"'"
        elif last_text.isnumeric():
            rx+="*"+x[i]
        elif last_text in {"("}:
            rx+="'"+x[i]+"'"
        elif x[i] in {")"} :
            rx+=x[i]
        else:
            rx+="+'"+x[i]+"'"
    last_text=x[i]
exec("a="+rx)
print(a)
