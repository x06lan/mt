#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ShapeText(TYPE) char name[10];\
double (*perimeter)(struct TYPE*);\
double (*area)(struct TYPE*)

#define pi 3.14

typedef struct circle_s {
	ShapeText(circle_s);
	double radius;
} circle_t;

typedef struct rr{
	ShapeText(rr);
	double edge[2];
} rr;
typedef struct ss{
	ShapeText(rr);
	double edge;
} ss;
typedef struct tri{
	ShapeText(tri);
	double edge[3];
} tri;

void c(double *a,double *p,char t[100]){
	double r;
	scanf("%lf",&r);
	printf("%.2lf %.2lf\n",r*2*pi,r*r*pi);
	(*p)+=r*2*pi;
	(*a)+=r*r*pi;
}
void r(double *a,double *p,char t[100]){
	double h,w;
	scanf("%lf %lf",&h,&w);
	printf("%.2lf %.2lf\n",h*2+w*2,h*w);
	(*p)+=h*2+w*2;
	(*a)+=h*w;
}

void s(double *a,double *p,char t[100]){
	double h,w;
	scanf("%lf",&h);
	printf("%.2lf %.2lf\n",h*4,h*h);
	(*p)+=h*4;
	(*a)+=h*h;
}
void t(double *a,double *p,char t[100]){
	double h,w,r,s;
	scanf("%lf %lf %lf",&h,&w,&r);
	s=(h+w+r)/2;
	s=sqrt(s*(s-h)*(s-w)*(s-r));
	printf("%.2lf %.2lf\n",h+w+r,s);
	(*p)+=h+w+r;
	(*a)+=s;
}
int main (){
	int n;
	scanf("%d",&n);
	int i;
	double a=0,p=0;
	for(i=0;i<n;i++){
		char tem[100]="";
		scanf("%s",tem);
		if((*tem)=='C'){
			c(&a,&p,tem);
		}
		else if((*tem)=='R'){
			r(&a,&p,tem);
		}
		else if(*tem=='S'){
			s(&a,&p,tem);
		}
		else if(*tem=='T'){
			t(&a,&p,tem);
		}
	}
	printf("%.2lf %.2lf",p,a);
}
