#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//#include "f1.c"

extern int global_1;
volatile int global_2;
void func();
//int global_3;
const int global_3;

typedef double real; 

int main()
{

real r_1 = 1.1;
int size = sizeof(r_1);

printf("real = %f; size = %d\n", r_1, size);

	global_1++;
	global_2++;
	//global_3++;
	func();


 return 0;

}
