#include<stdlib.h>
#define swap(a,b){int t=a;a=b;b=t};
int* col(int *a,int *b, int lena,int lenb){
	int *tem=malloc(sizeof(int)*(lena+lenb));
	int *tem1=malloc(sizeof(int)*(lena+lenb));
	int i,j;
	for(i=0;i<lena;i++)*(tem+i)=a[i];
	for(i=0;i<lenb;i++)*(tem+lena+i)=b[i];

}
void merge(int *x,int s,int m,int e){
	int alen=m-s+1;
	int blen=e-(m+1)+1;
	int a[alen],b[blen];
	int i,j;
	for(i=0;i<alen;i++){
		a[i]=x[i+s];
	}
	for(i=0;i<blen;i++){
		a[i]=x[i+m+1];
	}

}
void merge_sort(int *a,int s,int e){
	if(lena==2){
	}else{
		merge_sort(a,lena/2,int*c);

	}
}
int main(){
	return 0;
}
