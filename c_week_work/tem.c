#include <stdio.h>
#include <stdlib.h>
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
	int *num=malloc(sizeof(int)*10);
	*(num+1)=5;
	free(num);
	int a,*b,**c;
	a=5;
	b=&a;
	c=&b;
	printf("%d\n",**c);
	printf("%d\n",(**c)++);
	printf("%d\n",**c);
	
	
	
}
