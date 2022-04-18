#include <stdio.h>
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
}
int main(){
	//t1(2);
	t2(3);

	return 0;
}
