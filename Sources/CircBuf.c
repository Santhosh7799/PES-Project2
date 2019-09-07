/*
 * CircBuf.c
 *
 *  Created on: Oct 28, 2017
 *      Author: srikant
 */

#include "CircBuf.h"
#include "uart.h"
#define TEMP_BUFFER_LENGTH 40
uint8_t temp_buffer[TEMP_BUFFER_LENGTH];


CB_status CB_init(CB_t *buffer, uint8_t length)
{


if(buffer!= NULL)
{
	buffer->buffer = (uint8_t*) malloc (length);
	if((buffer->buffer)!=NULL)
	{
	buffer->Head = buffer->buffer;
	buffer->Tail = buffer->buffer;
	buffer->size = length;
	buffer->count = 0;
	return Success;
	}
	else
	{
		return Buffer_Fail;
	}
}
else
{
	return Null_Error;
}
}


CB_status CB_peek(CB_t *buffer, uint32_t position, uint8_t* data)
{
uint8_t*  Cbuff_peekpos;
uint8_t* offset;

if((buffer!=NULL)||((buffer->buffer)!=NULL))
{
    if((buffer->Tail)<(buffer->Head))
    {
    	Cbuff_peekpos = ((buffer->Head)-position);
    	if(Cbuff_peekpos<(buffer->buffer))
    	{
    		*data = *(Cbuff_peekpos);
    		return Success;
    	}
    	else
    	{
    		return peekpos_Error;
    	}
    }
    else if((buffer->Tail)>(buffer->Head))
    {
    	Cbuff_peekpos = ((buffer->Head)-position);
    	if(Cbuff_peekpos<(buffer->buffer))
    	{
    		*data = *(Cbuff_peekpos);
    	    return Success;
    	}
    	else
    	{
    		offset = (uint8_t*) ((buffer->buffer)-Cbuff_peekpos);
    		*data = *((uint8_t*)(((buffer->buffer)+(buffer->size))-offset));
    	    return Success;
    	}
    }
    else
    {
    	return Buffer_Empty;
    }
}

else
{
	return Null_Error;
}


}

CB_status CB_is_Full(CB_t *buffer)
{
if((buffer!=NULL)||((buffer->buffer)!=NULL))
{
	if((buffer->count) == (buffer->size))
	{
		return Buffer_Full;
	}
	else
	{
		return Buffer_Notfull;
	}
}
else
{
	return Null_Error;
}

}

CB_status CB_is_empty(CB_t *buffer)
{
	if((buffer!=NULL)||((buffer->buffer)!=NULL))
	{
		if((buffer->count) == 0)
		{
			return Buffer_Empty;
		}
		else
		{
			return Buffer_Notempty;
		}
	}
	else
	{
		return Null_Error;
	}

}

CB_status CB_buffer_add_item(CB_t *buffer, uint8_t data)
{
if ((buffer!=NULL)||(buffer->buffer)!=NULL)
  {
	if((buffer->count) == (buffer->size))
	{
      return Buffer_Full;
	}
	else if( (buffer->Head) < ((buffer->buffer)+((buffer->size)-1)))
    {
      *(buffer->Head)=data;
      (buffer->Head)++;
      (buffer->count)++;
      return Success;
    }
	else if((buffer->Head) == ((buffer->buffer)+((buffer->size)-1)))
	{
		*(buffer->Head) = data;
		buffer->Head = buffer->buffer;
		(buffer->count)++;
		return Success;
	}
	else
	{
		return Buffer_Outside;
	}

  }
else{
	return Null_Error;

}
}

CB_status CB_buffer_remove_item(CB_t *buffer, uint8_t *data)
{
	if ((buffer!=NULL)||(buffer->buffer)!=NULL)
	  {
		if((buffer->count) == 00)
		{
	      return Buffer_Empty;
		}
		else if( (buffer->Tail) < ((buffer->buffer)+((buffer->size)-1)))
	    {
	      *data = *(buffer->Tail);
	      (buffer->Tail)++;
	      (buffer->count)--;
	      return Success;
	    }
		else if((buffer->Tail) == ((buffer->buffer)+((buffer->size)-1)))
		{
			*data = *(buffer->Tail);
			(buffer->Tail) = buffer->buffer;
			(buffer->count)--;
			return Success;
		}
		else
		{
			return Buffer_Outside;
		}
	  }
	else
	{
		return Null_Error;
	}

}

CB_status CB_destroy(CB_t *buffer)
{
free(buffer->buffer);
return Success;
}

