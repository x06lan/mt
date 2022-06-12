#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_t{
	char v;
	struct node_t *r;
	struct node_t *l;
	struct node_t *f;
}node;

node *newnode(char v){
	node *tem=malloc(sizeof(node));
	tem->r=NULL;
	tem->l=NULL;
	tem->f=NULL;
	tem->v=v;
	return tem;
}
char *find(char *str,char targe,char *l,char *r){
	int i,j;
	int ai=0,bi=0;
	int flat=0;
	for(i=0;str[i]!='\0';i++){
		if(str[i]==targe){
			flat =1;
			continue;
		}
		if(flat==0){
			l[ai]=str[i];
			ai++;
		}
		else{
			r[bi]=str[i];
			bi++;
		}
	}
	l[ai]='\0';
	r[bi]='\0';
}
char *match(char *a,char *b ){
	int i,j;
	int max=-1;
	int min=-1;
	for(i=0;a[i]!='\0';i++){
		for(j=0;b[j]!='\0';j++){
			if(a[i]==b[j]){
				max=max>j?max:j;
				if(max=-1)min=j;
				else min=min<j?min:j;
			}
		}
	}
	char ans[100]="";
	for (int i = 0; i < max-min; i++){
		ans[i+min]=a[i];
	}
	ans[max]='\0';
	return ans;
}
node *findpre(char *mid,char *pre){
	if(mid=='\0'||pre=='\0'){
		return NULL;
	}
	node *tem=newnode(*pre);
	char l[100]="",r[100]="";
	find(mid,*pre,l,r);
	

	return tem;
}




int main(){
	char order=' ';
	scanf("%c",&order);
	char *path="";
	scanf("%c",path);

	return 0;
}

