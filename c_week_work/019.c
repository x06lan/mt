#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int i,j;
	int size=0;
	char instr[100];
	for(i=0;i<100;i++)instr[i]='-';
	scanf("%s",&instr);
	scanf("%d",&size);
	int *df=malloc(sizeof(int)*size*size);
	for(i=0;i<size;i++)for(j=0;j<size;j++)*(df+i+j)=9;
	//recode(size,df);
	pri(df,size);
	
}
