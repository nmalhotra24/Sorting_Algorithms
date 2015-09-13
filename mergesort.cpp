//Nikita Malhotra
//CSCI 260: Data Structures
//Purpose: to implement the sort algorithm for merge sort.

//function declaration
void Merge_Sort( unsigned int *list, unsigned int *tempbuffer, unsigned int leftside, unsigned int rightside );
void merge( unsigned int *list, unsigned int *tempbuffer, unsigned int leftside, unsigned int midpoint, unsigned int rightside );


void mergesort( unsigned int *list, unsigned int listLen, unsigned int *tempbuffer )
{
  Merge_Sort(list, tempbuffer, 0, listLen-1);
}

void Merge_Sort( unsigned int *list, unsigned int *tempbuffer, unsigned int leftside, unsigned int rightside )
{
  unsigned int midpoint;

  if (leftside < rightside)
  {
    midpoint = (rightside + leftside)/2;
    Merge_Sort(list, tempbuffer, leftside, midpoint);
    Merge_Sort(list, tempbuffer, midpoint+1, rightside);
    merge(list, tempbuffer, leftside, midpoint, rightside);
  }
}

void merge( unsigned int *list, unsigned int *tempbuffer, unsigned int leftside, unsigned int midpoint, unsigned int rightside )
{
  unsigned int temp_pos = leftside;
  unsigned int start = leftside;
  unsigned int right_end = midpoint + 1;
  unsigned int i = 0;

  while ((start <= midpoint) && (right_end <= rightside))
  {
    if (list[start] <= list[right_end])
    {
      tempbuffer[temp_pos] = list[start];
      start++;
    } else {
      tempbuffer[temp_pos] = list[right_end];
      right_end++;
    }

    temp_pos++;
  }

  while (start <= midpoint)
  {
    tempbuffer[temp_pos] = list[start];
    start++;
    temp_pos++;
  }

  while (right_end <= rightside)
  {
    tempbuffer[temp_pos] = list[right_end];
    right_end++;
    temp_pos++;
  }
  
  for (i = leftside; i <= rightside; i++)
  {
    list[i] = tempbuffer[i];
  }
}
  
