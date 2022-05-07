#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double f1(double x,double a){
	double tem=a-x*x;
	tem=pow(tem,0.5L);
	return fabs(tem);

}
double f2(double x,double a){
	double tem=(a*x*x*x+7.0L*x)/pow(a+x,0.5L);
	return fabs(tem);

}
double (*farr[2])(double,double)={f1,f2};
double t(double (*fun)(double ,double),double a,double p,double q,int n){
	double out=0.0;
	double up=(q-p)/n;
	double d=2.0;
	int i;
	for(i=0;i<n+1;i++){
		double tem=fun(p+i*up,a);
		if(i!=0&&i!=n)tem*=2.0L;
		out+=tem;
	}
	return out/2.0L*up;
}
int input(){
	int intype=0;
	int i,j;
	double p,q,a,err;
	long long int n=1;
	scanf("%d",&intype);
	if(intype==0)return 0;
	scanf("%lf%lf%lf%lf",&a,&p,&q,&err);
	double last=0.0;
	double now=0.0;
	while(1){
		now=t(farr[intype-1],a,p,q,n);
		if(n!=1){
			if(fabs(now-last)<pow(0.1,err)){
				printf("%.12lf\n",now);
				break;
			}
		}
		n=n<<1;
		last=now;
	}
	input();

}
int main(){
	input();
	return 0;
}

