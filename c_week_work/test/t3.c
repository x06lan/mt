#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node{
	int v;
	struct node *n;
}node;

typedef struct list{
	node *h;
	node *l;
}list;
node *newnode(int v){
	node *tem=malloc(sizeof(node));
	tem->v=v;
	return tem;
}
list *newlist(){
	list *a=malloc(sizeof(list));
	a->h=NULL;
	a->l=NULL;
	return a;
}
list *revser(list *a,node *head){

}
int push(list *a,int v){
	if(a->h==NULL){
		a->h=newnode(v);
		a->l=a->h;
	}
	else{
		node *tem=newnode(v);
		a->l->n=tem;
		a->l=tem;
	}
	return 0;
}
int insert(list *a, int v){
	if(a->h==NULL){
		a->h=newnode(v);
		a->l=a->h;
	}
	else{
		node *tem=newnode(v);
		tem->n=a->h;
		a->h=tem;
	}
	return 0;
}
node *find(list *a,int v){
	node *head=a->h;
	if(head==NULL)return NULL;
	while(head!=NULL){
		if(head->n->v==v)
			return head;
		head=head->n;
	}
	return NULL;
}
int print(list *a){
	node *head=a->h;
	if(head==NULL){
		printf("None\n");
		return 0;
	}
	while(head!=NULL){
		printf("%d ",head->v);
		head=head->n;
	}
	printf("\n");
}
int main() {
	int n,i,j;
	scanf("%d",&n);
	list *a=newlist();
	for(i=0;i<n;i++){
		int v;
		scanf("%d",&v);
		push(a,v);
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int ii;
		int v;
		scanf("%d",&ii);
		if(ii==1){
			scanf("%d",&v);
			push(a,v);
		}
		else if(ii==2){
			if(a->h!=NULL){
				node *tem=a->h->n;
				free(a->h);
				a->h=tem;
			}
		}
		else if(ii==3){
			if(a->h!=NULL){
				if(a->l->v == a->h->v){
					a->l=NULL;
					a->h=NULL;
				}
				else{
				node *tem=find(a,a->l->v);
				a->l=tem;
				a->l->n=NULL;
				}
			}
		}
		else if(ii==4){
			scanf("%d",&v);
			if(v==a->h->v){
				node *tem=a->h->n;
				free(a->h);
				a->h=tem;
			}
			else{
				node *tem=find(a,v);
				if(tem!=NULL){
					tem->n=tem->n->n;
				}
			}
		}
		else if(ii==5){
			int v2;
			scanf("%d",&v);
			scanf("%d",&v2);
			node *tem=find(a,v);
			if(tem!=NULL){
				node *tem2=tem->n;
				tem->n=newnode(v2);
				tem->n->n=tem2;
			}
		}
		else if(ii==6){
		}
		else if(ii==7){
			int v2;
			scanf("%d",&v);
			scanf("%d",&v2);
			node *tem=find(a,v);
			node *tem2=find(a,v2);
			if(tem!=NULL && tem2!=NULL){
				node *tem3=tem->n;
				node *tem4=tem->n->n;
				node *tem5=tem2->n;
				node *tem6=tem2->n->n;
				tem->n=tem2->n;
				tem->n->n=tem4;
				tem2->n=tem3;
				tem2->n->n=tem6;
			}
		}
		//if(a->h!=NULL)print(a);
	}
	print(a);
	return 0;
}
