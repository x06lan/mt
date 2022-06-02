#include <stdio.h>
#include <stdlib.h>
int main() {
	int w,h;
	scanf("%d %d",&w,&h);
	char  file[h][w];
	int i,j;
	for(i=0;i<h;i++){
		scanf("%s",file[i]);
	}

	printf("\n");
	for(i=h-1;i>=0;i--){
		for(j=w-1;j>=0;j--){
			printf("%c",file[i][j]);
		}
		printf("\n");
	}
}
