//Nikita Malhotra
//CSCI 260: Data Structures
//Purpose: to implement the sort algorithm for heap sort

#include "sortutilities.h"

//function declaration
void Build_maxHeap( unsigned int *list );
void Heapify( unsigned int *list, unsigned int i );

//global variable declaration
unsigned int heapsize = 0;

void heapsort( unsigned int *list, unsigned int listLen, unsigned int *tempbuffer )
{
  heapsize = listLen - 1;
  Build_maxHeap(list);
  for (unsigned int i = listLen-1; i >= 1; i--)
  {
    swap(list[0], list[i]);
    heapsize = heapsize - 1;
    Heapify(list,0);
  }
}

void Build_maxHeap( unsigned int *list)
{
  for (int i = (heapsize/2); i >= 0; i--)
  {
    Heapify(list, i);
  }

}

void Heapify( unsigned int *list, unsigned int i)
{
  unsigned int l = 2*i + 1;
  unsigned int r = 2*i + 2;
  unsigned int largest;

  if ((l <= heapsize) && (list[l] > list[i]))
  {
    largest = l;
  } else 
  {
    largest = i;
  }

  if ((r <= heapsize) && (list[r] > list[largest]))
  {
    largest = r;
  }

  if (largest != i)
  {
    swap(list[i], list[largest]);
    Heapify(list, largest);
  }
} 




