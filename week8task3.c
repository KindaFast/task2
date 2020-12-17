#include <stdio.h>

int main( int argc, char *argv[] )
{
  unsigned char binaryInteger[] = {1,0,1,1,1,1,0,1};
  
  int numBits = sizeof(binaryInteger)/sizeof(unsigned char);
  
  unsigned char unsignedInteger = 0;
  
  char signedInteger = 0;
  
  int index = 0;
  
  //Convert to an unsigned binaryInteger. i.e.
  //[0|1]*2^7 + [0|1]*2^6 + [0|1]*2^5 ... + [0|1]
  while ( index < numBits)
  {
    unsigned char base = 0x1 << (numBits - 1);
    
    unsignedInteger = unsignedInteger + binaryInteger[index]*(base >> index);
    
    index++;
  }
  
  printf("The unsigned integer is %d\n", unsignedInteger);

  //Covert to a signed integer, i.e.
  //-128 + [0|1]*2^6 + [0|1]*2^5 ... + [0|1] 
  //Method 1
  signedInteger = 0x1 << (numBits - 1);
  //start from the second bit as the first bit is the sign bit
  index = 1;
  while (index < numBits)
  {
    unsigned char base = 0x1 << (numBits - 2);
    signedInteger = signedInteger + binaryInteger[index]*(base >> (index - 1));
    index++; 
  }
  printf("The signed integer without cheating is %d\n", signedInteger);
  
  //Method 2: To cheat! Not really, we just exploit the naivity of C language
  signedInteger = unsignedInteger;

  printf("The signed integer by cheating is %d\n", signedInteger);
}