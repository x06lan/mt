#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int upbase(int a[4],int up,int save[3]){
	int i=0;
	int sum=0;
	for(i=0;i<up;i++){
		if(a[3]!=0){
			sum+=1;
			if(a[3]<=3){
				save[a[3]-1]+=1;
			}
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
	int base[5]={0,0,0,0};
	int first3[3]={0};
	int an[3]={0};
	int point[20]={0};
	int round=0;
	int sum=0;
	int targe=0;
	scanf("%d",&targe);
	i=0;
	while(value!=-1){
		//printf("%d %d %d %d\n",i%9,i/9,value,sum);
		if(value==0){
			round+=1;
			if(round%3==0){
				for(j=0;j<4;j++)base[j]=0;
			}
		}else{
			printf("&%d ",value);
			if((i%9)<3 &&value!=4){
				printf("&%d %d\n",i%9,value);
				an[i%9]=an[i%9]+1;
			}
			base[0]=(i%9)+1;
			sum+=upbase(base,value,first3);
		}
		point[round]=sum;
		i+=1;
		value=data[i%9][i/9];
	}
	printf("%d\n",point[targe]);
	for(i=0;i<3;i++){
		printf("%d %d %d\n",i+1,an[i],first3[i]);
	}
	
	return 0;
	for(i=0;i<9;i++){
		for(j=0;j<10;j++){
			printf("%d ",data[i][j]);
		}
		printf("\n");
	}
}
