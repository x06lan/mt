#include <stdio.h>
#include <stdlib.h>
void insert_sort(int*a,int n){
	int i,j;
	int count=0;
	for(i=1;i<n;i++){
		for(j=i;j>0;j--){
			int tema=*(a+j);
			int temb=*(a+j-1);
			if(tema<temb){
				count+=1;
				*(a+j)=temb;
				*(a+j-1)=tema;
			}
		}
	}
	printf("%d\n",count);
}

int main(){
	int n=15;
	int *a= malloc(sizeof(int)*(n));
	int i,j,k=0;
	int tem[15]={1,781,848,7,4,99,11,44,88,90,111,11,54,12,55};
	for(i=0;i<n;i++){
		*(a+i)=tem[i];
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
