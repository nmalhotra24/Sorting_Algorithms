//Nikita Malhotra                                                                                              
//CSCI 260: Data Structures                                                                             
//Purpose: to implement the sort algorithm for radix sort                                                      
 
//function declaration                                                                                        
void counting_sort( unsigned int *list, unsigned int *tempbuffer, unsigned int listLen, unsigned int exp );

void radixsort( unsigned int *list, unsigned int listLen, unsigned int *tempbuffer )
{
  unsigned int i = 0, max = list[0], exp = 1;
  
  //Find the maximum number to know number of digits
  for (i = 1; i < listLen; i++)
  {
    if (list[i] > max)
      max = list[i];
  }
 
  //Do counting sort for every digit.
  while (max / exp > 0)
  {  
    counting_sort(list,tempbuffer,listLen,exp);
    exp *= 10;
  }
}


//Do counting sort of list[] according to the digit represented by exp.
//tempbuffer will the array used to provide temporary working storage                                           
void counting_sort ( unsigned int *list, unsigned int *tempbuffer, unsigned int listLen, unsigned int exp )
{
  unsigned count[10] = {0}; 
  int i = 0;                                                                                

  //Store count of occurrences in count[] 
  for (unsigned int i = 0; i < listLen; i++)
  {
    count[ (list[i]/exp)%10 ]++;
  }
  
  //Change count[i] so that count[i] now contains actual position of
  //this digit in tempbuffer[]
  for (i = 1; i < 10; i++)
  {
    count[i] += count[i - 1];
  }
   
  //Build the tempbuffer array  
  for (i = listLen - 1; i >= 0; i--)
  {
    tempbuffer[count[ (list[i]/exp)%10 ] - 1] = list[i];
    count[ (list[i]/exp)%10 ]--;
  }
  
  //Copy the tempbuffer array to list[], so that list[] now
  //contains sorted numbers according to curent digit
  for (unsigned int i = 0; i < listLen; i++) 
  {
    list[i] = tempbuffer[i];
  }
}
