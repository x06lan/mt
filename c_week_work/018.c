#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
int check(int a[],int start ,int size){
	int same=1;
	int i=start;
	int max=i+size;
	int com=a[i];
	if(com==-1)return 0;
	for(i+=1;i<max;i++){
		int tem=a[i];
		if(tem==-1)break;
		//printf("%d %d %d %d\n",com,tem,start,size);
		if(tem==com ){
			same=0;
			break;
		}
	}
	if(size!=1&& start<100 &&same==1){
		same=check(a,start+1,size-1);
	}
	return same;
	
}
int main() {
	char a[100]="";
	int size;
	scanf("%s",&a);
	scanf("%d",&size);
	int df[100]={-1};
	int i=0;
	int out=0;
	for(i=0;i<100;i++){
		int tem=a[i]-'0';
		if(tem>=0&& tem<10){
			df[i]=tem;
		}else{
			df[i]=-1;
		}
	}

	for(i=0;i<100;i++){
		int tem=check(df,i,size);

		out+=tem;
		//printf("%d\n",tem);
	}
	printf("%d",out);
}
