#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 111
typedef struct work{
	int number;
	int time[size];
	int mc[size];
	int now;
}work;

typedef struct machine{
	int time;
	int task[size];
}machine;


int main(){
	int i,j;
	int n,m;
	scanf("%d",&m);
	scanf("%d",&n);
	machine w[m];
	work task[n];
	for(i=0;i<n;i++){
		int nx;
		scanf("%d",&nx);
		w[i].time=0;
		memset(w[i].task,-1,sizeof(w[i].task));
		task[i].now=-1;
		for(j=0;j<nx;j++){
			int mach,time;
			scanf("%d %d",&mach,&time);
			task[i].mc[j]=mach;
			task[i].time[j]=time;
		}
	}

	
	return 0;
}
