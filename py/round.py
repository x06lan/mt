import math 
get_input=lambda :[float(x) for x in input().split(" ")]
line_arg=lambda a,b:[a[0]-b[0],a[1]-b[1]] 
cneter_point=lambda a,b: [(a[0]+b[0])/2,(a[1]+b[1])/2] 
matrix_value=lambda a:a[0][0]*a[1][1]-a[0][1]*a[1][0]
def main():
    p1=get_input()
    p2=get_input()
    p3=get_input()
  
    cp1=cneter_point(p1,p2)
    cp2=cneter_point(p1,p3)
    a,b=line_arg(p1,p2)
    c,d=line_arg(p1,p3)
    e=a*cp1[0]+b*cp1[1]
    f=c*cp2[0]+d*cp2[1]
    tra=[[a,b],
        [c,d]]
    tra_x=[[e,b],
        [f,d]]
    tra_y=[[a,e],
        [c,f]]
    tra=matrix_value(tra)
    tra_x=matrix_value(tra_x)
    tra_y=matrix_value(tra_y)
    x=tra_x/tra
    y=tra_y/tra
    return x,y
print(main())