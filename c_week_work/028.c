#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct game{
	int an[10];
	int ob[10];
	int point[100];
}game;
int upbase(int a[4],int up,int save[10]){
	int i=0;
	int sum=0;
	for(i=0;i<up;i++){
		if(a[3]!=0){
			sum+=1;
			save[a[3]-1]+=1;
		}
		a[3]=a[2];
		a[2]=a[1];
		a[1]=a[0];
		a[0]=0;
	}
	return sum;
}
int main(){
	int data[9][10];
	char str[20]="";

	memset(data,-1,sizeof(data));
	int i,j,k;
	for(i=0;i<9;i++){
		fgets(str, sizeof(str), stdin);
		j=0;
		int n=str[j]-'0';
		for(j=1;j<n+1;j++){
			data[i][j-1]=str[j*2]-'0';
			if(str[j*2]=='H'){
				data[i][j-1]=4;
			}
			if(str[j*2]=='O'){
				data[i][j-1]=0;
			}
		}
	}

	int value=data[0][0];
	int base[4]={0,0,0,0};
	game d;
	memset(d.an,0,sizeof(d.an));
	memset(d.ob,0,sizeof(d.an));
	memset(d.point,0,sizeof(d.an));

	int round=0;
	int sum=0;
	int targe=0;
	scanf("%d",&targe);
	i=0;
	while(value!=-1 && targe>round){
		//printf("%d %d %d %d\n",i%9,i/9,value,sum);
		if(value==0){
			round+=1;
			if(round%3==0){
				for(j=0;j<4;j++)base[j]=0;
			}
		}else{
			d.an[i%9]+=1;
			base[0]=(i%9)+1;
			sum+=upbase(base,value,d.ob);
		}
		d.point[round]=sum;
		i+=1;
		value=data[i%9][i/9];
	}
	printf("%d\n",d.point[targe-1]);
	for(i=0;i<9;i++){
		printf("%d %d %d\n",i+1,d.an[i],d.ob[i]);
	}
	
	return 0;
}
