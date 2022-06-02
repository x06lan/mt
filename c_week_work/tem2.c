#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


double min(double a, double b){ return (a>b)?b:a;}
double max(double a, double b){ return (a<b)?b:a;}
double recode(double *a,double *b,int c,int n){
	int i;
	//a=time b=sp
	double lim=10000000000;
	for(i=c;i<n;i++){
		if(a[i]-b[i]>0){
			lim=min(lim,a[i]-b[i]);
		}
	}
	return lim;
}
int main() {
	int n,i,j;
	scanf("%d",n);
	double time[n];
	double maxsp[n];
	for(i=0;i<n;i++){
		int tem;
		scanf("%d",&tem);
		time[i]=(double)tem;
	}
	for(i=0;i<n;i++){
		int tem;
		scanf("%d",&tem);
		maxsp[i]=(double)tem;
	}
	double sum=0;
	double nowsp=0;
	for(i=0;i<n;i++){
		double lim=1000000;
		lim=recode(time,maxsp,i,n);
		sum+=pow(nowsp-lim,2)/2.;
		sum+=
		nowsp=lim;
	}
}
