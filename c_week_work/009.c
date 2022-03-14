#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
int int_bin(int a){
	int temp=floor(a/2);
	if (a==0)return 0;
	if (a==1)return 1;
	return (a%2)+int_bin(temp)*10;
}
void number_gray(){
	int i=0;
	int a,b;
	scanf("%d %d",&a,&b);
	int out[a];
	int b_temp[a];
	b=int_bin(b);
	for(i=a-1;i>=0;i--)
		b_temp[i]=0;
	i=0;
	while (b>=0){
		b_temp[i]=b%10;
		if (b<1)break;
		b=floor(b/10);
		i=i+1;
	}
	int temp=0;
	for(i=a-1;i>=0;i--){
		if(floor(log(b)+1)<=i){
			out[i]=(int)(b_temp[i]^temp);
			temp=(int)b_temp[i];
		}
		else{
			temp=0;
			out[i]=0;
		}
	}
	for(i=a-1;i>=0;i--){
		printf("%d",out[i]);
	}
	printf("\n");
}
int main() {
	int temp=0;
	while(temp!=-1){
		number_gray();
		scanf("%d",&temp);
	}
}
