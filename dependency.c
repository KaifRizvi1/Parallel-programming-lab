#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int main(){
    int i,j,n;
    scanf("%d",&n);
    int arr[n];
    #pragma omp parallel for
    for(i=0;i<n;i++){
        arr[i]=i*(i+1)/2;
    }

    for(j=0;j<n;j++){
        printf("%d ",arr[j]);
    }
    printf("\n");
}