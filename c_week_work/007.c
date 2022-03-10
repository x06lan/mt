#include <stdio.h>
#include <string.h>
int main() {
	int i=0,j=0;
	float player1=0;
	float player2=0;
	char card[][4]={"A","2","3","4","5","6","7","8","9","10"};
	for(i=0;i<3;i++){
		char temp[4];
		scanf("%s",&temp);
		int find=0;
		for(j=0;j<10;j++){
			if(strcmp(temp,card[j])==0){
				player1+=j+1;
				find=1;
				break;
			}
		}
		if (!find){
			player1+=0.5;
		}
	}
	for(i=0;i<3;i++){
		char temp[4];
		scanf("%s",&temp);
		int find=0;
		for(j=0;j<10;j++){
			if(strcmp(temp,card[j])==0){
				player2+=j+1;
				find=1;
				break;
			}
		}
		if (!find){
			player2+=0.5;
		}
	}
	if (player1>10.5){
		player1=0;
	}
	if (player2>10.5){
		player2=0;
	}
	printf("%.1f\n",player1);
	printf("%.1f\n",player2);
	if (player1==player2){
		printf("%s\n","It's a tie.");
	}
	else{
		if (player1>player2){
			printf("%s\n","A wins.");
		}
		else{
			printf("%s\n","B wins.");
		}
	}
	
	
}
