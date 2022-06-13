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
				
				if(max==-1)min=j;
				else min=min<j?min:j;
				max=max>j?max:j;
				
			}
		}
	}
	char *ans=malloc(sizeof(char)*100);
	for (int i = 0; i < max-min; i++){
		ans[i]=b[i+min];
	}
	ans[max]='\0';
	return ans;
}
node *findpre(char *mid,char *pre,int type){
	if(mid=='\0'||pre=='\0'){
		return NULL;
	}
	node *tem;
	if(type==0)tem=newnode(*pre);
	else tem=newnode(pre[strlen(pre)-1]);

	char l[100]="",r[100]="";
	find(mid,*pre,l,r);
	char *lpre=match(l,pre);
	char *rpre=match(r,pre);
	tem->l=findpre(l,lpre,type);
	tem->r=findpre(r,rpre,type);
	return tem;
}


int main(){
	
//BCAEDGHFI
//ABCDEFGHI

	char order=' ';
	scanf("%c",&order);
	char path[100]="EDGHFI";
	char path2[100]="ABCDEFGHI";
	printf("%s\n",match(path,path2));
	//scanf("%c",path);

	return 0;
}

