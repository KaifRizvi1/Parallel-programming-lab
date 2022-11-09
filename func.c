#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(int argc,char *argr[]){
#pragma omp parallel
{
printf("hello from %d thread of %d threads\n",omp_get_thread_num(),omp_get_num_threads());
}
}
