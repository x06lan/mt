#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node{
	char v;
	struct node *r;
	struct node *l;
}node;
node *newnode(char v){
	node *tem=malloc(sizeof(node));
	tem->v=v;
	tem->r=NULL;
	tem->l=NULL;
	return tem;
}
void find(char *a,char v,char *l,char *r){
	int i;
	int f=0;
	int ai=0;
	int bi=0;
	for (int  i = 0; a[i]!=0 ; i++){
		if(a[i]==v){
			f=1;
			continue;
		}
		if(f==1)l[ai++]=a[i];
		else r[bi++]=a[i];
	}
	l[ai]=0;
	r[bi]=0;
}
void match(char *a,char *b,char *c){
	int i;
	int j;
	int max=-1;
	int min=0;
	for (int i = 0; a[i]!=0 ; i++){
		for (int j = 0; b[j]!=0 ; j++){
			if(a[i]==b[j]){
				if(max==-1)min=j;
				if(max<j)max=j;
				min=(min>j)?j:min;
			}
		}
	}
	for(i=0;i<=max-min;i++)c[i]=b[i+min];
	c[max+1]=0;
}
node *revese_bintree(char *per,char *inorde){

	node *root=newnode(per[0]);
	char *il=malloc(sizeof(char)*100);
	char *ir=malloc(sizeof(char)*100);
	char *pl=malloc(sizeof(char)*100);
	char *pr=malloc(sizeof(char)*100);
	find(inorde,root->v,il,ir);
	match(il,per,pl);
	match(ir,per,pr);
	printf("+%s,%s\n",il,ir);
	printf("-%s,%s\n",pl,pr);
	if(strlen(il)==0)root->l=NULL;
	else root->l=revese_bintree(pl,il);
	if(strlen(ir)==0)root->r=NULL;
	else root->r=revese_bintree(pr,ir);
	return root;
}
void bfs(node **root,int len){
	int i;
	node *out[1000];
	int newline=0;
	for(i=0;i<len;i++){
		node *tem=root[i];
		printf("%c",tem->v);
		if(tem->l!=NULL){
			out[newline]=tem->l;
			newline+=1;
		}
		if(tem->r!=NULL){
			out[newline]=tem->r;
			newline+=1;
		}
	}
	bfs(out,newline);
}

int main() {
	char type[100];
	char data[1000]="ABDHIEJKCFLMGNO";
	char data2[1000]="HDIBJEKALFMCNGO";
	node *root=revese_bintree(data,data2);
	bfs(&root,1);

	return 0;
	scanf("%s",type);
	scanf("%s",data);
	scanf("%s",type);
	scanf("%s",data2);
}
