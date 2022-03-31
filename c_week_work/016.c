#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int big=100;
//lanx
void str_int(char a[],int* out){
	int i=strlen(a)-1;
	int tem=(int)a[i]-48;
	while(i>=0 ){
		out[strlen(a)-i-1]=tem;
		i-=1;
		tem=(int)a[i]-48;
	}
}
void big_print(int *a){
		int i,tem,notz=0;
		i=big-1;
		tem=a[i];
		for(i=big-1;i>=0;i--){
			tem=a[i];
			if(tem!=-1 &&tem!=0 ){
				notz=1;
			}
			if(notz==1){
				printf("%d",tem);
			}
		}
}
int compare(int *a,int *b){
	int i=0;
	int as=a[i];
	int bs=b[i];
	for(i=big-1;i>=0;i--){
		as=a[i];
		bs=b[i];
		if(as>bs&& bs>=0){
			return 1;
		}
		else if(as<bs && as>=0){
			return -1;
		}
	}
	return 0;
}
void big_mul(int *a,int *b,int *c){
	int i,j,up=0;
	for(i=0;i<=45;i++){
		for(j=0;j<=45;j++){
			int tem=a[i]*b[j]+up+c[i+j];
			up=tem/10;
			c[i+j]=tem%10;
		}
	}
}
void big_add(int *a,int *b,int *c){
	int i,up;
	for(i=0;i<big;i++){
		int tem=a[i]+b[i]+up;
		up=tem/10;
		c[i]=tem%10;
	}
}
void big_sub(int *a,int *b,int *c){
	int i,up;
	up=0;
	for(i=0;i<big;i++){
		int tem=a[i]-b[i]-up;
		if(tem<0){
			tem+=10;
			up=1;
		}
		else{
			up=0;
		}
		c[i]=tem;
	}
}
void big_div(int *a,int *b,int *c){
	int i,j;
	int tem[big];
	memset(tem,0,big*sizeof(int));
	for(i=40;i>=0;i--){
		for(j=9;j>=0;j--){
			int tem2[big];
			memset(tem2,0,big*sizeof(int));
			int tem3[big];
			memset(tem3,0,big*sizeof(int));
			tem2[0]=j;
			tem[i]=1;
			big_mul(b,tem2,tem3);
			memset(tem2,0,big*sizeof(int));
			big_mul(tem,tem3,tem2);
			tem[i]=0;
			if(j==0){
				c[i]=0;
			}
			else if(compare(a,tem2)>=0){
				big_sub(a,tem2,a);
				c[i]=j;
				break;
			}
		}
	}
}
int main() {
	char a[45],b[45];
	int x[big],y[big],z[big];
	//scanf("%d",&op);
	scanf("%s",&a);
	scanf("%s",&b);
	memset(x,0,big*sizeof(int));
	memset(y,0,big*sizeof(int));
	memset(z,0,big*sizeof(int));
	str_int(a,x);
	str_int(b,y);
	//big_mul(x,y,z);
	big_div(x,y,z);
	big_print(z);
	return 0;
}
