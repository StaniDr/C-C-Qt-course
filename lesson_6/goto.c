#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>





int main()
{
	int i = 0;
	char sign = ' ';

	slip: 
		i++;

			
	if (i%20 == 0)
		sign = '\n';
	else
		sign = ' ';

	printf("%-2.2d%c", i, sign);

	if ((i>=1) && (i<100))
		goto slip;	

 return 0;

}
