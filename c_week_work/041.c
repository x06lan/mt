#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* copy(int *a,int n){
	int i;
	int *out=malloc(sizeof(int)*(n+2));
	for(i=0;i<n;i++){
		*(out+i)=*(a+i);
	}
	return out;
}
int min(int a,int b){ return (a>b)?b:a;}

int shortpath(int n,int *data,int *path,int len,int *minv){
	int i,j;
	int out=0;
	if(len==n){
		*(path+len)=*path;
		for(i=0;i<len;i++){
			out+=data[path[i]*n+path[i+1]];
		}
		*minv=min(*minv,out);
		if(*minv==0)*minv=out;
		free(path);
		return *minv ;
	}
	for(i=0;i<n;i++){
		if(path==NULL ){
			int *newpath=malloc(sizeof(int)*2);
			*newpath=i;
			shortpath(n,data,newpath,1,minv);
		}
		else{
			int used=0; 
			for(j=0;j<len;j++){
				if(*(path+j)==i){used=1;break;}
			}			
			if(used==0){
				int *newpath=copy(path,len);
				*(newpath+len)=i;
				shortpath(n,data,newpath,len+1,minv);
			}
		}
	}
	free(path);
	return out;
}

int main(){
	int n;
	scanf("%d",&n);
	int data[n*n];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int tem;
			scanf("%d",data+i*n+j);
		}
	}
	int mv=0;
	shortpath(n,data,NULL,0,&mv);
	printf("%d",mv);
	return 0;
}

