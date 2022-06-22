#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define st(TYPE) char name[100];\
	int (*perf)(struct TYPE*);\
	int (*aref)(struct TYPE*);\
	int are;\
	int per;
typedef struct sq{
	int t;
	int v1;
	st(sq)
}sq;
typedef struct cc{
	int t;
	int v1;
	st(cc)
}cc;
typedef struct re{
	int t;
	int v1;
	int v2;
	st(re)
}re;
typedef struct tr{
	int t;
	int v1;
	int v2;
	int v3;
	st(tr)
}tr;

void atr(tr *a){
	scanf("%d",&(a->v1));
	scanf("%d",&(a->v2));
	scanf("%d",&(a->v3));
	int s=a->v1+a->v2+a->v3;
	s/=2;
	a->are=sqrt(s*(s-a->v1)*(s-a->v2)*(s-a->v3));
	a->per=a->v1+a->v2+a->v3;
	printf("%s %d %d\n","triangle",a->per,a->are);
}
void asq(sq *a){
	scanf("%d",&(a->v1));
	a->are=a->v1*a->v1;
	a->per=4*a->v1;
	printf("%s %d %d\n","square",a->per,a->are);
}
void acc(cc *a){
	scanf("%d",&(a->v1));
	a->are=a->v1*a->v1*4;
	a->per=a->v1*4*2;
	printf("%s %d %d\n","circle",a->per,a->are);
}
void are(re *a){
	scanf("%d",&(a->v1));
	scanf("%d",&(a->v2));
	a->are=a->v1*a->v2;
	a->per=a->v1*2+a->v2*2;
	printf("%s %d %d\n","rectangle",a->per,a->are);
}


int *newall(){
	char t[100]="";
	int *out=malloc(sizeof(int)*2);
	scanf("%s",t);
	if(*t=='t'){
		tr *tem=malloc(sizeof(tr));
		atr(tem);
		*out=tem->are;
		*(out+1)=tem->per;
	return out;
	}
	else if(*t=='s'){
		sq *tem=malloc(sizeof(sq));
		asq(tem);
		*out=tem->are;
		*(out+1)=tem->per;
	return out;
	}
	else if(*t=='c'){
		cc *tem=malloc(sizeof(cc));
		acc(tem);
		*out=tem->are;
		*(out+1)=tem->per;
	return out;
	}
	else if(*t=='r'){
		re *tem=malloc(sizeof(re));
		are(tem);
		*out=tem->are;
		*(out+1)=tem->per;
	return out;
	}
}


int main() {
	int n;
	int i;
	scanf("%d",&n);
	int aarea=0;
	int aper=0;
	for(i=0;i<n;i++){
		int *tem=newall();
		aarea+=(*tem);
		aper+=*(tem+1);
	}
	printf("%d %d\n",aper,aarea);
	return 0;
}
