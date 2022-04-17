#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int n =0;
	
	scanf("%d",&n);
	int data[6][10][n];
	int number[n];
	int i,j,k;
	memset(data,0,sizeof(data));

	for(i=0;i<n;i++){
		int name;
		scanf("%d",&name);
		number[i]=name;
		scanf("%d",&name);
		for(j=0;j<name;j++){
			int tem;
			scanf("%d",&tem);
			data[tem/10][tem%10][i]=1;
		}
	}
	for(i=1;i<6;i++){
		for(j=1;j<10;j++){
			int tem=-1;
			for(k=0;k<n;k++){
				if(data[i][j][k]==1){
					if(tem!=-1){
						printf("%d and %d conflict on %d",number[tem],number[k],i*10+j);
					}
					tem=k;
				}
			}
		}
	}
	return 0;
}
