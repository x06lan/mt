#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
		i=89;
		tem=a[i];
		for(i=89;i>=0;i--){
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
	int i=44;
	int as=a[i];
	int bs=a[i];
	for(i=44;i>=0;i--){
		as=a[i];
		bs=a[i];
		if(as>bs){
			return 1;
		}
		else if(as<bs){
			return -1;
		}
	}
	return 0;
}


int main() {
	char a[45],b[45];
	int x[90],y[90],z[90];
	int i=0;
	int sign=1;
	int op=0;
	scanf("%d",&op);
	scanf("%s",&a);
	scanf("%s",&b);
	memset(x,0,90);
	memset(y,0,90);
	memset(z,0,90);
	str_int(a,x);
	str_int(b,y);
	return 0;
}
