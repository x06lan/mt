#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 200
typedef struct work{
	int number;
	int time[size];
	int mc[size];
	int now;
	int last;
}work;

typedef struct machine{
	int time;
}machine;

int max(int a,int b){
	return (a>b)?a:b;
}
int dowork(machine w[],work task[],int m, int n, int time){
	int i,j,k;
	int t_id=-1;
	for(i=0;i<n;i++){
		int now=task[i].now;
		int w_id=task[i].mc[task[i].now];
		int ntime=task[i].time[now];

		if( now <task[i].number){
			if(t_id==-1){
				t_id=i;
			}else{
				int tnow=task[t_id].now;
				int tw_id=task[t_id].mc[task[t_id].now];
				int ttime=task[t_id].time[tnow];
				if(max(w[tw_id].time,task[t_id].last)+ttime>max(w[w_id].time,task[i].last)+ntime){
					t_id=i;
				}
			}
		}
	}
	if(t_id==-1){
		int out=0;
		for(i=0;i<n;i++){
			out+=task[i].last;
		}
		return out;
	}else{
		int tnow=task[t_id].now;
		int tw_id=task[t_id].mc[task[t_id].now];
		int ttime=task[t_id].time[tnow];
		w[tw_id].time=max(w[tw_id].time,task[t_id].last)+ttime;
		task[t_id].last=w[tw_id].time;
		task[t_id].now+=1;
		return dowork(w,task,m,n,0);
	}
}
int main(){
	int i,j;
	int n,m;
	scanf("%d",&m);
	scanf("%d",&n);
	machine w[m];
	work task[100];
	for(i=0;i<n;i++){task[i].last=0;}
	for(i=0;i<n;i++){
		int nx;
		scanf("%d",&nx);
		w[i].time=0;
		task[i].now=0;
		task[i].last=0;
		task[i].number=nx;
		for(j=0;j<nx;j++){
			int mach,time;
			scanf("%d %d",&mach,&time);
			task[i].mc[j]=mach;
			task[i].time[j]=time;
		}
	}
	int out =dowork(w,task,m,n,0);
	printf("%d",out);

	return 0;
}
