#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
int get_gcd(int a,int b){
	int tem=0;
	while(a>=1 &&b>=1){
		tem=a%b;
		a=b;
		b=tem;
	}
	return (a>=1)?a:1;
}
void out(int a ,int b,char s[],char add[]){
	int ta=abs(a);
	int tb=abs(b);
	if(a==0){
	}
	else if(ta/tb<1){
		if(a*b>0){
			printf("%s%d/%d%s",add,abs(a%b),abs(b),s);
		}
		else{
			printf("%d/%d%s",-abs(a%b),abs(b),s);
		}
	}
	else if(ta/tb>=1){
		if(a%b==0){
			if(a/b==1){
				printf("%s%s",add,s);
			}
			else if(a/b==-1){
				printf("-%s",s);
			}
			else{
				if(a/b>0){
					printf("%s%d%s",add,a/b,s);
				}
				else{
					printf("%d%s",a/b,s);
				}
			}
		}
		else{
			if(a/b>0){
				printf("%s%d(%d/%d)%s",add,a/b,abs(a%b),abs(b),s);
			}
			else{
				printf("%d(%d/%d)%s",a/b,abs(a%b),abs(b),s);
			}
		}
	}
	else if(ta/tb==1){
	}
}
int main() {
	int x1,x2,y1,y2;
	scanf("%d,%d",&x1,&y1);
	scanf("%d,%d",&x2,&y2);
	int m[2]={1};
	int b[2]={1};
	m[0]=y1-y2;
	m[1]=x1-x2;
	b[0]=(x2*y1-x1*y2);
	b[1]=x2-x1;
	int gcd1=get_gcd(abs(m[0]),abs(m[1]));
	m[0]/=gcd1;
	m[1]/=gcd1;
	gcd1=get_gcd(abs(b[0]),abs(b[1]));
	b[0]/=gcd1;
	b[1]/=gcd1;
	//printf("%d,%d %d,%d\n",m[0],m[1],b[0],b[1]);
	printf("y=");
	if(y1==y2){
		printf("%d",y1);
	}
	else{
		out(m[0],m[1],"x","");
		out(b[0],b[1],"","+");
	}
}
