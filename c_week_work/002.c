#include <stdio.h>
#include <math.h>

int main() {
	char n[2];
	int nn;
	int base[4]={0,0,0,0};
	int i=0;
	while(scanf("%s",n)!= EOF){ 
		if (n[0]=='O'){
			nn=0;
			base[0]=0;
		}
		else {
			base[0]=1;
		}
		if (n[0] =='1'){
			nn=1;
		}
		if (n[0] =='2'){
			nn=2;
		}
		if (n[0] =='3'){
			nn=3;
		}
		if (n[0]=='H'){
			nn=4;
		}
		for(i=3;i>=0;i--){
			if(base[i]!=0){
				int tem=i+nn;
				base[i]=0;
				if(i+nn<4){
					base[tem]=1;
				}
			}
		}
	}
    //printf("\n");
    for(i=1;i<4;i++){
		printf("%d\n",base[i]);
	}
	return 0;
}
