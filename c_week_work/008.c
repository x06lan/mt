#include <stdio.h>
#include <math.h>
void type_1(int b){
	int i=0,j=0;
	for(i=1;i<b;i++){
		for(j=0;j<i;j++){
			printf("%s","*");
		}
		printf("\n");
	}
	for(i=b;i>0;i--){
		for(j=0;j<i;j++){
			printf("%s","*");
		}
		printf("\n");
	}
}
void type_2(int b){
	int i=0,j=0;
	for(i=1;i<b;i++){
		for(j=b;j>i;j--){
			printf("%s",".");
		}
		for(j=0;j<i;j++){
			printf("%s","*");
		}
		printf("\n");
	}
	for(i=b;i>0;i--){
		for(j=b;j>i;j--){
			printf("%s",".");
		}
		for(j=0;j<i;j++){
			printf("%s","*");
		}
		printf("\n");
	}


}
void type_3(int b){
	int i=0,j=0;
	for(i=1;i<b;i++){
		for(j=b;j>i;j--){
			printf("%s",".");
		}
		for(j=0;j<i*2-1;j++){
			printf("%s","*");
		}
		printf("\n");
	}
	for(i=b;i>0;i--){
		for(j=b;j>i;j--){
			printf("%s",".");
		}
		for(j=0;j<i*2-1;j++){
			printf("%s","*");
		}
		printf("\n");
	}
}
int main() {
	int i=0,j=0;
	int a,b=0;
	scanf("%d",&a);
	scanf("%d",&b);
	b=(b-1)/2+1;

	if (a==1){
		type_1(b);
	}
	else if(a==2){
		type_2(b);
	}
	else{
		type_3(b);
	}
	//type 1
	//type2
	//type3


}
