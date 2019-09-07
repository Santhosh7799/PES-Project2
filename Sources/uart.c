/*
 * uart.c
 *
 *  Created on: Oct 20, 2017
 *      Author: srikant & Santhosh
 */


#include <MKL25Z4.H>
#include "uart.h"
#include<stdbool.h>
#include "project2.h"


uint8_t RData;
uint8_t TData;
extern CB_status T_Status;
extern CB_status R_Status;
extern CB_t R_Buff;
extern CB_t T_Buff;
void UART_configure()
{

		   uint16_t tmp;
		   UART_Stat Status=0;


		   SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
		   SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
		   UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);
		   SIM->SOPT2 &= ~(SIM_SOPT2_PLLFLLSEL_MASK);
		   SIM->SOPT2 |= SIM_SOPT2_PLLFLLSEL(1);
		   SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);
		   PORTA->PCR[1]= PORT_PCR_MUX(0x2);
		   PORTA->PCR[2]= PORT_PCR_MUX(0x2);
		   tmp = 48000000 / (115200*16);
		   UART0->BDH &= ~UARTLP_BDH_SBR_MASK;
		   UART0->BDH |= UARTLP_BDH_SBR((tmp>>8));
		   UART0->BDL &= ~UARTLP_BDL_SBR_MASK;
		   UART0->BDL |= UARTLP_BDL_SBR(tmp);
		   UART0->C4 = UART0_C4_OSR(15);
		   UART0->S2 = 0x00;
		   UART0->C1 = 0x00;
		   UART0->C3 = 0x00;
		   UART0->C5 = 0x00;
		   UART0->C2 = UART_C2_RIE_MASK;
		   NVIC_EnableIRQ(UART0_IRQn);
		   UART0->C2 |= UARTLP_C2_RE_MASK | UARTLP_C2_TE_MASK;
		   Status=Success;
		   return Status;

}

UART_Stat UART_receive(uint8_t *a)
{
	UART_Stat stat;
    if(a!=NULL)
    {
    *a= UART0->D;
    stat = UART_Success;
    }
    else
    {
    stat = UART_Null_Error;
    }
return stat;
}

UART_Stat UART_Send(uint8_t* ch)
{
	UART_Stat stat;

    if(ch!=NULL)
    {
    UART0->D = *ch;
    stat = UART_Success;
    }
    else
    {
    	stat = UART_Null_Error;
    }
    return stat;
}

UART_Stat UART_send_n(uint8_t *str, uint8_t length)
{
	UART_Stat stat;
	uint8_t i = 0;
 if(str!=NULL)
 {
	for (i=0; i<length; i++)
	{
		UART0->D = *(str+i);

	}
	stat = UART_Success;
 }
 else
 {
	 stat = UART_Null_Error;
 }
 return stat;
}

UART_Stat UART_receive_n(uint8_t *str, uint8_t length)
{
	UART_Stat stat;
	uint8_t i;
	if(str!= NULL)
	{
	   for(i=0; i<length; i++)
	   {
		   *(str+i)= UART0->D;
	   }
	   stat = UART_Success;
	}
	else
	{
		stat = UART_Null_Error;
	}
	return stat;
}

void UART0_IRQHandler (void)
{
	if(((UART0->S1) & UART0_S1_RDRF_MASK)>>UART0_S1_RDRF_SHIFT == 0x01)
	{
	    UART_receive(&RData);
	    CB_buffer_add_item(&R_Buff, RData);
	}
	else if( ( ((UART0->S1)&UART0_S1_TDRE_MASK)>>UART0_S1_TDRE_SHIFT) ==0x1)
	{
		T_Status = CB_buffer_remove_item(&T_Buff, &TData);
		if(T_Status == Success)
	    {
	    	UART_Send(&TData);
	    }
	else
	    {
		UART0->C2 &= ~UART_C2_TIE_MASK;
	    }
	}
	else
	{

	}
}
