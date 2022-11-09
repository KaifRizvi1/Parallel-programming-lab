#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void merge(int arr[],int low, int mid, int high){
int temp[30],i,j,k,m;
j=low;
m=mid+1;
for(i=low;j<=mid && m<=high;i++){
if(arr[j]<arr[m]){
temp[i]=arr[j];
j++;
}
else{
temp[i]=arr[m];
m++;
}
}
if(j>mid){
for(k=m;k<=high;k++)
{
temp[i]=arr[k];
i++;
}
}
else{
for(k=j;k<=mid;k++){
temp[i]=arr[k];
i++;
}
}
for(k=low;k<=high;k++)
arr[k]=temp[k];
}
int mergesort(int arr[],int low, int high){
int mid;
if(low<high){
mid=(low+high)/2;
#pragma omp parallel sections num_threads(2)
{
#pragma omp section
{ 
mergesort(arr,low,mid);
}
#pragma omp section
{
mergesort(arr,mid+1,high);
}}
merge(arr,low,mid,high);
}}
int main(){
int n,i,j;
printf("enter number of elements");
scanf("%d",&n);
int arr[n];
printf("enetr elements\n");
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
}
mergesort(arr,0,n-1);
printf("Sorted array=\n");
for(int i=0;i<n;i++){
printf("%d\t",arr[i]);
}
}

