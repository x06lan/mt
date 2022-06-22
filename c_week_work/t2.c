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
	char a[1000];
	gets(a);
	int i=0;
	int sign=1;
	int v=0;
	int len=0;
	int data[1000];
	for(i=0;a[i]!=0;i++){
		if(a[i]=='-')sign=-1;
		if(a[i]-'0'>=0&&a[i]-'0'<10){
			v*=10;
			v+=a[i]-'0';
		}
		if(a[i]==' '||a[i+1]==0){
			data[len]=sign*v;
			sign=1;
			v=0;
			len+=1;
		}
	}
	for(i=0;i<len;i++){
		push(l,i,data[len-i-1]);
	}
}

void print(node *a){
	if(a!=NULL){
		print(a->n);
		if(a->v!=0)printf("%d %d ",a->v,a->level);
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
	list *a=newlist();
	input(a);
	list *b=newlist();
	input(b);
	list *c=copy(b);
	add(a,c);
	print(c->h);
	printf("\n");
	c =mux(a,b);
	print(c->h);
	return 0;
}
