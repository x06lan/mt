#include <stdio.h>
#include <stdlib.h>
int* f(){

	int *tem=malloc(sizeof(int)*4);
	int i=0;
	for(i=0;i<4;i++)
		*(tem+i)=i;
	return tem;
}
int main() {
	int* e;
	e=f();

	printf("%d\n",*(e+1));
}
