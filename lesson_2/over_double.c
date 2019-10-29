#include <stdio.h>
#include <stdbool.h>


int main(int argc, char **argv)
{


   double x = 1E+308; 

   printf("was x: %f \n", x);
   printf("was x: %E \n", x);


   printf("----------------------------------------------\n");

    x += 1E+308; 

   printf("was x: %f \n", x);
   printf("was x: %E \n", x);




    return 0;


}
