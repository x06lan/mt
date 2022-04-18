#include <stdio.h>
typedef struct dice{
	int top;
	int buttom;

	int right;
	int left;

	int font;
	int back;
}dice;
void init(dice *a){
	a->top=1;
	a->buttom=6;

	a->font=4;
	a->back=3;

	a->right=2;
	a->left=5;
}
void move(dice *a,int up){
	if(up==1){
		int tem=a->top;
		a->top=a->font;
		a->font=a->buttom;
		a->buttom=a->back;
		a->back=tem;
	}
	else{
		int tem=a->top;
		a->top=a->left;
		a->left=a->buttom;
		a->buttom=a->right;
		a->right=tem;

	}
}
int main(){
	dice a[2];
	dice b[2];
	init(&a[0]);
	init(&a[1]);
	init(&b[0]);
	init(&b[1]);
	int n=0;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int aa,bb;
		scanf("%d %d",&aa,&bb);
		move(&a[0],aa);
		move(&a[1],bb);
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int aa,bb;
		scanf("%d %d",&aa,&bb);
		move(&b[0],aa);
		move(&b[1],bb);
	}
	printf("%d %d ",a[0].font,a[0].top);
	printf("%d %d ",a[0].back,a[0].buttom);
	printf("%d %d\n",a[0].right,a[0].left);

	printf("%d %d ",a[1].font,a[1].top);
	printf("%d %d ",a[1].back,a[1].buttom);
	printf("%d %d\n",a[1].right,a[1].left);
	int sum1=0;
	int sum2=0;
	
	if(a[0].top!=a[1].top)sum1=a[0].top!=a[1].top;
	if(b[0].top!=b[1].top)sum2=b[0].top!=b[1].top;

	printf("%d %d ",b[0].font,b[0].top);
	printf("%d %d ",b[0].back,b[0].buttom);
	printf("%d %d\n",b[0].right,b[0].left);

	printf("%d %d ",b[1].font,b[1].top);
	printf("%d %d ",b[1].back,b[1].buttom);
	printf("%d %d\n",b[1].right,b[1].left);
	if(sum1==sum2)printf("Tie");
	if(sum1>sum2)printf("A win");
	if(sum1<sum2)printf("B win");

	return 0;
}
