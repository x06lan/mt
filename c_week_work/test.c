#include <stdio.h>
#include <math.h>

void f(int *a, int*b,int*c){
	int *temp=a;
	*b=(*c)*(*temp);
	*c=*temp;
	*a=10;
	a=b;
	b=c;
	c=temp;
}
int main() {
	int i=-1,j=4,k=2;
	f(&i,&j,&k);
	printf("%d ,%d %d",i,j,k);
}
