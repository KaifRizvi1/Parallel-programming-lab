#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(){
int iter;
scanf("%d",&iter);
int i;
#pragma omp parallel for schedule(guided,2) num_threads(4)
for(i=0;i<iter;i++){
printf("Thread number :%d,iteration:%d\n",omp_get_thread_num(),i);
}
}
