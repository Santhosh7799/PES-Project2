/*
 * conversion.c
 *
 *  Created on: Oct 20, 2017
 *      Author: srikant
 */

/*This program is used to convert interger to ASCII and ASCII to interger converion.*/
/*This conversion program to convert big endian to little endian and vice versa */

/*Author Srikant Gaikwad, Santhosh Thumanapalli*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

/*Function for integer to ASCII conversion*/

#ifdef nonzer0
uint8_t my_itoa(int32_t data,char* ptr, uint32_t base)
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
#endif

const uint8_t ascii_0 = 48;
const uint8_t ascii_A = 65;
const uint8_t ascii_neg = 45;

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	uint8_t length = 0;

	if(data == 0)
	{
		*ptr = ascii_0;
		*(ptr + 1) = 0;
		return 1;
	}

	if(data < 0)
	{
		//negative
		*ptr = ascii_neg;
		ptr++;
		data *= -1;
	}

	while(data > 0)
	{
		if(data%base > 9)
		{
			*(ptr + length) = ascii_A + data%base - 10;
		}
		else
		{
			*(ptr + length) = ascii_0 + data%base;
		}
		length++;

		data /= base;
	}

	/* reverse */
	my_reverse(ptr, length);

	/* add null terminating character */
	*(ptr + length) = 0;

	return length;
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

/*Function for little endian to big endian conversion*/

int8_t little_to_big32(uint32_t *data, uint32_t length)
{
    uint32_t k = 0;
    while(k< length)
    {
        uint32_t l = *(data + k);

        int8_t a1,a2,a3,a4;
        a1 = (l & 0x000000ff);
        a2 = (l & 0x0000ff00) >> 8;
        a3 = (l & 0x00ff0000) >> 16;
        a4 = (l & 0xff000000) >> 24;

        l = ((a1<<24)|(a2<<16)|(a3<<8)|(a4));

        *(data + k) = l;
        k++;

    }
    return 0;

}

/*Function for big endian to little endian conversion*/
int8_t big_to_little32(uint32_t *data, uint32_t length)
{
    uint32_t a = 0;
    while(a < length)
    {
        uint32_t b = *(data + a);//04_03_02_01

        int8_t b1,b2,b3,b4;
        b1 = (b & 0xff000000) >> 24;//00_00_00_04
        b2 = (b & 0x00ff0000) >> 16;//00_00_00_03
        b3 = (b & 0x0000ff00) >> 8; //00_00_00_02
        b4 = (b & 0x000000ff);      //00_00_00_01

        b = ((b1)|(b2<<8)|(b3<<16)|(b4<<24));//01_02_03_04

        *(data + a) = b;
        a++;

    }
    return 0;
}






