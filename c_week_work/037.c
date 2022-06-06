#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* input(){
	char s[10000]="";
	gets(s);
	int i=0,tem=0,sign=1;
	int *out=malloc(sizeof(int)*10000); 
	*out=0;
	while(1){
		if(s[i]=='-'){
			sign=-1;
		}
		else if(s[i]==0){
			*out+=1;
			*(out+*out)=sign*tem;
			break;
		}
		else if(s[i]==' ' && s[i+1]!=0 ){
			*out+=1;
			*(out+*out)=sign*tem;
			tem=0;
			sign=1;
		}
		else if(s[i]!=' '){
			tem*=10;
			tem=tem+s[i]-'0';
		}
		
		i++;
	}
	return out;
}
typedef struct node_t{
	int pow;
	int v;
	struct node_t *next;
}node;

node *newnode(int v,int pow){
	node *tem=malloc(sizeof(node));
	tem->v=v;
	tem->pow=pow;
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
int insert_push(list *a,int v,int pow,int arg){
	node **head=&(a->h);
	node **last=&(a->l);
	if(*head==NULL){
		(*head)=newnode(v,pow);
		*last=*head;
		return 0;
	}
	else{
		if(arg==0){
			node *tem=newnode(v,pow);
			tem->next=*head;
			*head=tem;
		}
		else{
			(*last)->next=newnode(v,pow);
			*last=(*last)->next;
		}
	}
	return 0;
}
node* find(list *a,int pow){
	node *head=a->h;
	while(head!=NULL){
		if(head->pow==pow){
			return head;
		}
		head=head->next;
	}
	return NULL;
}
list* copy(list *a){
	list *b=newlist();
	node *chead=a->h;
	
	while(chead!=NULL){
		insert_push(b,chead->v,chead->pow,1);
		chead=chead->next;
	}
	return b;
}
void add(list *a,list*b,int sign){
	node *ah=a->h;
	while(ah!=NULL){
		node *tem=find(b,ah->pow);
		if(tem!=NULL)tem->v+=sign*(ah->v);
		else insert_push(b,sign*ah->v,ah->pow,1);
		ah=ah->next;
	}
}
int p_all(node *head,int tem){
	if(head->v!=0 )tem=head->pow;
	if(head->next!=NULL)tem=p_all(head->next,tem);
	if(head->v!=0 ){
		if(tem!=head->pow)printf("%c",(head->v>0)?'+':'-');
		else if(head->v<0)printf("%c",'-');

		if(abs(head->v)!=1||head->pow==0)printf("%d",abs(head->v));
		if(head->pow>1)printf("x^%d",head->pow);
		else if(head->pow==1 )printf("x");
	}else{
		if(head->pow==0 &&tem==0)printf("%d",0);
	}
	return tem;
}
void mux(list *a,list *b,list *d){
	node *ah=a->h;
	while(ah!=NULL){
		list *c=copy(b);
		node *ch=c->h;
		while(ch!=NULL){
			ch->v*=ah->v;
			ch->pow+=ah->pow;
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
		insert_push(a,*(v+1+i),*v-i-1,0);
	}
	free(v);
	v=input();
	list *b=newlist();
	for(i=0;i<*v;i++){
		insert_push(b,*(v+1+i),*v-i-1,0);
	}
	list *c=copy(b);
	list *d=copy(a);

	add(a,c,1);
	p_all(c->h,0);
	printf("\n");

	c=copy(b);
	add(c,d,-1);
	p_all(d->h,0);
	printf("\n");

	list *e=newlist();
	mux(a,b,e);
	p_all(e->h,0);
	printf("\n");
	return 0;
}

