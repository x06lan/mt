//p1.c gcc p1.c -lpthread -o p1
// ./p1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
typedef struct data{
	int s;
	int e;
	long double v;
}data;
void thread(data *v ) {
	v->v=0.0;
	for(int i=v->s;i<= v->e;i++) {
		long double tem=2*i+1;
		long double t=1/tem;
		if(i%2==1){
			t=t*-1;
		}
		//printf("%lf\n",tem);
		//printf("%lf\n",t);
		//printf("\n");
		(v->v)+=t;
	}
}
#define thread_number 3
int main(){
	
	pthread_t id[thread_number];
	long double out=0.0;
	data v[thread_number+1]={};
	v[0].s=3;
	v[0].e=22;

	v[1].s=23;
	v[1].e=42;

	v[2].s=43;
	v[2].e=62;

	v[3].s=0;
	v[3].e=2;
	for(int i=0;i<3;i++){
		int p;
		p= pthread_create(id+i,NULL,(void *) thread,v+i);
		if(p!=0){
			printf ("Create pthread error!n");
			exit(1);
		}
		pthread_join(id[i], NULL);
		out+=v[i].v;
	}
	thread(v+3);
	//printf("%.4lf\n",out);
	//printf("%.4lf\n",v[3].v);
	printf("%.10Lf\n",(v[3].v+out)*4);


	return 0;
}
