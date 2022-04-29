#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cube{
	int top[9];
	int but[9];

	int font[9];
	int back[9];

	int right[9];
	int left[9];
}cube;
void init(cube* a){

	int i=0;
	for(i=0;i<9;i++)a->top[i]=1;
	for(i=0;i<9;i++)a->but[i]=6;
	for(i=0;i<9;i++)a->font[i]=4;
	for(i=0;i<9;i++)a->back[i]=3;
	for(i=0;i<9;i++)a->left[i]=5;
	for(i=0;i<9;i++)a->right[i]=2;

}

void move(cube *a,int t){
	int level=t%10;//right2 midde1 letf 0
	int row;
	int side=t/10;
	int tem[3];
	int i=0;
	//top font back buttom
	//c
	if(side==1){
		for(i=0;i<3;i++)tem[i]=a->top[i*3+level];
		for(i=0;i<3;i++)a->top[i*3+level]=a->font[i*3+level];
		for(i=0;i<3;i++)a->font[i*3+level]=a->but[(2-i)*3+(2-level)];
		for(i=0;i<3;i++)a->but[(2-i)*3+(2-level)]=a->back[(2-i)*3+2-level];
		for(i=0;i<3;i++)a->back[(2-i)*3+(2-level)]=tem[i];
		
		if(level==0){
			for(i=0;i<3;i++)tem[i]=a->left[i];
			for(i=0;i<3;i++)a->left[i]=a->left[i*3+2];
			for(i=0;i<3;i++)a->left[i*3+2]=a->left[2-i+6];
			for(i=0;i<3;i++)a->left[2-i+6]=a->left[(2-i)*3];
			for(i=0;i<3;i++)a->left[(2-i)*3]=tem[i];
		}
		if(level==2){
			for(i=0;i<3;i++)tem[i]=a->right[i];
			for(i=0;i<3;i++)a->right[i]=a->right[(2-i)*3];
			for(i=0;i<3;i++)a->right[i*3]=a->right[6+i];
			for(i=0;i<3;i++)a->right[6+i]=a->right[2+i*3];
			for(i=0;i<3;i++)a->right[2+i*3]=tem[i];
		}
	}
	else{
		for(i=0;i<3;i++)tem[i]=a->font[i+level*3];
		for(i=0;i<3;i++)a->font[i+level*3]=a->right[i+level*3];
		for(i=0;i<3;i++)a->right[i+level*3]=a->back[i+level*3];
		for(i=0;i<3;i++)a->back[i+level*3]=a->left[i+level*3];
		for(i=0;i<3;i++)a->left[i+level*3]=tem[i];

		if(level==0){
			for(i=0;i<3;i++)tem[i]=a->top[i];
			for(i=0;i<3;i++)a->top[2-i]=a->top[i*3];
			for(i=0;i<3;i++)a->top[i*3]=a->top[6+i];
			for(i=0;i<3;i++)a->top[6+i]=a->top[2+3*(2-i)];
			for(i=0;i<3;i++)a->top[2+3*(2-i)]=tem[2-i];
		}
		if(level==2){
			for(i=0;i<3;i++)tem[i]=a->but[i];
			for(i=0;i<3;i++)a->but[2-i]=a->but[i*3];
			for(i=0;i<3;i++)a->but[i*3]=a->but[6+i];
			for(i=0;i<3;i++)a->but[6+i]=a->but[2+3*(2-i)];
			for(i=0;i<3;i++)a->but[6+i]=tem[2-i];
		}
	}
	

}
int main(){
	cube a;
	init(&a);
	int i,n,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		move(&a,k);
	}
	for(i=0;i<3;i++)printf("%d %d %d\n",*(a.top+i*3),*(a.top+1+3*i),*(a.top+2+i*3));
	return 0;
}
