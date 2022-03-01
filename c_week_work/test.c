#include <stdio.h>
#include <math.h>

int tt(int x,int y){
	int i=0,toto=0;
	for(i=x;i<=y;i++){
		if(i%2==1){
			toto+=i;
		}
	}
    return toto;
}
int main() {
	int g=0;
	g=tt(10,13);
	printf("%d",g);
}
