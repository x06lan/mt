#include <stdio.h>
#include <stdlib.h>
#define max 16*16*16*16
int check(char ans[],char gu[],int predict[]){
	int i,j;
	int a=0,b=0;
	for(i=1;i<4;i++)for(j=0;j<i;j++)if(ans[i]==ans[j])return 0;
	for(i=0;i<4;i++){
		int have=0;
		int same=0;
		for(j=0;j<4;j++){
			if(ans[i]==gu[j]){
				if(i==j){
					same=1;
					break;
				}
				else{
					have=1;
				}
			}
		}
		if(same==1)a+=1;
		if(same==0&& have==1)b+=1;
	}
	if(predict[0]==a &&predict[1]==b)return 1;
	return 0;
}
int gus(int all[] ,char ins[],int an_data[2]){
	int i=0;
	int one=0;
	char ag[100]="";
	char al[100]="";

	for(i=0;i<max;i++){
		if(all[i]==1){
			sprintf(ag,"%04X",i);
			if(check(ag,ins,an_data)==1){
				sprintf(al,"%04X",i);
				one+=1;
			}
			else{
				all[i]=0;
			}
		}
	}
	if(one==1)printf("%s",al);
	if(one==1)return 1;
	return 0;
}
int main() {
	int data[4];
	int an_data[2];
	char tem_s[20]="";
	char tem_c[100];
	char tem_a[20]="";
	int i,j,k;
	int all[max];
	for(i=0;i<16*16*16*16;i++)all[i]=1;
	i=0;j=0;
	scanf("%4s %1s %s", &tem_s,&tem_c,&tem_a);
	while(tem_s[0]!=' '){
		an_data[0]=tem_a[0]-'0';
		an_data[1]=tem_a[2]-'0';
		int j=gus(all,tem_s,an_data);
		if(j==1){
			break;
		}
		scanf("%4s %1s %s", &tem_s,&tem_c,&tem_a);
		i+=1;
	}
}
