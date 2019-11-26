#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TASK_SIZE 10


struct MyT
{
 	int id;
  	char name[20];
	int time;
  	int priority;
	struct MyT* next; 
};

	struct MyT Task[TASK_SIZE];	
	struct MyT Task_Empty = {0};

bool empty_t = false;

//-----------------------------------
int getSize()
{
	int count = 0;
	struct MyT * currentTask;
	currentTask = &Task[0];
	do{    
	currentTask = currentTask->next;
	count++;
 	}while(currentTask!=0);


if (empty_t) count = 0;

	return count;

}

void listLinker(struct MyT* , struct MyT* );

//-----------------------------------
void push(int* headId, struct MyT* newTask)
{
	empty_t = false;
	int id = getSize();	
    
	if ((id == 0) && (*headId == 0))
	{
      Task[0] =*newTask;
      Task[id].next = 0;
      id = getSize();	
	}


	if(id == TASK_SIZE)
	{
	// Не переполнен ли стек?   
      		printf( "Error: stack overflow\n");
        	abort();
  	}
    else
	{
      Task[*headId] =*newTask;
      Task[*headId-1].next = &Task[*headId];
      Task[*headId].next = 0;
  	}     
}

//-----------------------------------
void push_back(struct MyT* newTask)
{	
    empty_t = false;
	int id = getSize();	
    
	if(id == TASK_SIZE)
	{
	// Не переполнен ли стек?   
      		printf( "Error: stack overflow\n");
        	abort();
  	}
    else
	{
      Task[id] =*newTask;
      if (id != 0) Task[id-1].next = &Task[id];
      Task[id].next = 0;
  	}   
}

//-----------------------------------
void pop_front()
{	

	if (getSize() > 1)
		Task[0] = *Task[0].next;
	else
	{
		Task[0] = Task_Empty;

	printf( "---- Список задач пуст ---- \n");
	empty_t = true;
	}

}

//-----------------------------------
void buble_sort()
{	
	
int size = getSize();	

 for (int i = 0; i < size - 1; ++i)
        {
            for (int j = 0; j < size - 1; ++j)
            {
                if (Task[j+1].priority < Task[j].priority)
                {
					struct MyT temp = Task[j+1];					
					Task[j+1] = Task[j];
					Task[j] = temp;

                }
            }
        }


  for (int j=1; j <size; j++)
    listLinker(&Task[j-1], &Task[j]);

	Task[size-1].next = 0;
}

//-----------------------------------
void reverse_sort()
{	
	
int size = getSize();	

 for (int i = 0; i < size - 1; ++i)
        {
            for (int j = 0; j < size - 1; ++j)
            {
                if (Task[j+1].priority > Task[j].priority)
                {
					struct MyT temp = Task[j+1];					
					Task[j+1] = Task[j];
					Task[j] = temp;

                }
            }
        }


  for (int j=1; j <size; j++)
    listLinker(&Task[j-1], &Task[j]);

Task[size-1].next = 0;

}

//-----------------------------------
void pop_back()
{
		int id = getSize();	

--id;
		Task[id].id = 0;
		strcpy(Task[id].name,"");
		Task[id].time = 0;
		Task[id].priority =  0;

      	Task[id-1].next = 0;

    if(id <= 0)  
	{
 	printf( "---- Список задач пуст ---- \n");
    empty_t = true;
	}

}
//----------------------------------
char* itoa(int val, int base){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}

//-----------------------------------
void handlerStructs(struct MyT * Task, struct MyT * Task2)
{

    Task->id = ++Task2->id;
	Task->time = ++Task2->time;

    int a=Task->id;
	char* ch;
    ch = itoa(++a,20);   
    char buf[20]; 
	strcpy(buf,"task_");
    strcat(buf,ch);
	strcpy(Task->name,buf);

}

//-----------------------------------
void initPrior(struct MyT* curr)
{
	curr->priority = rand()%10;
}

//-----------------------------------
void listLinker(struct MyT * Task, struct MyT * Task2)
{
  Task->next = Task2;
}

//-----------------------------------
void peek()
{

	struct MyT * currentTask;
	

	printf( "Task[1].id = %d\n", Task[0].id);
	printf( "Task[1].name = %s\n", Task[0].name);
	printf( "Task[1].priority = %d\n", Task[0].priority);

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++

void qhandlerStructs(struct MyT * Task,struct MyT * Task2)
{
    //Task->id = Task2->id /2;
	Task->id = ++Task2->id;
    strcpy(Task->name,Task2->name);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++

void sleepcp(int milliseconds) // Cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {

    }
}
//------------------------------

