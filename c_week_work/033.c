#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define all_tr(TYPE) void(*f)(struct TYPE*)
typedef struct tran{
	double time;
	int dis;
	int price;
	int nowp;

	int car_oil;
	int pass;
	int stop;
	
	int take;

	int stay;
	int extra;
	
	int s_oil;
	char *s;
	all_tr(tran);
}tran;
void car(tran *a){
	double time=(double)a->dis/100.0;
	int ever100=(int)(a->dis/100);
	ever100+=(a->dis%100==0)?0:1;
	int p=ever100*(a->car_oil*10+a->pass);
	p+=a->stop;
	if(a->price>=p &&(a->time>time|| a->nowp==-1)){
		a->time=time;
		a->s="Car";
		a->nowp=p;
	}
}
void bike(tran *a){
	double time=a->dis/20.0;
	int p=a->take;
	if(a->price>=p &&(a->time>time|| a->nowp==-1)){
		a->time=time;
		a->s="Bike";
		a->nowp=p;
	}
}
void bus(tran *a){
	double time=a->dis/75.0;
	int p=a->stay;
	int over50=(a->dis-100)/50;
	over50+=(a->dis%50==0)?0:1;
	if(a->dis>100){
		p+=over50*a->extra;
	}
	if(a->price>=p &&(a->time>time|| a->nowp==-1)){
		a->time=time;
		a->s="Intercity Bus";
		a->nowp=p;
	}
}
void sc(tran *a){
	double time=a->dis/50.0;
	int over100=(a->dis)/100;
	over100+=(a->dis%100==0)?0:1;
	int p=over100*4*a->s_oil;
	if(a->price>=p &&(a->time>time|| a->nowp==-1)){
		a->time=time;
		a->s="Scooter";
		a->nowp=p;
	}
}
void (*farr[4])(tran *)={car,bike,bus,sc};
int main(){
	tran a;
	a.time=-1;
	a.nowp=-1;
	a.s="No Transportation";

	scanf("%d %d",&(a.dis),&(a.price));
	scanf("%d %d %d",&(a.car_oil),&(a.stop),&(a.pass));
	scanf("%d",&(a.take));
	scanf("%d %d",&(a.stay),&(a.extra));
	scanf("%d",&(a.s_oil));
	int i;
	for(i=0;i<4;i++){
		farr[i](&a);
	}
	printf("%s\n",a.s);
	if(a.time!=-1){
		printf("%d\n",a.nowp);
		printf("%.2lf\n",a.time);
	}

	return 0;
}

