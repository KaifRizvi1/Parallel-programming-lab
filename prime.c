#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(){
int prime[1000],i,j,n;
scanf("%d",&n);
for(j=1;j<=n;j++){
prime[j]=1;
}
prime[1]=0;
for(i=2;i*i<=n;i++){
#pragma omp parallel for
for(j=i*i;j<=n;j+=i){
if(prime[j]==1)
prime[j]=0;
}
}
for(i=2;i<=n;i++){
if(prime[i]==1)
printf("%d\t",i);
}
printf("\n");
}

