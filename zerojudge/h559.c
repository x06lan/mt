#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int number,weight;
	int i=0,j=0;
	scanf("%d %d",&number,&weight);
	int save[number];
	int path[number][number];
	for(i=0;i<number;i++){
		scanf("%d",&save[i]);
	}
	for(i=0;i<number;i++){
		for(j=0;j<number;j++){
			path[i][j]=0;
		}
	}
	for(i=0;i<number-1;i++){
		int tem1,tem2,tem3;
		scanf("%d %d %d",&tem1,&tem2,&tem3);
		path[tem2][tem3]=tem1;
		path[tem3][tem2]=tem1;
	}
	for(i=0;i<number;i++){
		for(j=0;j<number;j++){
			printf("%d %d %d",i,j,path[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

