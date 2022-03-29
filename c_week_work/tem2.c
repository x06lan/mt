#include <stdio.h>
#include <stdlib.h>
#define swap(x,y){int t;t=x;x=y;y=t;}
int  f(int d[],int size,int key){
	int i=size/2;
	int start=0,end=size-1;
	while(d[i]!=key && i<size){
		
		if(d[i]<key){
			i=(i+end)/2;
			start=i;
		}
		else{
			i=(i+start)/2;
			end=i;
		}
	}

	if(d[i]!= key){
		return -1;
	}
	return i;
}
void merge_sort(int *a,int len){
	if(len==2){
	}

}
	

int main() {
	int e[]={1,2,3};
	int x=1,y=0;

	//f(e,3,1);
	printf("%d %d\n",x,y);
	swap(x,y);
	printf("%d %d\n",x,y);
	printf("%d %d\n",e[0],e[1]);
	swap(e[0],e[1]);
	printf("%d %d\n",e[0],e[1]);

	//printf("%d\n",*(e+1));
	
}
