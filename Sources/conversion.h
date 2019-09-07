/*
 * conversion.h
 *
 *  Created on: Oct 29, 2017
 *      Author: srika
 */

#ifndef SOURCES_CONVERSION_H_
#define SOURCES_CONVERSION_H_


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/*Integer to ASCII conversion function*/
uint8_t my_itoa(int32_t data, char *ptr, uint32_t base);

/*ASCII to Integer conversion function*/
int32_t my_atoi(uint8_t *ptr,uint8_t digits,uint32_t base);

/*converting big endian to little endian*/
int8_t big_to_little32(uint32_t *data,uint32_t length);

/*converting little endian to big endian*/
int8_t little_to_big32(uint32_t *data,uint32_t length);




#endif /* SOURCES_CONVERSION_H_ */
