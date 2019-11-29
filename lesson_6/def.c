#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define SQR(X) (X*X)
#define BLOCK 3

struct myS{
int i;
char* s;

};


int main()
{

struct myS curS;
curS.i = 100500;
curS.s = "cash";

printf("size = %d, name = %s\n", curS.i, curS.s);



 return 0;

}
