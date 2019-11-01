#include <stdio.h>
#include <stdbool.h>



int main(int argc, char **argv)
{
	    
int m = 1000; //count value

for(int n = 0; n < 10; n++)
{

	char ch1[10]; 				    //file name
	sprintf(ch1, "%s%d%s", "output_",n , ".txt");
	FILE* out = fopen(ch1, "w");     //file open

	if (out == NULL)
	{
    return -1;   //error
	}

	for(int i = 0; i <= m; i++)
	{
		char sign = ' ';
		if (i%30 == 0)
			sign = '\n';

		fprintf(out, "%c", sign);
		int rnd = rand()%1000;
		fprintf(out, "%-3.3d", rnd);	

	}
	
	fprintf(out, "\n"); //end
	fclose(out);


}	



 return 0;
}
