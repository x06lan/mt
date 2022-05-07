#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int brs(char a){
	return (a>96)?1:0;
}
int max(int a,int b){
	if(a>b)return a;
	return b;
}
int recode(char *a,int n){
	int len=strlen(a);
	int i,j,k;
	int time=0;
	int last_count=1;
	int last;
	for(i=0;i<len;i++){
		int now=brs(*(a+i));
		if(i!=0){
			if(now==last){
				last_count+=1;
			}
			if(now!=last || i==len-1){
				if(last_count>=n)time+=1;
				if(last_count==n){
					last_count=1;
				}
				else{
					break;
				}
			}
		}
		last=brs(*(a+i));
	}
	if(len==1)return 0;
	return max(time,recode(a+1,n));
	
}
int main(){
	int n;
	char *a=malloc(sizeof(char)*1000);
	scanf("%d",&n);
	scanf("%s",a);
	int i=0;
	int out=recode(a,n);

	printf("%d\n",out*n);
	return 0;
	printf("\n");
	for(i=0;i<strlen(a);i++){
		printf("%d",brs(*(a+i)));
	}
}
