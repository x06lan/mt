#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void sp(char **save,char *str,char *ma,int *len){
	char *token;
	token=strtok(str,ma);
	
	while(token!=NULL){
		(*len)+=1;
		*save=token;
		save+=1;
		token=strtok(NULL,ma);
	}
}
int main() {
	char str[100]="";
	char str1[100]="";

	gets(str);

	int n=0,i=0,j=0,k=0;
	scanf("%d",&n);
	char *del=" ";
	char *con1[100];
	char *con2[100];
	memset(con1,'\0',sizeof(con1));
	memset(con2,'\0',sizeof(con2));
	int len=0;
	int tem=0;
	int out=0;
	sp(con1,str,del,&len);
	int data[n][len];
	memset(data,0,sizeof(data));
	gets(str1);
	for(i=0;i<n;i++){
		if(i==-1)continue;
		tem=0;
		gets(str1);
		memset(con2,'\0',sizeof(con2));
		sp(con2,str1,del,&tem);

		for(j=0;j<tem;j++){
			for(k=0;k<len;k++){
				if(strcmp(*(con2+j),*(con1+k))==0 ){
					data[i][k]=1;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			int mark=0;
			for(k=0;k<len;k++){
				if(data[i][k]==0&&data[j][k]==0)mark=1;
				if(data[i][k]==1&&data[j][k]==1)mark=1;
			}
			if(mark==0){
				out+=1;
			}
			mark=0;
		}
	}
	printf("%d",out);
	return 0;
}
