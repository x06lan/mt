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
	word ccd[1000];
	int len=0;
	int len2=0;
	char del[]=" ";
	int i=0,j;
	while(data[i]!=0){
		if(data[i]!=' '){
			ccd[i].s=data[i];
			len2+=1;
		}
		i++;
	}
	sp(cd,data,del,&len);
	int cdata[1000];
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
	for(i=0;i<len2;i++){
		if(ccd[i].s!=0){
			for(j=i+1;j<len2;j++){
				if(ccd[i].s==ccd[j].s){
					ccd[i].n+=1;
					ccd[j].n=-100;
				}
			}
		}
	}
	for(i=0;i<len2;i++){
		for(j=i+1;j<len2;j++){
			if(ccd[i].n<ccd[j].n){
				word tem=ccd[i];
				ccd[i]=ccd[j];
				ccd[j]=tem;
			}
		}
	}
	for(i=0;i<4;i++){
		printf("%c:%d\n",ccd[i].s,ccd[i].n);
	}
	return 0;
}
