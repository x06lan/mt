#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//lanx
void str_int(char a[],int* out){
	int i=strlen(a)-1;
	int tem=(int)a[i]-48;
	*(out+i+1)=-1;
	while(i>=0 ){
		*(out+strlen(a)-i-1)=tem;
		i-=1;
		tem=(int)a[i]-48;
	}
}
void big_print(int *a){
		int i,tem,notz=0;
		i=89;
		tem=*(a+i);
		for(i=89;i>=0;i--){
			tem=*(a+i);
			if(tem!=-1 &&tem!=0 ){
				notz=1;
			}
			if(notz==1){
				printf("%d",tem);
			}
		}
}
int compare(int *a,int *b){
	int i=44;
	int as=*(a+i);
	int bs=*(b+i);
	for(i=44;i>=0;i--){
		as=*(a+i);
		bs=*(b+i);
		if(as>bs){
			return 1;
		}
		else if(as<bs){
			return -1;
		}
	}
	return 0;
}

void big_add(int *a,int *b,int *out){
	int i=0;
	int up=0;
	int as=*(a+i);
	int bs=*(b+i);
	while((as!=-1 ||bs!=-1) || up==1){
		if(as<0)as=0;
		if(bs<0)bs=0;
		*(out+i)=(as+bs+up)%10;
		up=(as+bs+up)/10;
		i+=1;
		as=*(a+i);
		bs=*(b+i);
	}
}
void big_mul(int *a,int *b,int *out){
	int i=0,j=0,tem;
	int up=0;
	int as=*(a+i);
	int bs=*(b+i);
	for(i=0;i<45;i++){
		as=*(a+i);
		if(as<0)as=0;
		for(j=0;j<45;j++){
			bs=*(b+j);
			if(bs<0)bs=0;
			if(*(out+i+j)<0)*(out+i+j)=0;
			tem=*(out+i+j)+(as*bs)+up;
			*(out+i+j)=tem%10;
			up=tem/10;
			//if(as*bs>0)printf("%d,%d,%d,%d\n",tem,as,bs,up);
		}
		//big_print(out);
		//printf("\n");
	}
}
void big_sub(int *a,int *b,int *out){
	int i=0;
	int bw=0;
	int as=*(a+i);
	int bs=*(b+i);
	while((as!=-1 ||bs!=-1) || bw==1){
		if(as<0)as=0;
		if(bs<0)bs=0;
		if(as-bs-bw>=0){
			*(out+i)=as-bs-bw;
			bw=0;
		}
		else{
			*(out+i)=10+as-bs-bw;
			bw=1;
		}
		i+=1;
		as=*(a+i);
		bs=*(b+i);
	}
}

int main() {
	char a[45],b[45];
	int *x,*y,*z;
	int i=0;
	int sign=1;
	int op=0;
	scanf("%d",&op);
	scanf("%s",&a);
	scanf("%s",&b);
	x=malloc(90* sizeof(int));
	y=malloc(90* sizeof(int));
	z=malloc(90* sizeof(int));
	for(i=0;i<90;i++)*(x+i)=-1;
	for(i=0;i<90;i++)*(y+i)=-1;
	for(i=0;i<90;i++)*(z+i)=-1;
	str_int(a,x);
	str_int(b,y);
	switch(op){
		case 1:
			big_add(x,y,z);
			break;
		case 2:
			sign=compare(x,y);
			if(sign!=0){
				if(sign>0){
					big_sub(x,y,z);
				}
				else{
					big_sub(y,x,z);
					printf("-");
				}
			}
			else{
				printf("0");
				return 0;
			}
			break;
		case 3:
			big_mul(x,y,z);
			break;
	}
	big_print(z);
	return 0;
}
