#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
long long int str_int(char *a){
	long long int x=0;
	long long int tem=1;
	int up=2;
	int i=0;
	for(i=19;i>=0;i--){
		if((int)a[i]-48>=0){
			if((int)a[i]-48>1){
				x=-1;
				break;
			}
			else{
				x+=((int)a[i]-48>0)*tem;
				tem*=up;
			}
		}
	}
	return x;
}
long long int change_base(long long int x){
	int i=0;
	long long int z=0;
	long long int tem=1;
	int up=10;
	while(x>0){
		z+=(x%7)*tem;
		tem*=up;
		x/=7;
	}
	return z;
}
int main() {
	char a[20]="";
	scanf("%s",&a);
	long long int x=str_int(a);
	//printf("%d\n",x);
	if(x==-1){
		printf("ERROR");
		return 0;
	}
	long long int z=change_base(x);
	printf("%d",z);
}
