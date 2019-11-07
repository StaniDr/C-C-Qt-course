#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int global_1 = 1;
int global_2 = 2;
int global_3 = 3;

void func()
{

      printf("global = %d; %d; %d\n", global_1, global_2, global_3);

}
