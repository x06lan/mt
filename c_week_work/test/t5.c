#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node{
	int v;
	int level;
	struct node *n;
}node;

typedef struct list{
	node *h;
	node *l;
}list;
node *newnode(int level,int v){
	node *tem=malloc(sizeof(node));
	tem->v=v;
	tem->level=level;
	return tem;
}
list *newlist(){
	list *a=malloc(sizeof(list));
	a->h=NULL;
	a->l=NULL;
	return a;
}
int push(list *a,int level, int v){
	if(a->h==NULL){
		a->h=newnode(level,v);
		a->l=a->h;
	}
	else{
		node *tem=newnode(level,v);
		a->l->n=tem;
		a->l=tem;
	}
	return 0;
}
list *copy(list *a){
	node *head=a->h;	
	list *tem=newlist();
	while(head!=NULL){
		push(tem,head->level,head->v);
		head=head->n;
	}
	return tem;
}
void input(list *l){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int tem;
		scanf("%d",&tem);;
		if(i==0){
			l->h=newnode(n-1,tem);
			l->l=l->h;
		}
		else{
			node *nn=newnode(n-i-1,tem);
			nn->n=l->h;
			l->h=nn;
		}
	}
}

void print(node *a){
	if(a!=NULL){
		print(a->n);
		printf("%d %d ",a->v,a->level);
	};
}
void add(list *a,list *b){
	node *na=a->h;
	list *c=copy(b);
	while(na!=NULL){
		node *nb=b->h;
		int find=0;
		while(nb!=NULL){
			if(na->level==nb->level){
				nb->v+=na->v;
				find=1;
				break;
			}
			nb=nb->n;
		}
		if(find==0)push(b,na->level,na->v);
		na=na->n;
	}
}
void sub(list *a,list *b){
	node *na=a->h;
	list *c=copy(b);
	while(na!=NULL){
		node *nb=b->h;
		int find=0;
		while(nb!=NULL){
			if(na->level==nb->level){
				nb->v-=na->v;
				find=1;
				break;
			}
			nb=nb->n;
		}
		if(find==0)push(b,na->level,-na->v);
		na=na->n;
	}
}
list* mux(list *a,list *b){
	node *na=a->h;
	list *d=newlist();
	while(na!=NULL){
		list *c=copy(b);
		node*nb=c->h;
		while(nb!=NULL){
			nb->level+=na->level;
			nb->v*=na->v;
			nb=nb->n;
		}
		add(c,d);
		na=na->n;
	}
	return d;
}

int main() {
	int n;
	list *a=newlist();
	input(a);
	list *b=newlist();
	input(b);
	list *c=copy(b);
	list *d=copy(a);
	add(a,c);
	print(c->h);
	printf("\n");

	sub(b,d);
	print(d->h);
	printf("\n");

	c =mux(a,b);
	print(c->h);
	return 0;
}
