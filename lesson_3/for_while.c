#include <stdio.h>
#include <stdbool.h>


int main(int argc, char **argv)
{



int k = 0;

do
{
 
  printf("------ do_while = %d ------ \n", k);
 
  int j = 3;
  while (j > 0)   
   {
      printf("--- while = %d ---\n", j);

      for(int i = 0; i<2; i++)
        printf("for = %d \n", i);
       j--;
    }
 
 k++; 

}while(k<2);


    return 0;


}
