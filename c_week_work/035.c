#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define big 241
//number 120 is last int 
#define point 120
int str_int(char text[45],int a[big]){
	int mide=-1;
	int sign=1;
	int i,j;
	for(i=0;i<100;i++){
		if(mide!=-1){
			int tem=text[i]-'0';
			int index=mide-i+point;
			if(tem<0||tem>9){
				break;
			}
			a[index]=tem;
		}
		if(text[i]=='.'){
			mide=i;
		}
	}
	for(i=mide-1;i>=0;i--){
		if(text[i]=='-')sign=-1;
		int tem=text[i]-'0';
		int index=-i+mide-1+point;
		if(tem<0||tem>9){
			break;
		}
		a[index]=tem;
	}
	return sign;
}
int compare(int a[big],int b[big]){
	int i=big-1;
	while(i>=0){
		if(a[i]>b[i])return 1;
		if(a[i]<b[i])return -1;
		i--;
	}
	return 0;
}
void big_print(int a[big]){
	int i;
	int flip=0;
	for(i=big-1;i>=point;i--){
		if(a[i]!=0)flip=1;
		if(flip==1)printf("%d",a[i]);
	}
	if(flip==0)printf("0");
	flip=-1;
	for(i=0;i<point;i++){
		if(a[i]!=0){
			flip=i;
			break;
		}
	}
	if(flip!=-1){
		printf(".");	
		for(i=point-1;i>=flip;i--){
			printf("%d",a[i]);
		}
	}
}
void big_add(int a[big],int b[big],int c[big]){
	int i=0;
	for(i=0;i<big-1;i++){
		int tem=a[i]+b[i]+c[i];
		c[i]=tem%10;
		c[i+1]=tem/10;
	}
}
void big_sub(int a[big],int b[big],int c[big]){
	int up=0;
	int i=0;
	for(i=0;i<big-1;i++){
		int tem=a[i]-b[i]-up;
		up=(tem<0)?1:0;
		tem=(up==1)?tem+10:tem;
		c[i]=tem;
	}
}
void big_mul(int a[big],int b[big],int c[big]){
	int up=0;
	int i,j=0;
	for(i=0;i<big/2;i++){
		for(j=0;j<big/2;j++){
			int tem=a[i+point/2]*b[j+point/2]+c[i+j]+up;
			up=tem/10;
			c[i+j]=tem%10;
		}
	}
}
void add_sub(int a[big],int b[big],int c[big],int signa,int signb){

	if(signa==signb){
		big_add(a,b,c);
		if(signa==-1)printf("-");
	}
	else{
		if(signa!=-1){
			if(compare(a,b)>0){
				big_sub(a,b,c);
			}
			else{
				big_sub(b,a,c);
				printf("-");
			}
		}
		else{
			if(compare(a,b)>0){
				//printf("*%d\n",compare(a,b));
				big_sub(a,b,c);
				printf("-");
			}
			else{
				big_sub(b,a,c);
			}
		}
	}

}
int main(){
	char str_a[100]="",str_b[100]="";
	int a[big];
	int b[big];
	int c[big];
	int signa;
	int signb;
	memset(a,0,sizeof(int)*big);
	memset(b,0,sizeof(int)*big);
	memset(c,0,sizeof(int)*big);
	scanf("%s",str_a);
	scanf("%s",str_b);
	signa=str_int(str_a,a);
	signb=str_int(str_b,b);

	memset(c,0,sizeof(int)*big);
	add_sub(a,b,c,signa,signb);
	big_print(c);
	printf("\n");

	memset(c,0,sizeof(int)*big);
	signb*=-1;
	add_sub(a,b,c,signa,signb);
	big_print(c);
	printf("\n");

	signb*=-1;
	memset(c,0,sizeof(int)*big);
	if(signa==1 ^signb==1)printf("-");
	big_mul(a,b,c);
	big_print(c);
	return 0;
}

