#include <stdio.h>
#include <stdlib.h>
int gcd(int a,int b){
	int tem=0;;
	a=abs(a);
	b=abs(b);
	while(a>=1&&b>=1){
		tem=a%b;
		a=b;
		b=tem;
	}
	return (a>1)?a:1;
}
void input(int b[2]){
	int i,tem=0;
	char str[100]="";
	scanf("%s",str);
	for(i=0;i<100;i++){
		if(str[i]=='(')tem=-1;
	}
	if(tem==-1)sscanf(str,"%d(%d/%d)",&tem,&b[0],&b[1]);
	if(tem<0)b[0]=-b[0];
	if(tem==0)sscanf(str,"%d/%d",&b[0],&b[1]);
	b[0]+=tem*b[1];
}
int out(int a[2]){
	if(a[0]%a[1]==0){
		printf("%d\n",a[0]/a[1]);
		return 0;
	}
	if(abs(a[0]/a[1])>0){
		int tem=a[0]/a[1];
		a[0]%=a[1];
		int int_gcd=gcd(abs(a[0]),a[1]);
		a[0]/=int_gcd;
		a[1]/=int_gcd;
		printf("%d(%d/%d)\n",tem,abs(a[0]),a[1]);
	}
	else{
		printf("%d/%d\n",a[0],a[1]);
	}
	return 0;
}
int main(){
	int a[2]={0};
	int b[2]={0};
	int c[2]={0};

	char str[100]="";
	while(str[0]!='n'){
		input(a);
		input(b);

		scanf("%s",str);
		if(a[1]==0||b[1]==0)str[0]='E';
		char sign=str[0];
		if(sign=='+'){
			int mom=a[1]*b[1];
			int ch=a[0]*b[1]+b[0]*a[1];
			int int_gcd=gcd(ch,mom);
			c[0]=ch/int_gcd;
			c[1]=mom/int_gcd;
			out(c);
		}else if(sign=='-'){
			int mom=a[1]*b[1];
			int ch=a[0]*b[1]-b[0]*a[1];
			int int_gcd=gcd(ch,mom);
			c[0]=ch/int_gcd;
			c[1]=mom/int_gcd;
			out(c);
		}else if(sign=='*'){
			int mom=a[1]*b[1];
			int ch=a[0]*b[0];
			int int_gcd=gcd(ch,mom);
			c[0]=ch/int_gcd;
			c[1]=mom/int_gcd;
			out(c);
		}else if(sign=='/'){
			int tem=b[0];
			b[0]=b[1];
			b[1]=tem;;
			int mom=a[1]*b[1];
			int ch=a[0]*b[0];
			int int_gcd=gcd(ch,mom);
			c[0]=ch/int_gcd;
			c[1]=mom/int_gcd;
			out(c);
		}else{
			printf("error\n");
		}
		scanf("%s",str);
	}
	return 0;
}
