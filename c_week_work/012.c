#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
int command(int a,int b){
	int tem=0;
	while(a>=1 &&b>=1){
		tem=a%b;
		a=b;
		b=tem;
	}
	return (a>=1)?a:1;
}
void deal(int a,int b,int aa,int bb,char sign[]){
	if(b==0||bb==0){
		printf("ERROR\n");
		return;
	}
	int out[3]={0};
	if(strcmp(sign,"/")==0){
		int temp=aa;
		aa=bb;
		bb=temp;
		sign="*";
	}
	if(strcmp(sign,"*")==0){
		out[0]=a*aa;
		out[1]=b*bb;
	}
	a=a*bb;
	aa=aa*b;
	if(strcmp(sign,"+")==0){
		out[0]=a+aa;
		out[1]=b*bb;
	}
	if(strcmp(sign,"-")==0){
		out[0]=a-aa;
		out[1]=b*bb;
	}
	if (abs(out[0])/out[1]>=1){
		out[2]=out[0]/out[1];
		out[0]=out[0]%out[1];
		int gcd=command(abs(out[0]),out[1]);
		printf("%d(%d/%d)\n",out[2],abs(out[0])/gcd,out[1]/gcd);
	}else if(out[0]==0){
		printf("0\n");
	}
	else{
		int gcd=command(abs(out[0]),out[1]);
		printf("%d/%d\n",out[0]/gcd,out[1]/gcd);
	}
}
int main() {
	int a,b=0;
	int aa,bb=0;
	char stop[5]="";
	char sign[5]="";
	while(strcmp(stop,"n")!=0){
		scanf("%d/%d",&a,&b);
		scanf("%d/%d",&aa,&bb);
		scanf("%s",&sign);
		scanf("%s",&stop);
		deal(a,b,aa,bb,sign);
	}
}
