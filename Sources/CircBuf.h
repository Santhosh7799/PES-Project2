/*
 * CircBuf.h
 *
 *  Created on: Oct 28, 2017
 *      Author: srika
 */

#ifndef SOURCES_CIRCBUF_H_
#define SOURCES_CIRCBUF_H_

#define MAX_BUFFER_LENGTH 10
#include <stdint.h>
#include <stdlib.h>


typedef struct{

uint8_t *buffer;
uint8_t *Head;
uint8_t *Tail;
uint8_t size;
uint8_t count;
}CB_t;

typedef enum{

Buffer_Full,
Buffer_Empty,
Success,
Null_Error,
Buffer_Outside,
Buffer_Notfull,
Buffer_Notempty,
Buffer_Fail,
peekpos_Error

}CB_status;


/* Function prototypes */
CB_status CB_init(CB_t *buffer, uint8_t length);
CB_status CB_is_empty(CB_t *buffer);
CB_status CB_is_Full(CB_t *buffer);
CB_status CB_buffer_add_item(CB_t *buffer, uint8_t data);
CB_status CB_buffer_remove_item(CB_t *buffer, uint8_t *data);

CB_status CB_destroy(CB_t *buffer);
CB_status CB_peek(CB_t *buffer, uint32_t position, uint8_t* data);
//uint8_t calcLength(C_Buffer * c_buffer);

#endif /* SOURCES_CIRCBUF_H_ */
