#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <sys/times.h>
#include <time.h>
#include <cmath>
#include <iomanip>

//#define aSIZE 10000

const int aSIZE = 10000; 


//-----------------------------------
void buble_sort(int arr[], int size)
{	
	
 for (int i = 0; i < size - 1; ++i)
        {
            for (int j = 0; j < size - 1; ++j)
            {
                if (arr[j] > arr[j+1])
                {
					int temp = arr[j+1];					
					arr[j+1] = arr[j];
					arr[j] = temp;

                }
            }
        }
}


//-----------------------------------
void select_sort(int arr[], int size)
{	
	
 for (int i = 0; i < size - 1; ++i)
        {
            for (int j = 0; j < size - 1; ++j)
            {
                if (arr[j] > arr[j+1])
                {
					int temp = arr[j+1];					
					arr[j+1] = arr[j];
					arr[j] = temp;
                }
            }
        }

}

//-----------------------------------
void insert_sort(int arr[], int size)
{	
	
	int temp = 0;
	int j = 0;
	for(int i = 1; i < size; i++)
	{
		temp = arr[i];
        	j = i-1;
	
		while((j >= 0) && (arr[j]>temp))
		{
		arr[j+1] = arr[j];
		arr[j] = temp;
		j--;	      
		}

	}
}


//-----------------------------------
void Sleep(unsigned int milliseconds) {
    usleep(milliseconds * 1000);
}


int frequencyPrimes (int n)                           // функция поиска простых чисел
{
  int freq = n-1;
  for (int i = 2; i <= n; ++i)
      for (int j = sqrt( (float)i ); j > 1; --j)
          if (i % j == 0)
          {
            --freq;
            break;
          }
  return freq;
}

//-----------------------------------
void merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR){
  int i = 0;
  int j = 0;
  while(i<lenL||j<lenR){
    if (i<lenL & j<lenR){
      if(L[i]<=R[j]){
        merged[i+j] = L[i];
        i++;
      }
      else{
        merged[i+j] = R[j];
        j++;
      }
    }
    else if(i<lenL){
      merged[i+j] = L[i];
      i++;
    }
    else if(j<lenR){
      merged[i+j] = R[j];
      j++;
    }
  }
}

//-----------------------------------
void merge_sort(int data[], int lenD)
{
  if(lenD>1){
    int middle = lenD/2;
    int rem = lenD-middle;
    int* L = new int[middle];
    int* R = new int[rem];
    for(int i=0;i<lenD;i++){
      if(i<middle){
        L[i] = data[i];
      }
      else{
        R[i-middle] = data[i];
      }
    }
    merge_sort(L,middle);
    merge_sort(R,rem);
    merge(data, lenD, L, middle, R, rem);
  }
}

//-----------------------------------
void quick_sort(int* data, int const len)
{
  int const lenD = len;
  int pivot = 0;
  int ind = lenD/2;
  int i,j = 0,k = 0;
  if(lenD>1){
    int* L = new int[lenD];
    int* R = new int[lenD];
    pivot = data[ind];
    for(i=0;i<lenD;i++){
      if(i!=ind){
        if(data[i]<pivot){
          L[j] = data[i];
          j++;
        }
        else{
          R[k] = data[i];
          k++;
        }
      }
    }
    quick_sort(L,j);
    quick_sort(R,k);
    for(int cnt=0;cnt<lenD;cnt++){
      if(cnt<j){
        data[cnt] = L[cnt];;
      }
      else if(cnt==j){
        data[cnt] = pivot;
      }
      else{
        data[cnt] = R[cnt-(j+1)];
      }
    }
  }
}


//-----------------------------

int main()
{
  
   int sw = 0;
   char ch;
   int cnt_do = 0;
   bool st_rand = false;


   int* Arr1 = new int[aSIZE]; 
   int* Arr2 = new int[aSIZE]; 
   int* Arr3 = new int[aSIZE]; 
   int* Arr4 = new int[aSIZE]; 
   int* Arr5 = new int[aSIZE]; 



for(int i = 0; i < aSIZE; i++)
   Arr1[i] = rand()%1000;

for(int i = 0; i < aSIZE; i++)
   Arr2[i] = rand()%1000;

for(int i = 0; i < aSIZE; i++)
   Arr3[i] = rand()%1000;

for(int i = 0; i < aSIZE; i++)
   Arr4[i] = rand()%1000;

for(int i = 0; i < aSIZE; i++)
   Arr5[i] = rand()%1000;


//----------------------------------------------------------------------------------- 
  buble_sort(Arr1, aSIZE);
  int t1 = clock(); 

	std::cout << "сортировка пузырьком. Время =  " 
          << ((float)t1) / CLOCKS_PER_SEC << " секунд" << std::endl;

//----------------------------------------------------------------------------------- 
  select_sort(Arr2, aSIZE);
  int t2 = clock()-t1; 

	std::cout << "сортировка выбором.   Время =  " 
          << ((float)t2) / CLOCKS_PER_SEC << " секунд" << std::endl;

//----------------------------------------------------------------------------------- 
  insert_sort(Arr3, aSIZE);
  int t3 = clock() - t2 - t1; 

	std::cout << "сортировка вставкой.  Время =  " 
          << ((float)t3) / CLOCKS_PER_SEC << " секунд" << std::endl;

//----------------------------------------------------------------------------------- 

  quick_sort(Arr4, aSIZE);
  int t4 = clock() - t3 - t2 - t1; 

	std::cout << "быстрая сортировка.   Время =  " 
          << ((float)t4) / CLOCKS_PER_SEC << " секунд" << std::endl;

//----------------------------------------------------------------------------------- 

  merge_sort(Arr5, aSIZE);
  int t5 = clock() - t4 - t3 - t2 - t1; 

	std::cout << "сортировка слиянием.  Время =  " 
          << ((float)t5) / CLOCKS_PER_SEC << " секунд" << std::endl;
//----------------------------------------------------------------------------------- 
  int t = clock(); 

int st1 = ((float)t1) / CLOCKS_PER_SEC;


int arr_i[5];

arr_i[0] = t1;
arr_i[1] = t2;
arr_i[2] = t3;
arr_i[3] = t4;
arr_i[4] = t5;

int min_i = arr_i[0];
for(int i = 1; i < 5; i++)
{
	if (arr_i[i] < min_i)
	min_i = arr_i[i];
}

std::cout << "самая быстрая сортировка = " << ((float)min_i) / CLOCKS_PER_SEC << " секунд" << std::endl;


std::cout << std::setprecision(3) << "пузырьком медленнее в  = " << (float)t1/min_i << " раз "<<  std::endl;
std::cout << std::setprecision(3)<< "выбором   медленнее в  = " << (float)t2/min_i << " раз "<<  std::endl;
std::cout << std::setprecision(3)<< "вставкой  медленнее в  = " << (float)t3/min_i << " раз "<<  std::endl;
std::cout << std::setprecision(3)<< "быстрая   медленнее в  = " << (float)t4/min_i << " раз "<<  std::endl;
std::cout << std::setprecision(3)<< "слиянием  медленнее в  = " << (float)t5/min_i << " раз "<<  std::endl;
//std::cout << "t  = " << t  << std::endl;

//for(int i = 0; i < aSIZE; i++)
 // std::cout << Arr1[i] << std::endl;



delete[] Arr1;
delete[] Arr2;
delete[] Arr3;
delete[] Arr4;
delete[] Arr5;




std::cout << "Общее время =  " 
          << ((float)t) / CLOCKS_PER_SEC << " секунд" << std::endl;




  return 0;

}
