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

int main(){
	char order=' ';
	scanf("%c",&order);
	char *path="";
	scanf("%c",path);

	return 0;
}

