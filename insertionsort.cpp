//Nikita Malhotra                                                                                              
//CSCI 260: Data Structures                                                                                    
//Purpose: to implement the sort algorithm for insertion sort                                                  


void insertionsort( unsigned int *list, unsigned int listLen )
{
  unsigned int i, j, key;

  for (j = 1; j < listLen; j++)
  {
    i = j-1;
    key = list[j];

    //while the number is greater than zero and                                                                
    //greater than its previous index                                                                          
    while (i > 0 && (list[i] > key))
    {
      list[i+1] = list[i];
      i--;
    }

    list[i+1] = key;

  }
}



