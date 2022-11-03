#include "COTS/LIB/STD_TYPES.h"

#include "COTS/MCAL/DIO/DIO_interface.h"


#include "COTS/HAL/LCD/LCD_interface.h"
//#include "COTS/HAL/KEYPAD/KEYPAD_interface.h"

int main(void)
{
	door_state_flag = 0;
	while(1)
	{

		check if x = 0// where x= 0 means dorr is locked


		LCD_vInit();
//		IN Parallel LCD Display steps
		/* 1- Check door state (locked / unlocked) */
			/* if -> True  */
			/* call check password func */
				/* if -> True */
					/* call servo change angle to unlock the door*/
					/* call change door status */

				/* if -> false 3 times */
				/* Call block func */
					/* freeze 10sec - KeyPad Disable */
				/*  */
	}
}
