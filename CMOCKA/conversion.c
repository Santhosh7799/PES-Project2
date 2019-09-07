/*This program is used to convert interger to ASCII and ASCII to interger converion.*/
/*This conversion program to convert big endian to little endian and vice versa */

/*Author Srikant Gaikwad, Santhosh Thumanapalli*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "conversion.h"

/*Function for integer to ASCII conversion*/

uint8_t my_itoa(int32_t data,uint8_t* ptr, uint32_t base)
{
    
uint8_t l=1;
int flag=0;
int8_t i=0,j=0;			       
uint8_t temp;

if(data==0)
  {
    *(ptr+l++)='0';
    return 0;
  }

if (data<0)
  {
   flag=1;
   data = -1*data;
  }

while(data!=0)
  {
   uint32_t remainder=data % base;
   if(remainder>9)
    {
      *(ptr+l++)=(remainder-10)+'a';
     }
   else
     {
      *(ptr+l++)= remainder+'0';
     }
 data = data/base;
  }

if(flag==1)
  {
   *(ptr+l++)='-';
  }


i=l-1;
j=0;
 while(j <i)				
       {
         temp= *(ptr+j);
         *(ptr+j) = *(ptr+i);
         *(ptr+i)=temp;
         j++;
         i--;
       }
*(ptr+l)='\0';




return l;
}


/*Function for ASCII to integer conversion*/
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{

	int i=0,q=0;
int flag;
int32_t res=0;
int32_t value=0;
//int32_t multiplier=1;
int32_t counter=0;

if(*ptr == '-')
{

i++;
q++;
counter++;
flag=1;
}

if(base==10)
{
while(i<digits-1)
  {
res= res*10+*(ptr+i)-'0';
i++;
  }
}

if(base==2)
{
while(i<digits-1)
  {
   res = res + *(ptr+i) * (2^(digits-2-i));
   i++;
  }
}
if(base==16)
{


while(i<digits-1) 
  {
  if((*(ptr+i)-'0')>9)
   {
   value = *(ptr+i)-'a'+10;
   
   }
  else
  {
  value=*(ptr+i);
  value = value - '0';
  }  

i++;
res =res*16+value;
}
}
if(flag==1)
{
res= -1*res;
}
return res;
}


int8_t big_to_little32(uint32_t * data, uint32_t length)
{     
 enum test_status status = TEST_SUCCEED;

    if (! data )

    {

    status= TEST_ERROR_INVALID_POINTERS;
    return status;
    }

	int8_t result = 1;
	if(data!=NULL)
	{
		uint8_t * byte_ptr = (uint8_t *) data;
		uint32_t x = 0;

		/*
			Return an error because the data is not aligend on a word.  Endian conversion
			will fail.
		*/
		if(length%4 != 0)
		{
			result = 1;
		}else
		{
			/*
				Loop for every word.  Reverse the values of the word.
				Set result to success.
			*/
			for(x = 0; x<length/4;x++)
			{
				byte_ptr = (uint8_t *)data;
				byte_ptr = my_reverse(byte_ptr,4);
				data += 1;
			}
			result = 0;
		}	

		data = data - x;
	}
	
	
	return result;
	
}

int8_t little_to_big32(uint32_t * data, uint32_t length)
{
	int8_t result = 0;
	
	/*
		The process is the same to go from big_to_little and little_to_big.
		Call the big_to_little function and return result
	*/
	if(data!=NULL)
	{
		result = big_to_little32(data, length);
	}
	
	return result;
	
}

