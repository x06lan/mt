#include <stdio.h>
#include <stdlib.h>
typedef struct dice
{
    int top;
    int buttom;

    int right;
    int left;

	int font;//face me
	int back;
}dice;
void init(dice* a){
	a->top=1;
	a->buttom=6;

	a->right=2;
	a->left=5;
	
	a->font=4;
	a->back=3;
}
void roll(dice* a,int st){
	if(st==1){
		int tem=a->top;
		a->top=a->font;
		a->font=a->buttom;
		a->buttom=a->back;
		a->back=tem;
	}
	else if(st==2){
		int tem=a->top;
		a->top=a->back;
		a->back=a->buttom;
		a->buttom=a->font;
		a->font=tem;
	}
	else if(st==3){
		int tem=a->right;
		a->right=a->top;
		a->top=a->left;
		a->left=a->buttom;
		a->buttom=tem;
	}
	else if(st==4){
		int tem=a->right;
		a->right=a->buttom;
		a->buttom=a->left;
		a->left=a->top;
		a->top=tem;
	}
}
int deal(int a[]){
	int value=0;
	int i,j;
	int all[7]={0};
	int count=0;
	int max=0;
	int max_s=0;
	for(j=1;j<7;j++){

		for(i=0;i<4;i++){
			if(a[i]==j){
				all[j]+=1;
				count+=1;
			}
		}
		if(count>=max){
			max_s=max;
			max=count;
		}
		else if(count>=max_s)max_s=count;
		count=0;
	}
	if(max==4)value=18;
	if(max==3)value=0;
	if(max==1)value=0;
	if(max==2 &&max_s==2){
		count=0;
		for(j=1;j<7;j++){
			if(all[j]==2)count+=1;
			if(count==2){value=j*2;break;}
		}
	}
	if(max==2 &&max_s==1)for(j=1;j<7;j++)if(all[j]==1)value+=j;
	return value;
}
int main() {
	dice a[4];
	init(&a[0]);
	init(&a[1]);
	init(&a[2]);
	init(&a[3]);
	int time=0;
	int i=0,j=0;
	int run[4]={0};
	int sum=0;
	scanf("%d",&time);
	if(time==0){
		printf("18");	
		return 0;
	}
	for(i=0;i<time;i++){
		for(j=0;j<4;j++){
			scanf("%d",&run[j]);
			roll(&a[j],run[j]);
		}
		int tem[4]={0};
		for(j=0;j<4;j++){
			tem[j]=a[j].top;
		}
		sum=deal(tem);
	}
	printf("%d",sum);	
    return 0;
}
