#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int main(int argc,char**argr[]){
int partial_sum=0,total_sum=0;
#pragma omp parallel private(partial_sum) shared(total_sum)
{
partial_sum=0;
total_sum=0;
#pragma omp for
for(int i=1;i<=10;i++)
{
partial_sum+=i;

}
#pragma omp critical
{
total_sum+=partial_sum;
printf("partail sum =%d\n",partial_sum);
}
}
printf("total sum =%d\n",total_sum);
}
