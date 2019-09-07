/*********************************************************
*author: santhosh thummanapalli   srikanth gaikwad
*
This contains the functions to check whether conversation.c 
*functions worked fine or not
*
**********************************************************/
#include "conversion.h"

 //TO CHECK FOR NULL POINTER CASE

void test_little_to_big32_invalid_pointers() 
{
  enum test_status status = TEST_SUCCEED;
  uint32_t * set=NULL;
  uint32_t * ptra;
   ptra = &set[0];
  status=little_to_big32(ptra, TEST_MEMMOVE_LENGTH);

  assert_int_equal(status,TEST_ERROR_INVALID_POINTERS);
  }

 //TO CHECK FOR NULL POINTER CASE 
void test_big_to_little32_invalid_pointers()
{ 
  enum test_status status = TEST_SUCCEED;
  uint32_t * set=NULL;
  uint32_t * ptra;
   ptra = &set[0];
  status=big_to_little32(ptra, TEST_MEMMOVE_LENGTH);
  assert_int_equal(status,TEST_ERROR_INVALID_POINTERS);
}
//TO CHECK IF THE BIG TO LITTLE ENDIAN IS WORKING CORRECTLY OR NOT

void test_big_to_little32_check_set() {
  enum test_status status = TEST_SUCCEED;
  uint32_t * set =0x12345678;
  uint32_t * ptra=0x78563412;
  big_to_little32(ptra,32);
  if(*set==*ptra)
  {
  status=TEST_SUCCEED;
  }
  assert_int_equal(status,TEST_SUCCEED);
  free( (int32_t*)set );
  
}

//TO CHECK IF THE LITTLE TO BIG ENDIAN IS WORKING CORRECTLY OR NOT

void test_little_to_big32_check_set() {
enum test_status status = TEST_SUCCEED;
  uint32_t * set=0x12345678;
  uint32_t * ptra=0x78563412;
  little_to_big32(ptra, 32);
  if(*set==*ptra)
  {
  status=TEST_SUCCEED;
  }
  assert_int_equal(status,TEST_SUCCEED);
  free( (int32_t*)set );

}
