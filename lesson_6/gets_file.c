#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>





int main()
{
	
	int count = 0;
	int total = 0;
	int i = 0;	

	char mystring[10000];

	char arrCh[] = {'A','S','D','F','G','H','J','K','L',':',
					'Q','W','E','R','T','Y','U','I','O','P',
					'Z','X','C','V','B','N','M','<','>','?',
					'a','s','d','f','g','h','j','k','l',';',
					'q','w','e','r','t','y','u','i','o','p',
					'z','x','c','v','b','n','m',',','.','/'};



	int sizeArr = sizeof(arrCh);

	//printf("size=%d", sizeArr);

	for(int k =0; k<sizeArr; k++)	
	{
		FILE *file = fopen("gets_text.txt", "r");		
		count = 0;	
		//i = 0;	
		while(true)
		{
			if (fgets(mystring, 10000, file) != NULL)
			{
				i=0;
				while(mystring[i] != '\n')
				{
				if (mystring[i] == arrCh[k])
					{
					count++;
					total++;				
					}
				i++;		
				}

			}	
		else{
			break;		
			}
		}

		printf("count of symbols %c = %d\n", arrCh[k], count);
		fclose(file);

	}


		printf("total of symbols = %d\n", total); 




 return 0;

}
