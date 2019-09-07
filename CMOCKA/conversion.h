
#ifndef __conversion_H__
#define __conversion_H__

#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "memory.h"
#define TEST_MEMMOVE_LENGTH (16)
#define TESTCOUNT           (8)
void test_little_to_big32_invalid_pointers() ;
void test_big_to_little32_invalid_pointers();
void test_big_to_little32_check_set() ;
void test_little_to_big32_check_set();




/*Integer to ASCII conversion function*/
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);

/*ASCII to Integer conversion function*/
int32_t my_atoi(uint8_t *ptr,uint8_t digits,uint32_t base);

/*converting big endian to little endian*/
int8_t big_to_little32(uint32_t *data,uint32_t length);

/*converting little endian to big endian*/
int8_t little_to_big32(uint32_t *data,uint32_t length);


#endif
