#include <stdio.h>

int main( int argc, char *argv[] )
{
  int integers[] =  {2,5,9,6,7,3,4,10,8,1};
  int numItems = sizeof(integers)/sizeof(int);
  int copy[numItems];
  int index = 0;

  int start = 0;
  int end = numItems - 1;
  //Trivival solution: reverse values into another array
  while(index < numItems)
  {
    //Index the copy array from the back to the front
    copy[numItems - index - 1] = integers[index];
    index++;
  }
  
  //In-situ reverse: reverse without using a second array
  while(start < end)
  {
    //Swap the value between start and end
    int temp = integers[start];
    integers[start] = integers[end];
    integers[end] = temp;

    //move start towards the last item.
    start++;
    //move end towards the first item
    end--;
  }
}