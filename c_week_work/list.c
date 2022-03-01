#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    struct node *init_node;
    int len;
}list;

typedef struct node {
    int value;
    int index;
    struct node *last;
    struct node *next;
}node;


node *create_node(int index,int setvalue){
    node *head = malloc(sizeof(node));
    head->value = setvalue;
    head->index=index;
    head->last = NULL;
    head->next = NULL;
    return head;
}
list *create_list(int len,int arr[]){
    list *new_list=malloc(sizeof(list));
    node *tem;
    new_list->len=len;
    int i=0;
    for(i=0;i<len;i++){
        node *new_node=create_node(i,arr[i]);
        if (i==0){
            new_list->init_node=new_node;
            tem=new_node;
        }
        else{
            tem->next=new_node;
            tem=new_node;
        }
    }
    return new_list;
}

void print_list(list *init_list){
    node *last_node=init_list->init_node;
    while (last_node!=NULL)
    {
        printf("%d\n",last_node->value);
        last_node=last_node->next;
    }
    printf("\n");

}

int get_value(list *link_list,int index){
    node *head=link_list->init_node;
    while (head->index<index )
    {
        head=head->next;
    }
    if(head->index==index){
        return head->value;
    }
    return 0; 
}
void set_value(list *link_list,int index,int value){
    node *head=link_list->init_node;
    while (head->index<index )
    {
        head=head->next;
    }
    if(head->index==index){
        head->value=value;
    }
}
void push(list *link_list,int value){
	node *next_node=link_list->init_node;
	while(next_node->next!=NULL){
		next_node=next_node->next;
	}
	next_node->next=create_node(link_list->len,value);
}
// void push(list *link_list,int )

int main() {
    int tem[4]={1,3,5,7};
    list *new_list=create_list(4,tem);
    print_list(new_list);
    //int test=get_value(new_list,0);
	push(new_list,5);
    print_list(new_list);

    return 0;
}
