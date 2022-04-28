#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int tt1(int n,int m,int g){
	int i=n;
	if(g==-1){
		for(i=n;i<m;i++){
			printf("%d",abs(i));
		}
	}
	else if(g==0){
		for(i=m;i>=n;i--){
			printf("%d",abs(i));
		}
	}else{
		for(i=n;i<m;i++){
			printf("%d",g);
		}
	}
	return 0;
}
int t1(int len){
	int i,j;
	for(i=1;i<len+1;i++){
		for(j=1;j<=i;j++){
			printf("%d",j);
		}
		printf("\n");
	}
	for(i=len;i>=1;i--){
		for(j=i;j>=1;j--){
			printf("%d",j);
		}
		printf("\n");
	}
	for(i=1;i<len+1;i++){
		for(j=1;j<=i;j++){
			printf("%d",i);
		}
		printf("\n");
	}
	return 0;
}
int t2(int len){
	int i,j;
	for(i=1;i<len+1;i++){
		for(j=1;j<i;j++){
			printf("%d",j);
		}
		for(j=i;j>=1;j--){
			printf("%d",j);
		}
		printf("\n");
	}
	for(i=2;i<len+1;i++){
		for(j=0;j<len-i;j++){
			printf(" ");
		}
		for(j=i-1;j>=1;j--){
			printf("%d",j);
		}
		for(j=2;j<i;j++){
			printf("%d",j);
		}
		printf("\n");
	}
	for(i=len;i>=2;i--){
		for(j=0;j<len-i;j++){
			printf(" ");
		}
		for(j=i-1;j>=1;j--){
			printf("%d",j);
		}
		for(j=2;j<i;j++){
			printf("%d",j);
		}
		printf("\n");
	}
	return 0;
}
int main(){
	//t1(2);
	int i;
	int n=5;
	for(i=0;i<n;i++){
		tt1(1,i+2,-1);
		printf("\n");
	}
	for(i=n;i>0;i--){
		tt1(1,i,0);
		printf("\n");
	}
	for(i=0;i<n;i++){
		tt1(1,i+2,i+1);
		printf("\n");
	}
	return 0;
}
