#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum level{
	ap=90,
	a=85,
	as=80,
	bp=77,
	b=73,
	bs=70,
	cp=67,
	c=63,
	cs=60,
	f=0
}level;
typedef struct word{
	char * s;
}word;

int G(){
	char *a=malloc(sizeof(char)*100);
	char *match[10]={"F","C-","C","C+","B-","B","B+","A-","A","A+"};
	scanf("%s",a);
	int i;
	for(i=0;i<10;i++){
		if(strcmp(a,match[i])==0){
			return i;
		}
	}
	return -1;

}
int GPA(){
	double a;
	scanf("%lf",&a);
	double point[10]={0,1.7,2,2.3,2.7,3,3.3,3.7,4,4.3};
	int i;
	for(i=0;i<10;i++){
		if(a==point[i]){
			return i;
		}
	}
	return -1;
}
int S(){
	int a,b;
	scanf("%d-%d",&a,&b);
	int point[10]={0,60,63,67,70,73,77,80,85,90};
	int i;
	for(i=9;i>=0;i--){
		if(a>=point[i]){
			return i;
		}
	}
	return -1;
}
int compare(char*a,char *b){
	
	if(*a!=*b)return -1;
	if(*a!='\0'&&*a==*b)return compare(a+1,b+1);
	return 0;
}
int (*deal[3])(void)={G,GPA,S};
int main(){
	double value[10]={50,60,65,68,70,75,78,82,87,95};
	int n,sn;
	scanf("%d",&n);
	int intype[n];
	int i,j,k;
	for(i=0;i<n;i++){
		char str_type[100]="";
		scanf("%s",str_type);
		char *a[3]={"G","GPA","S"};
		for(j=0;j<3;j++){
			if(compare(str_type,a[j])==0){
				intype[i]=j;
				break;
			}
		}
	}
	scanf("%d",&sn);
	double sum[sn];
	int av[sn];
	word id[sn];
	for(i=0;i<sn;i++)id[i].s=malloc(sizeof(char)*100);
	memset(sum,0,sizeof(sum));
	memset(av,0,sizeof(av));
	for(i=0;i<sn;i++){
		scanf("%s",id[i].s);
		//printf("*%s\n",id[i].s);
		for(j=0;j<n;j++){
			int index=deal[intype[j]]();
			sum[i]+=value[index];
		}
		av[i]=(int)((sum[i]/n)+0.5);
	}
	int sort[sn];
	for(i=0;i<sn;i++)sort[i]=i;
	for(i=0;i<sn;i++){
		int max_id=i;
		for(j=i+1;j<sn;j++){
			if(av[sort[max_id]]<av[sort[j]]){
				max_id=j;
			}
		}
		int tem=sort[i];
		sort[i]=sort[max_id];
		sort[max_id]=tem;
	}
	for(i=0;i<3;i++){
		printf("%s\n",id[sort[i]].s);
		printf("%d\n",av[sort[i]]);
	}
	return 0;
}
