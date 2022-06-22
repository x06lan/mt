#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node{
	int time;
	int id;
	int *req;
	int len;
	int breq;

}node;
int max(int a,int b){return a>b?a:b;}

int recode(node nodev,node data[]){
	if(nodev.len==0){
		return nodev.time;
	}
	else{
		int i;
		int maxv=0;
		for(i=0;i<nodev.len;i++){
			maxv=max(maxv,recode(data[nodev.req[i]],data));
		}
		return maxv+nodev.time;
	}
}

int main() {
	node data[10000];
	memset(data,0,sizeof(data));
	int n,i,j;
	int out=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&data[i].time);
		int len=0;
		scanf("%d",&len);
		data[i].len=len;
		data[i].req=malloc(sizeof(int)*len);
		for (j = 0; j <len ; j++){
			int v;
			scanf("%d",&v);
			v-=1;
			data[i].req[j]=v;
			data[v].breq=1;
		}
	}
	for (int  i = 0; i < n; i++){
		if(data[i].breq==0){
			out=max(out,recode(data[i],data));
		}
	}
	printf("%d",out);
	
	return 0;
}
