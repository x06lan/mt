#include <stdio.h>
#include <math.h>
int main() {
	int i=0,j=0;
	int name[3];
	int class[6][10];
	for(i=0 ;i<6;i++){
		for(j=0;j<10;j++){
			class[i][j]=4;
		}
	}
	for (i=0;i<3;i++){
		int class_n=0;
		scanf("%d",&name[i]);
		scanf("%d",&class_n);
		for(j=0;j<class_n;j++){
			int time=0;
			scanf("%d",&time);
			int tem=0;
			tem=floor(time/10);
			if (class[tem][time%10]!=4){
				// printf("%d\n",class[tem][time%10]);
				printf("%d and %d conflict on %d\n",name[class[tem][time%10]],name[i],time);

			}
			else{
				class[tem][time%10]=i;
			}
		}
	}
	return 0;
}
