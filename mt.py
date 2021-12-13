def num(cin):
  return "".join([str(i) for i in range(cin,0,-1)])
def main():

  x=int(input())
  if 1<=x and x <=31:
    tem=""
    for i in range(x):
      tem+="#"*(x+i)
      tem+=num(x-i)+"\n"
    
    print(tem)
  else:
    print("error")
# main()
def triangle(n):
  b=(n-1)//2
  for i in range(b,0,-1):
    print("#"*i,end="")
    print("*"*int(b-i+1))
  print("*"*int(b+1))
  for i in range(1,b+1):
    print("#"*i,end="")
    print("*"*int(b-i+1))
    print("error")
# main()
def shape(n):
  b=(n-1)//2
  for i in range(b,0,-1):
    print("#"*i,end="")
    print("*"*int(2*b-i*2+1))
  print("*"*int(2*b+1))
  for i in range(1,b+1):
    print("#"*i,end="")
    print("*"*int(2*b-i*2+1))


# triangle(int(input()))   
# shape(int(input()))  
def ox(data):
  # ---
  for i in range(3) :
    if data[i][0]!=None:
      if data[i][0]== data[i][1] and data[i][0]== data[i][2]:
        return True,data[i][0]
  # -
  # -
  # - 
  for i in range(3) :
    if data[0][i]!=None:
      if data[0][i]== data[1][i] and data[0][i]== data[2][i]:
        return True,data[0][i]
  
  if data[0][0]!=None :
    if data[0][0]== data[1][1] and data[0][0]== data[2][2]:
      return True,data[0][0]
  if data[0][2]!=None :
    if data[0][2]== data[1][1] and data[0][2]== data[2][0]:
      return True,data[0][2]
  return False,None
def shape(data):
  for i in data:
    for j in i:
      if j!=None:
        print(j,end=" ")
      else:
        print("_",end=" ")
    print()
data=[[None,None,None],
  [None,None,None],
  [None,None,None]]
print(ox(data))
shape(data)