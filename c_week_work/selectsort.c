#include <stdio.h>
#include <stdlib.h>
void select_sort(int*a,int n){
	int i,j;
	int count=0;
	for(i=0;i<n-1;i++){
		int max=i;
		for(j=i+1;j<n;j++){
			int tema=*(a+max);
			int temb=*(a+j);
			if(tema>temb){
				max=j;
			}
		}
		if(max!=i){
			count+=1;
		}
		int tem=*(a+i);
		*(a+i)=*(a+max);
		*(a+max)=tem;
	}
	printf("%d\n\n",count);
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
	select_sort(a,n);
	for(i=0;i<n;i++){
		printf("%d\n",*(a+i));
	}


	return 1;
}
