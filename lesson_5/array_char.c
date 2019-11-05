#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>





int main()
{
	char arrCh[] = {" "};

	for(int i = 0; i <= 1000; i++)
	{
		char sign = ' ';
		if (i%30 == 0)
			sign = '\n';

		printf("%c", sign);
		arrCh[i] = (char)rand()%10;
		arrCh[i] += 65; 

		printf("%c", arrCh[i]);	

	}



 return 0;
}
