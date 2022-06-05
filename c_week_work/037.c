#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* input(){
	char s[10000]="";
	gets(s);
	int i=0,tem=0,level=10,sign=1;
	int *out=malloc(sizeof(int)*10000); 
	*out=0;
	while(s[i]!=0){
		if(s[i]=='-'){
			sign=-1;
		}
		else if(s[i]==' '){
			*out+=1;
			*(out+*out)=sign*tem;
			tem=0;
			level=10;
			sign=1;
		}
		else{
			tem*=level;
			tem=tem+s[i]-'0';
			level=10;
		}
		i++;
	}
	*out+=1;
	*(out+*out)=sign*tem;
	return out;
}
typedef struct node_t{
	int level;
	int v;
	struct node_t *next;
}node;

node *newnode(int v,int level){
	node *tem=malloc(sizeof(node));
	tem->v=v;
	tem->level=level;
	tem->next=NULL;
	return tem;
}
typedef struct  list {
	node *h;
	node *l;
}list;

list *newlist(){
	list *a=malloc(sizeof(list));
	a->h=NULL;
	a->l=NULL;
	return a;
}
int insert(list *a,int v,int level,int arg){
	node **head=&(a->h);
	node **last=&(a->l);
	if(*head==NULL){
		(*head)=newnode(v,level);
		*last=*head;
		return 0;
	}
	else{
		if(arg==0){
			node *tem=newnode(v,level);
			tem->next=*head;
			*head=tem;
		}
		else{
			(*last)->next=newnode(v,level);
			*last=(*last)->next;
		}
	}
	return 0;
}
node* find(list *a,int level){
	node *head=a->h;
	while(head!=NULL){
		if(head->level==level){
			return head;
		}
		head=head->next;
	}
	if(head==NULL)return NULL;
}
list* copy(list *a){
	list *b=newlist();
	node *chead=a->h;
	
	while(chead!=NULL){
		insert(b,chead->v,chead->level,1);
		chead=chead->next;
	}
	return b;
}
void add(list *a,list*b,int sign){
	node *ah=a->h;
	while(ah!=NULL){
		node *tem=find(b,ah->level);
		if(tem!=NULL)tem->v+=sign*(ah->v);
		else insert(b,sign*ah->v,ah->level,1);
		ah=ah->next;
	}
}
void p_all(node *head,int *tem){
	if(head->v!=0 )*tem=head->level;
	if(head->next!=NULL)p_all(head->next,tem);
	if(head->v!=0 ){
		if(*tem!=head->level){
			printf("%c",(head->v>0)?'+':'-');
		}
		else {
			if(head->v<0){
				printf("%c",'-');
			}
		}
		if(abs(head->v)!=1||head->level==0){
			printf("%d",abs(head->v));
		}
		if(head->level>1){
			printf("x^%d",head->level);
		}
		else if(head->level==1 ){
			printf("x",abs(head->v));
		}
	}else{
		if(head->level==0 &&*tem==0){
			*tem=0;
			printf("%d",0);

		}
	}
}
void mux(list *a,list *b,list *d){
	node *ah=a->h;
	while(ah!=NULL){
		list *c=copy(b);
		node *ch=c->h;
		while(ch!=NULL){
			ch->v*=ah->v;
			ch->level+=ah->level;
			ch=ch->next;
		}
		add(c,d,1);
		ah=ah->next;
	}
}
int main(){
	int i;
	int *v=input();
	list *a=newlist();
	for(i=0;i<*v;i++){
		insert(a,*(v+1+i),*v-i-1,0);
	}
	int *v1=input();
	int tem;
	list *b=newlist();
	for(i=0;i<*v1;i++){
		insert(b,*(v1+1+i),*v1-i-1,0);
	}
	list *c=copy(b);
	list *d=copy(a);

	add(a,c,1);
	p_all(c->h,&tem);
	free(c);
	tem=0;
	printf("\n");

	c=copy(b);
	add(c,d,-1);
	p_all(d->h,&tem);
	free(c);
	free(d);
	tem=0;
	printf("\n");

	list *e=newlist();
	mux(a,b,e);
	p_all(e->h,&tem);
	tem=0;
	free(v);
	free(v1);
	free(e);
	return 0;
}

