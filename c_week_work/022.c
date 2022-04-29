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
int compare(char *a,char *b,int i){

	if(*(a+i)=='\0'&&*(b+i)=='\0')return 0;
	if(*(a+i)<*(b+i))return 1;
	if(*(a+i)>*(b+i))return -1;
	return compare(a,b,i+1);
}
int main() {
	char str[1000]="";
	char str1[1000]="";
	char str2[1000]="";

	gets(str);
	scanf("%s",&str1);
	scanf("%s",&str2);
	int n=0,i=0,j=0,k=0;
	char *del=" ";
	char *con1[100];
	memset(con1,'\0',sizeof(con1));
	int len=0;
	sp(con1,str,del,&len);
	int data[len];
	int sort[len];
	for(i=0;i<len;i++){
		data[i]=1;
		if(strcmp(*(con1+i),str1)==0){
			printf("%s",str2);
		}
		else{
			printf("%s",*(con1+i));
		}
		if(i!=len-1)printf(" ");
	}
	printf("\n");
	for(i=0;i<len;i++){
		if(strcmp(*(con1+i),str1)==0){
			printf("%s ",str2);
			printf("%s",*(con1+i));
		}
		else{
			printf("%s",*(con1+i));
		}
		if(i!=len-1)printf(" ");
	}
	printf("\n");
	for(i=0;i<len;i++){
		if(strcmp(*(con1+i),str1)!=0){
			printf("%s",*(con1+i));
			if(i!=len-1)printf(" ");
		}
	}
	printf("\n");
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			//printf("%s %s\n",*(con1+i),*(con1+j));
			char *tems=*(con1+i);
			char *tems1=*(con1+j);
			if(strlen(tems)==strlen(tems1)){
				if(compare(tems,tems1,0)==0){
					//printf("%s %s\n",tems,tems1);
					data[i]+=1;
					data[j]=-100;
				}
			}
		}
	}
	for(i=0;i<len;i++)sort[i]=i;
	for(i=0;i<len;i++){
		int max=i;
		for(j=i+1;j<len;j++){
			int tem=sort[j];
			int tem1=sort[max];
			char *tems=*(con1+tem);
			char *tems1=*(con1+tem1);
			if(data[tem]>=data[tem1]){
				if(data[tem]==data[tem1]){
					if(strlen(tems)<=strlen(tems1)){
						if(strlen(tems)==strlen(tems1)){
							if(compare(tems,tems1,0)>0){
								max=j;
							}
						}
						else{
							max=j;
						}
					}
				}
				else{
					max=j;
				}
			}
		}
		int tem=sort[max];
		sort[max]=sort[i];
		sort[i]=tem;
	}
	for(i=0;i<len;i++){
		if(data[sort[i]]>0)printf("%s %d\n",*(con1+sort[i]),data[sort[i]]);
	}

	return 0;
}
