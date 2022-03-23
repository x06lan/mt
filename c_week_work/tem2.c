#include <stdio.h>
#include <stdlib.h>
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
int main() {
	int e[]={1,2,3};

	f(e,3,1);

	printf("%d\n",*(e+1));
	
}
