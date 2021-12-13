import sys,os,string,random

if len(sys.argv)==1:
    exit()

file_name=sys.argv[1]
f=open(file_name,'r')
lines=f.readlines()
f.close()

f=open('t.py','w')
f.write("import sys,string,random\n")
f.write("_arr_e=[]\n")
f.write("_arr_s=[]\n")
f.write("def randomString():\n")
f.write("   length_of_string=8\n")
f.write("   return ''.join(random.choice(string.ascii_letters + string.digits) for _ in range(length_of_string))\n")

lines_len=len(lines)

for i in range(lines_len):
    j=0
    while lines[i][j]==' ':
        j+=1
    if lines[i][j:j+3]=='def' \
    or lines[i][j:j+2]=='if' \
    or lines[i][j:j+4]=='else' \
    or lines[i][j:j+3]=='for' \
    or lines[i][j:j+5]=='while':
        j+=4
        f.write(lines[i])
        f.write(' '*j+'_arr_e.append("a"+randomString()+"['+str(i+1)+']")\n')
        f.write(' '*j+'_arr_s.append(str('+str(i+1)+'))\n')
    else:
        f.write(' '*j+'_arr_e.append("a"+randomString()+"['+str(i+1)+']")\n')
        f.write(' '*j+'_arr_s.append(str('+str(i+1)+'))\n')
        f.write(lines[i]+'\n')
    
if len(sys.argv) == 2 or sys.argv[2]=='-e':
    f.write('\nsys.stderr.write("-->".join(_arr_e))\n')
    f.write('sys.stderr.write("\\n")\n')
if len(sys.argv) == 2 or sys.argv[2]=='-s':
    f.write('sys.stderr.write("-->".join(_arr_s))\n')
    f.write('sys.stderr.write("\\n")\n')
f.close()
os.system("python3 t.py > temp")    