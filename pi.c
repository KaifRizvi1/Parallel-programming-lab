#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define MAX_THREADS 8
static long steps=1000000000;
double step;
int main(){
int i,j;
double x,pi,sum=0.0,start,delta;
step=1.0/(double)steps;
for(j=1;j<=MAX_THREADS;j++){
printf("using %d threads",j);
omp_set_num_threads(j);
sum=0.0;
start=omp_get_wtime(); 
#pragma omp parallel for reduction(+:sum) private(x)
for(i=1;i<=steps;i++){
x=(0.5+i)*step;
sum+=4.0/(1.0+x*x);
}
pi=step*sum;
delta=omp_get_wtime()-start;
printf("pi= %16g  calculated in %4g seconds\n",pi,delta);
}
}
