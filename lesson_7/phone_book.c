#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <string.h>

#define MAXH 80
#define SIZE 10


//------------- struct book-------------
struct Tnum
{
    char number[MAXH];
    char name[MAXH];
};

//------------- function-len-------------
int strlen_ch(char* s)
{
   char* p =s;
   while(*p != '\0')
       p++;
   return p-s;
}

//-------------------------------- print ---------------------------------------------
void printT(struct Tnum* arr)
{
	printf("---------------------------------\n");

	for(int i=0; i<SIZE; i++)
	{
		printf("%s%s", arr[i].name, arr[i].number);
		printf("---------------------------------\n");
	}
}
//------------------------------------------------------------------------------------

//-------------------------------- search ---------------------------------------------
int searchT(struct Tnum* arr)
{


	char str[5];
	if (fgets(str, 5, stdin)) {
    	while (!strchr(str, '\n') && fgets(str, 5, stdin)) { /* empty */ }
	}


	char temp[MAXH];
	printf("Введите имя для поиска..");
	fgets(temp, MAXH, stdin);
	fflush(stdin);

	int count = 0;

			for(int i=0; i<SIZE; i++)
			{
			if (strcmp(temp, arr[i].name)==0)
				{
				printf("Такое имя уже есть. В ячейке №_%d\n", i);
				return -1;
				}
			else
                  count++;
			}

         if (count==SIZE)
               printf("имя не занято!\n");

         return 0;

}
//------------------------------------------------------------------------------------

//-------------------------------- write ---------------------------------------------
void writeT(struct Tnum* arr)
{
	FILE *file = fopen("phone_book.txt", "w");

	for(int i=0; i<SIZE; i++)
    {
		fputs(arr[i].name, file);
		fputs(arr[i].number, file);
    }

	fclose(file);
	printf("файл сохранен успешно");

}
//------------------------------------------------------------------------------------

//-------------------------------- input ---------------------------------------------
void inputT(struct Tnum* arr)
{

char str[5];
if (fgets(str, 5, stdin)) {
    while (!strchr(str, '\n') && fgets(str, 5, stdin)) { /* empty */ }
}


    char temp[MAXH];
    printf("Ввести новое имя..");
    fgets(temp, MAXH, stdin);
    fflush(stdin);

    int count = 0;

	for(int i=0; i<SIZE; i++)
	{
		if ((strcmp(temp, arr[i].name)==0))
		{
			printf("Такое имя уже есть. (в номере №_%d\n", i);
			printf("Ввести другое имя..");
			fgets(temp, MAXH, stdin);
		}
		else
			count++;
	}

    for(int i=0; i<SIZE; i++)
	{
		if(strlen_ch(arr[i].name)==0) // && (count==SIZE))
		{
               memcpy(arr[i].name, temp, MAXH);
               fflush(stdin);

               printf("Ввести новый номер..");
               fgets(arr[i].number, MAXH, stdin);
               fflush(stdin);

               break;
             }
	}

}
//------------------------------------------------------------------------------------

//-------------------------------- read ---------------------------------------------
void readT(struct Tnum *arr)
{
    FILE *file = fopen("phone_book.txt", "r");

    char temp[2];

    for(int i=0; i<SIZE; i++)
    {
        fgets(arr[i].name, MAXH, file);
        fgets(arr[i].number, MAXH, file);
    }

    fclose(file);
    printf("файл успешно загружен");

}
//------------------------------------------------------------------------------------



int main()
{
	
    struct Tnum arrNum[SIZE];
	
    //--init---
    for(int i=0; i<SIZE; i++)
    {
        strcpy(arrNum[i].name,"");
        strcpy(arrNum[i].number,"");
    }

    int sw = 0;
    char ch;

    printf("добавить новый контакт...(1)\n");
    printf("показать все контакты....(2)\n");
    printf("записать в файл..........(3)\n");
    printf("чтение из файла..........(4)\n");
    printf("поиск контакта...........(5)\n");
    printf("выход из программы.......(6)\n");

    do
{	    
    	printf("\n");
        printf("ввести код(1-6)....");

			fflush(stdin);
            scanf("%d", &sw);
            fflush(stdin);

            if ((sw < 1) || (sw > 6))
			{
                printf("Ошибка! Ввести код(1-6)! код = %d", sw);
				char str[5];
				if (fgets(str, 5, stdin)) {
   				while (!strchr(str, '\n') && fgets(str, 5, stdin)) { /* empty */ }
				}		
			}
         fflush(stdin);

        switch (sw)
        {
        case 1:        
                inputT(arrNum);
                break;

        case 2:
                printT(arrNum);
                break;

        case 3:
                writeT(arrNum);
                break;

        case 4:
                readT(arrNum);
                break;

        case 5:
                searchT(arrNum);
                break;
          }

        fflush(stdin);

    }while(sw != 6);


printf("выход. код =%d", sw);



 return 0;

}
