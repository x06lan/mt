#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 111
typedef struct d{
	int *save;
	int id;
	int n;
}d;
void init( d *d, int n){
	d->save=malloc(sizeof(int)*n);
	d->id=0;
	d->n=n;
}
int cmp(const void *a,const void *b){
	d *aa=(d *)(a);
	d *ab=(d *)(b);
	int *ia=aa->save;
	int *ib=ab->save;
	int n=aa->n;

	int i=0;
	while(i<n){
		if(*(ia+i)>*(ib+i)){
			return 1;
		}
		if(*(ia+i)<*(ib+i)){
			return -1;
		}
		i++;
	}
	return 0;
}
int main(){
	int number ,n;
	scanf("%d %d",&number,&n);
	d data[number];
	int i,j;
	for(i=0;i<number;i++){
		init(&data[i],n);
		data[i].id=i;
		for(j=0;j<n;j++){
			int tem;
			scanf("%d",&tem);
			*(data[i].save+j)=tem;
		}
	}
	//printf("%d\n",cmp(&data[0],&data[1]));
	//return 0;
	//printf("\n");
	qsort(data,number,sizeof(data[0]),cmp);
	for(i=0;i<number;i++){
		for(j=0;j<n;j++){
			printf("%d ",*(data[i].save+j));
		}
		printf("\n");
	}
	return 0;
}
