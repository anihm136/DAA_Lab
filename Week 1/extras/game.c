#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int pred;
  while (1) {
    printf("Enter prediction: ");
    scanf("%d",&pred);
    if (pred == rand()%6) {
      printf("You won\n");
    } else {
      printf("You lost\n");
    }
  }
  return 0;
}
