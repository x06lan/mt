#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define big 100
//lanx
typedef struct link{

	char *str;
	struct link *next;
}link;

void push(link *node,char *v){

	link a;
	a.str=malloc(sizeof(char)*100);
	a.str="";
	a.str=v;
	node->next=&a;
}
void split(char **arr, char *str, char *del) {
	char *s = strtok(str, del);
	while(s != NULL) {
	*arr++ = s;
	s = strtok(NULL, del);
	}
}
int main() {
	char *str="";
	scanf("%s",&str);
	memset(str,0,sizeof(char)*100*3);
	int n,i;
	scanf("%d",n);
	char *strn="";
	int data[n][100];
	memset(str,0,sizeof(data));

	for(i=0;i<n;i++){
		scanf("%s",&strn);
		
	}


	return 0;
}
