#include <stdio.h>
#include <stdlib.h>
int upbase(int base[4],int up){
	int point=0;
	int i=0;
	for(i=0;i<up;i++){
		if(base[3]!=0){
			point+=1;
		}
		base[3]=base[2];
		base[2]=base[1];
		base[1]=base[0];
		base[0]=0;
	}
	return point;
}
int main(){
	char str_i[60]="";
	int data[9][20];
	int point[9]={0};
	int base[4]={0};
	int i,j;
	for(i=0;i<9;i++)for(j=0;j<20;j++)data[i][j]=-1;
	for(i=0;i<9;i++){
		scanf("%[^\n]%*c", &str_i);
		for(j=2;j<40;j+=2){
			int tem=str_i[j]-'0';
			if(str_i[j]=='H'){
				data[i][j/2-1]=4;
			}
			else if(str_i[j]=='O'){
				data[i][j/2-1]=0;
			}
			else if(tem>0&& tem<10){
				data[i][j/2-1]=tem;
			}else{
				break;
			}
		}
	}
	int round=0;
	int targe=0;
	scanf("%d",&targe);
	i=0;
	int sum=0;
	for(i=0;i<9;i++){
		for(j=0;j<10;j+=1){
			printf("%d ",data[i][j]);
		}
		printf("\n");
	}
	int tem=data[0][0];
	i=0;
	while(tem!=-1){
		if(tem==0){
			round+=1;
			if(round%3==0){
				for(j=0;j<4;j++)base[j]=0;
			}
		}
		base[0]=tem;
		sum+=upbase(base,tem);
		point[round]=sum;
		printf("%d %d %d %d\n",i%9,i/9,round,tem);
		i+=1;
		tem=data[i%9][i/9];
	}
	for(i=0;i<9;i++){
		printf("#%d ",point[i]);
	}

	printf("\n");
	return 0;
	for(i=0;i<9;i++){
		printf("#%d ",point[i]);
	}

	return 0;
}
