#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 10000
void removeback(char *a,char d){
	int i=0;
	char tc[size]="";
	strcpy(tc,a);
	
	while(a[i]!='\0'){
		a[i+1]=tc[i];
		i++;
	}
	*a=d;
}
void removefont(char *a){
	int i=0;
	char tc[size]="";
	strcpy(tc,a);
	
	while(a[i]!='\0'){
		a[i]=tc[i+1];
		i++;
	}
}
int main(){

	char a[size]="";
	char ins[size]="";
	gets(a);
	gets(ins);
	int i=0;
	char *pos=a;
	while(ins[i]!='\0'){
		int le=ins[i];
		//printf("%s , %c+ %c +%d\n",a,le,*pos,i);
		if (le=='0'){
			pos=a+0;
		}
		else if(le== '$'){
			pos=a+strlen(a);
		}
		else if(le== 'x'){
			if(*pos!=0){
				removefont(pos);
			}
		}
		else if(le== 's'){
			char tem2=*pos;
			*pos=*(pos+1);
			*(pos+1)=tem2;
		}
		else if(le== 'i'){
			removeback(pos,ins[i+1]);
			pos+=1;
			i+=1;
		}
		else if(le== 'u'){
			if(isalpha(*pos)){
				*pos=toupper(*pos);
			}
			pos+=1;
		}
		else if(le== '+'){
				pos+=1;
			}
		else if(le== '-'){
				pos-=1;
			}
		i+=1;
	}
	printf("%s\n",a);
	return 0;
} 