void Sleep(unsigned int milliseconds) {
    usleep(milliseconds * 1000);
}

void InputFree(){

	char str[5];
	if (fgets(str, 5, stdin)) {
    while (!strchr(str, '\n') && fgets(str, 5, stdin)) { /* empty */ }
} 

}

//-----------------------------

int main()
{
  
   int sw = 0;
   char ch;
   int cnt_do = 0;
   bool st_rand = false;

    do
    {	    
		printf("Выбор: Стек(s)/Очередь(q)....");
		fflush(stdin);
		if (cnt_do != 0) InputFree();
		scanf("%c", &ch);

		Task[0].id = 0;
		strcpy(Task[0].name,"task_1");
		Task[0].time = 1;
		st_rand = false;
		srand(time(NULL));

		printf("Сформировать задачи вручную? Да(y)/Нет(n)....");
		fflush(stdin);
		InputFree();
        scanf("%c", &ch);

		int t_size = 0;
		int c_time[t_size];

	    struct MyT * tempT;

		if (ch == 'y')
		{	     		
			do
			{
			
 			char temp[20];

			Task[t_size].id = t_size;  
			InputFree();
    		printf("Ввести имя задачи..");
        	scanf("%s", temp);
    		fflush(stdin);
			strcpy(Task[t_size].name, temp);	
		
        	printf("Ввести время выполнения..");
       		InputFree();
			scanf("%d", &Task[t_size].time);
        	fflush(stdin);

        	printf("Ввести приоритет..");
       		InputFree();
			scanf("%d", &Task[t_size].priority);
        	fflush(stdin);

            push(&Task[t_size].id, &Task[t_size]);

			t_size++;

			InputFree();
        	printf("добавить еще задачу y(да)/n(нет)..");
			fflush(stdin);
            scanf("%c", &ch);
            fflush(stdin);

			} while(ch != 'n');	

		}
		else
		{

		t_size = rand()%10;

		if (t_size >7)      
			t_size -=3;
		else if (t_size < 3) 
			t_size +=4;

		if (t_size ==1) t_size++;
		if (t_size ==4) t_size++;

		for(int i = 0; i<=t_size; i++)  
			c_time[i] = rand()%5;

        st_rand = true;
        empty_t = false;

		}


	int cnt = t_size+3;

	if (st_rand == true)
	{
		for (int j=1; j <cnt-1; j++)
			handlerStructs(&Task[j], &Task[j-1]);

		for (int j=0; j <cnt-3; j++)
			initPrior(&Task[j]);

		for (int j=0; j <cnt-3; j++)
			Task[j].time = c_time[j];
	}

	for (int j=1; j <cnt-3; j++)
		listLinker(&Task[j-1], &Task[j]);

	Task[TASK_SIZE-3-1].next = 0;

	struct MyT * currentTask;
		currentTask = &Task[0];

	do
	{
		printf("Текущая задача №: %d Имя: %s Время: %d Приоритет: %d \n",
		currentTask->id,
		currentTask->name,
		currentTask->time,
		currentTask->priority);      
    	currentTask = currentTask->next;
	}while(currentTask!=0);


    int msec = 0, trigger = 10000; 
    clock_t before = clock();
    int iterations = 0;


	if(ch == 's') 
		buble_sort();
	else 
		reverse_sort();

	printf ("\n");
	int iSize = getSize();
	int i =0;

    //-------------------- таймер выполнения ------------------ 
		do
		{
    	Sleep(1000);
		if(ch == 's') 
		{
			if (Task[0].time <= i)
			{
			printf ("Задача %s выполнена. \n",Task[0].name);
			pop_front();
			i=0;
			}
		}
		else
		{
			if (Task[getSize()-1].time <= i)
			{
			printf ("Задача %s выполнена. \n",Task[getSize()-1].name);
			pop_back();
			i=0;
			}
		}	

	    
		i++;
		} while(getSize()>0);


		InputFree();
        printf("повторный запуск менеджера задач y(да)/n(нет)..");

		fflush(stdin);
        scanf("%c", &ch);
        fflush(stdin);
		cnt_do++;

    }while(ch != 'n');



  return 0;

}
