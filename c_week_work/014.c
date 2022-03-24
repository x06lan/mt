#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
int main() {
	char ans[5];
	char guss[6][5]={};
	scanf("%s",&ans);
	int i=0,j=0,z=0;
	int x=0,y=0;
	for(i=0;i<6;i++){
		scanf("%s",&guss[i]);
		if(strcmp(guss[i],"")==0){
			break;
		}
	}
	for(i=0;i<6;i++){
		int isb=0,isa=0;
		for(j=0;j<4;j++){
			if(ans[j]==guss[i][j]){
				isa+=1;
			}
			else{
				for(z=0;z<4;z++){
					if(ans[j]==guss[i][z]){
						isb+=1;
						break;
					}
				}
			}
		}
		if(isa==4){
			printf("win");
			break;
		}
		else if(x<isa){
			printf("%dA%dB\n",isa,isb);
			x=isa;y=isb;
		}
		else{
			printf("%dA%dB\n",isa,isb);
		}
	}
	return 0;
}
