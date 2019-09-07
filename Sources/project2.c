/*
 * project2.c
 *
 *  Created on: Oct 20, 2017
 *      Author: srikant & Santhosh
 */

#include "project2.h"

Statistic Dump_Stat;
CB_t R_Buff;
CB_t T_Buff;
extern uint8_t RData;
extern uint8_t TData;

CB_status T_Status;
CB_status R_Status;


char Table[] = "\r\nStatistics";
char Alphabets[] = "\r\nNo. of Alphabets\t";
char Numerics[]= "\r\nNo. of numerics\t\t";
char punctuations[]= "\r\nNo. of punctuations\t";
char misc[]= "\r\nNo. of Miscellaneous char\t";


uint8_t itoa_bufalpha[ITOA_STRINGSIZE];
uint8_t itoa_bufnum[ITOA_STRINGSIZE];
uint8_t itoa_bufpunc[ITOA_STRINGSIZE];
uint8_t itoa_bufmisc[ITOA_STRINGSIZE];



void project2()
{
uint8_t data;
SystemInit();
UART_configure();
CB_init(&R_Buff, RX_CIRBUF_SIZE);
CB_init(&T_Buff, TX_CIRBUF_SIZE);


while(1)
{

	R_Status = CB_buffer_remove_item(&R_Buff, &data);

	if(R_Status==Success)
	{
		if((data>=48)&&(data<=57))
		{
			(Dump_Stat.Numerics)++;
			data=0;
		}
		else if(((data>=65)&&(data<=90))||((data>=97)&&(data<=122)))
		{
			((Dump_Stat.Alphabets)++);
			data=0;
		}
		else if(data==27)
		{
			Dump_data(&Dump_Stat);
			data=0;
		}
		else if((data==33)||(data=34)||((data==39)&&(data==47)))
		{
			(Dump_Stat.punctuation)++;
			data=0;
		}
		else
		{
			(Dump_Stat.Misc)++;
			data=0;
		}
	}



}

}

void Dump_data(Statistic* Stat)
{
uint32_t i=0;
uint32_t i_A=0;
uint32_t i_B=0;

for (i=0; i<sizeof(Table); i++)
{
	CB_buffer_add_item(&T_Buff, *(Table+i));
}
for(i_A=0; i_A<sizeof(Alphabets); (i_A)++)
{
	CB_buffer_add_item(&T_Buff, *(Alphabets+i_A));
}

my_itoa((Dump_Stat.Alphabets), itoa_bufalpha, 10);

for (i_B=0; i_B<sizeof(itoa_bufalpha); i_B++)
{
	CB_buffer_add_item(&T_Buff, *(itoa_bufalpha+i_B));
}
//CB_buffer_add_item(&T_Buff, *(itoa_bufalpha+i_B));
for (i=0; i<sizeof(Numerics); i++)
{
	CB_buffer_add_item(&T_Buff, *(Numerics+i));
}
my_itoa((Dump_Stat.Numerics), itoa_bufnum, 10);
for(i=0; i<sizeof(itoa_bufnum); i++)
{
	CB_buffer_add_item(&T_Buff, *(itoa_bufnum+i));
}
//CB_buffer_add_item(&T_Buff, *(itoa_bufnum));

for(i=0; i<sizeof(punctuations); i++)
{
	CB_buffer_add_item(&T_Buff, *(punctuations+i));
}
my_itoa((Dump_Stat.punctuation), itoa_bufpunc, 10);

for(i=0; i<sizeof(itoa_bufpunc); i++)
{
	CB_buffer_add_item(&T_Buff, *(itoa_bufpunc+i));
}
//CB_buffer_add_item(&T_Buff, *(itoa_bufpunc));
for(i=0; i<sizeof(misc);i++)
{
	CB_buffer_add_item(&T_Buff, *(misc+i));
}
my_itoa((Dump_Stat.Misc), itoa_bufmisc, 10);
for(i=0; i<sizeof(itoa_bufmisc); i++)
{
	CB_buffer_add_item(&T_Buff, *(itoa_bufmisc+i));
}
//CB_buffer_add_item(&T_Buff, *(itoa_bufmisc));

Dump_Stat.Numerics =0;
Dump_Stat.Alphabets=0;
Dump_Stat.punctuation = 0;
Dump_Stat.Misc =0;

UART0->C2 |= UART_C2_TIE_MASK;
}
