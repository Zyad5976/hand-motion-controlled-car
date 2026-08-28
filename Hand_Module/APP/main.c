/*
 * Project_2.c
 *
 * Created: 8/7/2026 6:40:03 PM
 * Author : Eltawel
 */ 

#include "main.h"

int main(void)
{
	TIM0_voidInit();
	UART_voidInit();
	TWI_voidMasterInit();
	MPU_voidInit();
	
	s16 Loc_status_X = 0;

	s16 Loc_status_Z = 0;
	
	
	u8 Loc_command = 0;
	
	
    while (1) 
    {
		Loc_status_X = MPU_s16GetRawAccelX();
		Loc_status_Z = MPU_s16GetRawAccelZ();
		
		if(Loc_status_Z > 2500) // Virtual Threshold
		{
			Loc_command = 'F';
		}
		
		else if(Loc_status_Z < -2500) // Virtual Threshold
		{
			Loc_command = 'B';
		}
		
		else if(Loc_status_X > 2500) // Virtual Threshold
		{
			Loc_command = 'R';
		}
		
		else if(Loc_status_X < -2500) // Virtual Threshold
		{
			Loc_command = 'L';
		}
		
		else
		{
			Loc_command = 'S';
		}
		
		UART_voidSendData(Loc_command);
		
    }
}

