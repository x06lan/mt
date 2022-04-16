#include <stdio.h>
#include <stdlib.h>
void insert_sort(int*a,int n){
	int i,j;
	for(i=1;i<n;i++){
		for(j=i;j>0;j--){
			int tema=*(a+j);
			int temb=*(a+j-1);
			if(tema<temb){
				*(a+j)=temb;
				*(a+j-1)=tema;
			}
		}
	}
}

int main(){
	int n=5;
	int *a= malloc(sizeof(int)*(n));
	int i,j,k=0;
	for(i=0;i<n;i++){
		*(a+i)=n-(i+1)+1;
	}
	for(i=0;i<n;i++){
		printf("*%d\n",*(a+i));
	}
	insert_sort(a,n);
	for(i=0;i<n;i++){
		printf("%d\n",*(a+i));
	}


	return 1;
}
