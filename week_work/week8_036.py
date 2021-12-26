import sys
def line(n):
    if n==1:
        return 2
    return line(n-1)+n
print(line(int(input())))