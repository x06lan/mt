#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t{
	char *s;
	int *data;
	struct node_t *next;
}node;

void push(node **head,node **last){
	int *data=malloc(sizeof(int)*4);
	char *s=malloc(sizeof(char)*100);
	scanf("%s %d %d %d %d",s,data,data+1,data+2,data+3);
	node *tem=malloc(sizeof(node));
	tem->data=data;
	tem->s=s;
	tem->next=NULL;
	//printf("@%s\n",tem->s);

	//if(*last!=NULL)printf("@%s\n",(*last)->s);
	//else printf("NULL\n");
	if( *head==NULL||*last==NULL)
	{
		*head=tem;
		*last=tem;
	}
	else{
		(*last)->next=tem;
		*last=(*last)->next;
	}
}
int pop(node **head,node **last,int arg){
	int type=0;
	if(arg==0){scanf("%d",&type);}
	if(*head==NULL){
		(*head)=NULL;
		(*last)=NULL;
		if(arg!=3)printf("The Queue is empty\n");
		return 0;
	}
	if(arg==1 ||arg ==2){
		printf("%s ",(*head)->s);
		printf("%d ",*((*head)->data));
		printf("%d_",*((*head)->data+1));
		printf("%d_",*((*head)->data+2));
		printf("%d\n",*((*head)->data+3));
	}
	if(type==1){
		printf("%s\n",(*head)->s);
	}
	else if(type==2){
		printf("%d\n",*((*head)->data));
	}
	else if(type==3){
		printf("%d_",*((*head)->data+1));
		printf("%d_",*((*head)->data+2));
		printf("%d\n",*((*head)->data+3));
	}
	if(arg!=2){
		node *tem=(*head)->next;
		free((*head));
		*head=tem;

	}
	return 0;
}
int main(){
	int type;
	scanf("%d",&type);
	
	node *head=NULL;
	node *last=NULL;
	while(type!=5){
		if(type==1){
			push(&head,&last);
		}
		else if(type==2){
			pop(&head,&last,0);
		}
		else if(type==3){
			if(head==NULL){
				pop(&head,&last,1);
			}
			else{
				while(head!=NULL){
					pop(&head,&last,1);
				}
			}
		}
		else if(type==4){
			if(head==NULL){
				pop(&head,&last,2);
			}
			else{
				node *tem2=head;
				while(tem2!=NULL){
					pop(&tem2,&last,2);
					tem2=tem2->next;
				}
			}
		}
		else if(type==5){
			break;
		}
		scanf("%d",&type);
	}
	int number=0;
	while(head!=NULL){
		pop(&head,&last,3);
		number+=1;
	}
	printf("%d\n",number);
	return 0;
}

