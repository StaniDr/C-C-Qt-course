#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>





int main()
{
	
	int count = 0;
	int i = 0;	
	
	FILE *file = fopen("gets_text.txt", "r");
	char mystring[10000];

	while(true)
	{
	if (fgets(mystring, 10000, file) != NULL)
		{
		i=0;
		while(mystring[i] != '\n')
		{
			if (mystring[i] == 'a')
				count++;
			i++;		
		}

		}	
	else{
		break;		
		}
	}


	 printf("count of symbols a = %d\n", count);




 return 0;

}
