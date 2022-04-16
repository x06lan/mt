#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define big 81
//number 40 is last int 
#define point 40
void str_int(char text[45],int a[big]){
	int mide=-1;
	int i,j;
	for(i=0;i<45;i++){
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
		int tem=text[i]-'0';
		int index=-i+mide-1+point;
		if(tem<0||tem>9){
			break;
		}
		a[index]=tem;
	}
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
			int tem=a[i+20]*b[j+20]+c[i+j]+up;
			up=tem/10;
			c[i+j]=tem%10;
		}
	}
}
int main(){
	char str_a[45]="",str_b[45]="";
	int a[big];
	int b[big];
	int c[big];
	memset(a,0,sizeof(int)*big);
	memset(b,0,sizeof(int)*big);
	memset(c,0,sizeof(int)*big);
	scanf("%s",str_a);
	scanf("%s",str_b);
	str_int(str_a,a);
	str_int(str_b,b);
	big_add(a,b,c);
	big_print(c);
	printf("\n");

	memset(c,0,sizeof(int)*big);
	big_sub(a,b,c);
	big_print(c);
	printf("\n");

	memset(c,0,sizeof(int)*big);
	big_mul(a,b,c);
	big_print(c);
	return 0;
}

