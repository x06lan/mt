#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int v;
	struct node *r;
	struct node *l;
}node;
node *newnode(int v){
	node *tem=malloc(sizeof(tem));
	tem->v=v;
	tem->r=NULL;
	tem->r=NULL;
	return tem;
}
void pr(node *root){
	if(root->l!=NULL)pr(root->l);
	if(root)printf("%d ",root->v);
	if(root->r!=NULL)pr(root->r);
}
void append(node **root ,int v){
	if((*root)==NULL){
		(*root)=newnode(v);
	}else if (v<(*root)->v){
		if((*root)->r!=NULL)append((*root)->r,v);
		else (*root)->r=newnode(v);
	}
	else{
		if((*root)->l!=NULL)append((*root)->l,v);
		else (*root)->l=newnode(v);
	}
}

int main() {

}
