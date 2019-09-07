#ifndef __memory_H__
#define __memory_H__

#include <math.h>


#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#define DATA_SET_SIZE_W (10)
#define MEM_SET_SIZE_B  (32)
#define MEM_SET_SIZE_W  (8)
#define MEM_ZERO_LENGTH (16)

#define TEST_MEMMOVE_LENGTH (16)
#define TESTCOUNT           (8)

enum test_status{
TEST_ERROR_INVALID_POINTERS,
TEST_SUCCEED,
TEST_ERROR
}status;

void test_memmove_invalid_pointers() ;
void test_memcpy_invalid_pointers();
void test_memzero_invalid_pointers();
void test_reverse_invalid_pointers();
void test_memmove_no_overlap();
void test_memmove_src_in_dst();
void test_memmove_dst_in_src();
void test_memcpy_check_set();
void test_memzero_check_set();
void test_reverse_even_check_set();
void test_reverse_odd_check_set();
void test_reverse_character_check_set();



/*Function for memory moving*/
uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length);

/*Function for copying of data*/
uint8_t *my_memcpy(uint8_t *src,uint8_t *dst,size_t length);

/*Function to set memory values*/

int8_t *my_memset(uint8_t *src,size_t length, uint8_t value);

/*Function to set all memory locations to Zero*/

uint8_t *my_memzero(uint8_t *src, size_t length);

/*Funtion for Reversing*/

uint8_t *my_reverse(uint8_t *src,size_t length);

/*Function for reserving of memory for words*/
int32_t *reserve_words(size_t length);

/*Function to free memory locations*/
void free_words(int32_t *src);

#endif /*__memory_H__*/
