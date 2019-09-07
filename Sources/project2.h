/*
 * project2.h
 *
 *  Created on: Oct 20, 2017
 *      Author: srika
 */

#ifndef SOURCES_PROJECT2_H_
#define SOURCES_PROJECT2_H_

#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <MKL25Z4.H>
#include"CircBuf.h"
#include"uart.h"
#include "conversion.h"
#include"memory.h"
#define RX_CIRBUF_SIZE 40
#define TX_CIRBUF_SIZE 250
#define ITOA_STRINGSIZE 5
void project2();


typedef struct{
	uint8_t Alphabets;
	uint8_t Numerics;
	uint8_t punctuation;
	uint8_t Misc;
}Statistic;

void Dump_data(Statistic* Stat);
#endif /* SOURCES_PROJECT2_H_ */
