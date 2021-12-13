# from _typeshed import Self
import sys
input_text=[]
try :
    while True:
        tem=input()
        if tem=="":
            break
        input_text.append(tem)
except:
    pass
tree_data={}
class newtree():
    def __init__(self):
       self.tree={}
       self.node=1
    def tree_add_text(self,mom,input):
            # print(input)
            try:
                index=mom[input[0]]
            except:
                index=None
            if index == None :
                mom[input[0]]={}
                self.node+=1
            if len(input) != 1:
                # print(mom)
                self.tree_add_text(mom[input[0]],input[1::1])
            else :
                self.tree=mom
tree=newtree()
tree_data={}
for x in  input_text:
    tree.tree_add_text(tree_data,x)
print(tree_data)
print(tree.node)

