#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>

void big_add(char  a[],char b[],char *out){
	int i=0;
	int up=0;
	int tema=(int)a[i]-48;
	int temb=(int)b[i]-48;
	bool run=tema>=0 && tema<10 &&tema>=0 && tema<10;
	while(run || up==1){
		*(out+i)=(tema+temb+up)%10;
		printf("%d",*(out+i));
		up=(tema+temb+up)/10;
		i+=1;
		tema=(int)a[i]-48;
		temb=(int)b[i]-48;
		run=tema>=0 && tema<10 &&tema>=0 && tema<10;
	}

}

int main() {
	char a[45],b[45];
	char x[45];
	char *out;
	out=x;
	int i=0;
	scanf("%s",&a);
	scanf("%s",&b);
	big_add(a,b,x);

	printf("%c",x[0]);
	//int tem=(int)x[i]-48;
	//int tem=(int)*(out+i)-48;
	int tem=(int)*(x+i)-48;
	while(tem>=0 && tem<10 ){
		printf("%d",tem);
		i+=1;
		//tem=(int)*(out+i)-48;
		tem=(int)*(x+i)-48;
		//tem=(int)x[i]-48;
	}
}
