#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
int c(int number,int counter){
	counter+=1;
	if(number==0 ||number==1)return counter;
	if(number%2==0){
		return c(number/2,counter);
	}else{
		return c((number+1)/2,counter);
	}
}
int bin_int(int number){
	int out=0;
	int level=0;
	while(number>0){
		out+=(number%10)*pow(2,level);
		number/=10;
		level+=1;
	}
	return out;
}
void int_bin(int number){
	int out[11]={0};
	int i=0;
	while(i<11){
		out[i]=number%2;
		number/=2;
		i+=1;

	}
	for(i=0;i<11;i++){
		printf("%d",out[11-i-1]);
	}
	
}
int main() {
	int temp=0;
	int b=0;
	int cn=0;
	int out[1000]={0};
	int i=0;
	while(b!=-1){
		scanf("%d",&temp);
		temp=bin_int(temp);
		for(i=2;i<=temp;i++){
			out[cn]+=c(i,-1);
		}
		cn+=1;
		scanf("%d",&b);
	}
	for(i=0;i<cn;i++){
		int_bin(out[i]);
		printf("\n");
	}
}
