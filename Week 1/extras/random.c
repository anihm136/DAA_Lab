#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  clock_t start, end;
  double cpu_time_used;

  for (long int i = 10; i < 10000000000; i*=10) {
    start = clock();
    for (int j=0; j<i; j++) {
      rand();
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for %ld : %lf\n",i,cpu_time_used);
  }
  return 0;
}
