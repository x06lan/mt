#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_t{
	int v;
	struct node_t *next;
}node;
node * newnode(int v){
	node *tem=malloc(sizeof(node));
	tem->v=v;
	tem->next=NULL;
	return tem;
}
void find(node *a,int target,int v){
	node *now=a;
	while(now!=NULL){
		if(now->v==target)break;
		now=now->next;
	}
	if(now!=NULL){
		node *tem=now->next;
		now->next=newnode(v);
		now->next->next=tem;
	}
}
node *findnode(node *a,int target){
	node *now=a;
	node *last=NULL;
	while(now!=NULL){

		if(now->v==target)break;
		last=now;
		now=now->next;
	}
	if(now!=NULL &&last!=NULL)return last;
	return NULL;
}
int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	node *head;
	node *last;
	node *tem;

	for(i=0;i<n;i++){
		int vv;
		scanf("%d",&vv);
		if(i==0){
			head=newnode(vv);
			tem=head;
			last=tem;
		}
		else{
			tem->next=newnode(vv);
			last=tem;
			tem=tem->next;
			last=tem;
		}
	}
	int input;
	scanf("%d",&input);
	while(input!=6){
		if(input==1){
			int v;
			scanf("%d",&v);
			if(head ==NULL){
				last=newnode(v);
				head=last;
			}
			else{
				last->next=newnode(v);
				last=last->next;
			}
		}
		else if(input==2){
			int target,v;
			scanf("%d %d",&target,&v);
			if(head!=NULL){
				if(target!=last->v){
					find(head,target,v);
				}else{
					last->next=newnode(v);
					last=last->next;
				}
			}
		}
		else if(input==3){
			int v;
			scanf("%d",&v);
			if(head->v==v){
				tem=head->next;
				free(head);
				head=tem;
			}
			else if(last->v==v){
				tem=findnode(head,last->v);
				tem->next=NULL;
				free(last);
				last=tem;
			}
			else{
				tem=findnode(head,v);
				if(tem!=NULL){
					node *tem2=tem->next->next;
					free(tem->next);
					tem->next=tem2;
				}
			}
			
		}
		else if(input==4){
			if(head!=NULL){
				tem=head->next;
				free(head);
				head=tem;
			}
		}
		else if(input==5){
			if(head!=NULL  && last!=NULL){
				if (head->v ==last->v){
					head=NULL;
					last=NULL;
				}
				else{
					tem=findnode(head,last->v);
					if(tem!=NULL){
						tem->next=NULL;
						free(last);
						last=tem;
					}
				}
			}
		}
		scanf("%d",&input);
	}
	if(head==NULL){
		printf("None any node\n");
		return 0;
	}
	while(head!=NULL){
		if(head->next!=NULL)printf("%d ",head->v);
		else printf("%d\n",head->v);
		head=head->next;
	}

	return 0;
}

