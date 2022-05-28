#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int w,h;
	scanf("%d %d",&w,&h);
	int i,j,k;
	int x,y;
	int xl,yl;
	int xm,ym=-1;
	int xmi,ymi=-1;
	char save[100][100];
	memset(save,(int)' ',sizeof(save));
	while(scanf("%d %d",&x,&y)!= EOF){
		int tem=x-xl;
		int tem1=y-yl;
		if(xm==-1){
			xm=x;
			xmi=x;
			ym=y;
			ymi=y;
		}
		for(i=0;i<abs(tem);i++){
			int nowx=x+i*tem/abs(tem);
			int nowy=y+i*tem1/abs(tem1);
			save[nowx][nowy]='*';
			if(nowx>xm)xm=nowx;
			if(nowx>xmi)xmi=nowx;
			if(nowy>ym)ym=nowy;
			if(nowy>ymi)ymi=nowy;
		}
		xl=x;
		yl=y;
	}
	for(i=ymi;i<ym;i++){
		printf("|");
		for(j=xmi;j<xm;j++){
			if(i==ymi || j==ym-1)printf("-");
			printf("%c",save[i][j]!=' '?'*':' ');
		}
		printf("|\n");
	}
	
	return 0;

}
