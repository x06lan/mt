#include <stdio.h>
#include <math.h>
#include <stdarg.h>
int main() {
	int i=0,j=0;
	float out[3]={0};
	float min=1000000;
	float pay_type[6][3]=
	{{183,383,983},
	{0.08,0.07,0.06},
	{0.1393,0.1304,0.1087},
	{0.1349,0.1217,0.1018},
	{1.1287,1.1127,0.9572},
	{1.4803,1.2458,1.1243}};
	for(i=1;i<6;i++){
		float tem=0;
		scanf("%f",&tem);
		// printf("%f\n",tem);
		for(j=0;j<3;j++){
			out[j]+=pay_type[i][j]*tem;
		}
	}
	for(i=0;i<3;i++){
		if (out[i]<pay_type[0][i]){
			out[i]=pay_type[0][i];
		}
		if(out[i]<min){
			min=out[i];
		}
	}
	for(i=0;i<3;i++){
		if(out[i]==min){
			printf("%d\n",(int)pay_type[0][i]);
		}
	}
}
