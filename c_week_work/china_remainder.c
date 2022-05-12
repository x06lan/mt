#include <stdio.h>
int rev(int a,int m){
    int i;
    for(i=1;i<m;i++){
        if((i*a)%m==1){
            return i;
        }
    }
}
int main()
{
    int n;
    
    scanf("%d",&n);
    printf("%d\n",n);
    int m=1,i;
    int x[100],y[100];
    for(i=0;i<n;i++){
        scanf("%d %d",&x[i],&y[i]);
        m*=x[i];
        
        
    }
    
    int out=0;
    for(i=0;i<n;i++){
        out+=(m/x[i])*rev(m/x[i],x[i])*y[i];
   
    }
    printf("%d\n",out%m);
    return 0;
}