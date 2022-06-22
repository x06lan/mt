#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct word {
	char *s;
	int n;	
}word;
void sp(word word[100],char *str,char *ma,int *len){
	char *token;
	token=strtok(str,ma);

	while(token!=NULL){
		word[*len].s=token;
		word[*len].n=1;
		(*len)+=1;
		token=strtok(NULL,ma);
	}
}


int main() {
	char data[1000]="can you can a can can as a canner can can a can";
	word cd[100];
	int len=0;
	int len2=0;
	char del[]=" ";
	int i=0,j;
	char s1[1000];
	scanf("%s",s1);
	char s2[1000];
	scanf("%s",s2);
	sp(cd,data,del,&len);
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if(strcmp(cd[i].s,cd[j].s)==0){
				cd[i].n+=1;
				cd[j].n=-100;
			}
		}
	}
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if(cd[i].n<cd[j].n){
				word tem=cd[i];
				cd[i]=cd[j];
				cd[j]=tem;
			}
		}
	}
	for(i=0;i<2;i++){
		printf("%s %d\n",cd[i].s,cd[i].n);
	}
	return 0;
}
