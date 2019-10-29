#include <stdio.h>
#include <stdbool.h>


int main(int argc, char **argv)
{


  for(int i = 97; i < 100; i++)
  {
     switch(i)
      {
      case 97: printf("char = %c\n", i); break;
      case 98: printf("char = %c\n", i); break;
      case 99: printf("char = %c\n", i); break;
      }; 

   }

 return 0;
}
