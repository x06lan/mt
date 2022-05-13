#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 111
typedef struct work{
	int id;
	int time;
	int req_n;
	int *req;
	int bereq_n;
	int *bereq;
}work;
void init(work *a){
	a->id=0;
	a->time=0;
	a->req_n=0;
	a->req=malloc(sizeof(int)*size);
	memset(a->req,-1,sizeof(a->req));
	a->bereq_n=0;
	//a->bereq=malloc(sizeof(int)*size);
	//memset(a->bereq,-1,sizeof(a->req));
}
int recode(work d[size],work a){
	int max=0;
	int i;
	if(a.req_n!=0){
		for(i=0;i<a.req_n;i++){
			int id=*(a.req+i)-1;
			//printf("@%d %d %d\n",a.id,id,a.time);
			int take_time=recode(d,d[id]);
			if(take_time >max){
				max=take_time;
			}
		}
	}
	return a.time+max;
}
int work_time(work a[size],int n){
	int i,j,k;
	int max=0;
	for(i=0;i<n;i++){
		if(a[i].bereq_n==0){
			int tem=a[i].time;
			if(a[i].req_n!=0){
				tem=recode(a,a[i]);
			}
			if(tem>max){
				max=tem;
			}
		}
	}
	return max;
}
int main(){
	int n;
	scanf("%d",&n);
	int i,j,k,l;
	int xn;
	for(i=0;i<n;i++){
		scanf("%d",&xn);
		work data[size];
		for(j=0;j<xn;j++){
			int time;
			int yn;
			scanf("%d",&time);
			scanf("%d",&yn);
			init(&data[j]);
			data[j].id=j;
			data[j].time=time;
			data[j].req_n=yn;
			for(k=0;k<yn;k++){
				int id;
				scanf("%d",&id);
				*((data[j].req)+k)=id;
				//*(data[id].bereq+data[id].bereq_n)=j;
				data[id].bereq_n+=1;
			}
		}
		printf("%d\n",work_time(data,xn));
	}
	return 0;
}
