#include<omp.h>
#include<stdio.h>
int main(){
#pragma omp parallel
{
#pragma omp sections
{
printf("this is from thread %d\n",omp_get_thread_num());
}
#pragma omp sections
{
printf("this is from thread %d\n",omp_get_thread_num());
}
}
}
