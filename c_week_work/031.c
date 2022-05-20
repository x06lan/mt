#include <stdio.h>
#include <stdlib.h>
#define GATEVALUE(TYPE) int(*GateValue)(void)
typedef struct gate{
	int gatetype;
	int i[2];
	int out;
	struct gate *a;
	struct gate *b;

}gate;
int g_and(int a,int b){
	return a&b;
}
int g_or(int a,int b){
	return a|b;
}
int g_xor(int a,int b){
	return a^b;
}
int g_not(int a,int b){
	return (!a);
}
int g_b(int a,int b){
	return a;
}
int (*f[5])(int,int)={g_and,g_or,g_xor,g_not,g_b};
int get_v(gate *t){
	if(t->a!= NULL){
		t->i[0]=get_v(t->a);
	}
	if(t->b!=NULL){
		t->i[1]=get_v(t->b);
	}
	int out=f[t->gatetype](t->i[0],t->i[1]);
	t->out=out;
	return out;
}
int main(){

	int ii[4];
	int ig[6];
	int i;
	for(i=0;i<4;i++){
		scanf("%d,",&ii[i]);
	}
	scanf("%c,",&i);
	for(i=0;i<6;i++){
		char v;
		if(i!=5){
			scanf("%c,",&v);
		}
		else{
			scanf("%c",&v);
		}
		if(v=='A'){
			ig[i]=0;
		}
		else if(v=='O'){
			ig[i]=1;
		}
		else if(v=='X'){
			ig[i]=2;
		}
		else if(v=='N'){
			ig[i]=3;
		}
		else if(v=='E'){
			ig[i]=4;
		}
	}
	//gate allgate[6];
	gate gate[6];
	for(i=0;i<6;i++){
		gate[i].gatetype=ig[i];
		gate[i].a=NULL;
		gate[i].b=NULL;
		gate[i].out=-1;
	}

	gate[0].i[0]=ii[0];
	gate[0].i[1]=ii[1];
	gate[1].a=&gate[0];
	gate[2].a=&gate[0];
	gate[2].i[1]=ii[2];
	gate[3].a=&gate[1];
	gate[3].b=&gate[2];
	gate[4].i[1]=ii[3];
	gate[4].a=&gate[2];
	gate[5].a=&gate[3];
	gate[5].b=&gate[4];

	get_v(&(gate[5]));
	printf("%d,%d,%d",gate[1].out,gate[3].out,gate[5].out);
	return 0;
} 
