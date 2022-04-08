#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rec(int *a,int x, int y, int *bin,int size,int *count,char *str){
	char nowtext=str[*count];
	int i,j;
	int sign=nowtext-'0';
	//printf("%d %d %d %d\n",x,y,*bin,sign);
	if(sign==2){
		(*bin)/=2;
		*count=*count+1;
		rec(a,x,y,bin,size,count,str);
		*count=*count+1;
		rec(a,x+*bin,y,bin,size,count,str);
		*count=*count+1;
		rec(a,x,y+*bin,bin,size,count,str);
		*count=*count+1;
		rec(a,x+*bin,y+*bin,bin,size,count,str);
		(*bin)*=2;
		
	}
	else if(sign==1){
		//printf("+%d %d %d %d\n",x,y,*bin,sign);
		for(i=y;i<y+*bin;i++){
			for(j=x;j<x+*bin;j++){
				*(a+i*size+j)=sign;
			}
		}
	}
}
int main() {
	int i,j;
	int size=0;
	char instr[1000];
	for(i=0;i<100;i++)instr[i]='-';
	scanf("%s",&instr);
	scanf("%d",&size);
	int bin=size;
	int *df=malloc(sizeof(int)*size*size);
	for(i=0;i<size*size;i++)*(df+i)=0;
	i=0;
	rec(df,0,0,&bin,size,&i,instr);
	for(i=0;i<size*size;i++)if(*(df+i)==1)printf("%d,%d\n",i/size,i%size);
	bin=0;
	for(i=0;i<size*size;i++)if(*(df+i)==1)bin=1;
	if(bin==0)printf("all white");
}
