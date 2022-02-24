#include <stdio.h>
#include <math.h>
int main() {
	int base[4]={0,0,0,0};
	int i=0;
	float pay,poe,rant;
	for(i=0;i<4;i++){
		scanf("%d",&base[i]);
	}
	poe=base[3]*0.05;
	rant=(base[1]+base[0])*0.08*base[2];
	pay=(base[1]+base[0])*base[2]-poe-rant;
	printf("%.1f\n",pay);
	printf("%.1f\n",poe);
	printf("%.1f\n",rant);

	
	return 0;
}
