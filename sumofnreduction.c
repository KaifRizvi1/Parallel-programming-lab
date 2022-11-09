#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int main(){
int n,sum=0;
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
}
#pragma omp parallel shared(arr) reduction(+:sum)
{
#pragma omp for
for(int i=0;i<n;i++)
{
sum+=arr[i];
printf("partial sum= %d\n",sum);
}
}
printf("total sum= %d\n",sum);
}
