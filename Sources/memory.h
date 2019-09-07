/*
 * memory.h
 *
 *  Created on: Oct 29, 2017
 *      Author: srika
 */

#ifndef SOURCES_MEMORY_H_
#define SOURCES_MEMORY_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


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




#endif /* SOURCES_MEMORY_H_ */
