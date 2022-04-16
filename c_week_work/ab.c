#include <stdio.h>
#include <stdlib.h>
int* rec(int d[][4],int a[][2],int check[4][9],int n){
	int i,j,k;
	for(i=0;i<n;i++){
		if(a[i][0]!=0||a[i][1]!=0){
			if(a[i][1]==0){
				//guset one is ture
			}
			else if(a[i][0]==0){
				//guset one could be ture
			}
			else {
				//guset one could be and is  ture
			}
		}
		else {
			//remove
		}
	}

	return 0;
}
int main() {
	int n;
	scanf("%d",&n);
	int data[n][4];
	int an_data[n][2];
	char tem_s[12]="";
	int i,j,k;
	i=0;j=0;
	scanf("%s",&tem_s);
	while(tem_s[0]!='-'){
		for(j=0;j<4;j++){
			data[i][j]=tem_s[j]-'0';
		}
		an_data[i][0]=tem_s[5]-'0';
		an_data[i][1]=tem_s[7]-'0';
		for(j=0;j<4;j++){
			printf("%d ",data[i][j]);
		}
		for(j=0;j<2;j++){
			printf("%d ",an_data[i][j]);
		}
		scanf("%s",&tem_s);
		i+=1;
	}
    return 0;
}
