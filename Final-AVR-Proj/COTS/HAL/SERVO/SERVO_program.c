/*
 * SERVO_program.c
 *
 *  Created on: Nov 2, 2022
 *      Author: lapshop
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/Timers/TIMER_interface.h"

#include "SERVO_interface.h"


void SERVO_vInit(void)
{
	/* 2- Set fast PWM */


	/* Calculating Top value to have 50HZ in PWM PIN */
	u16 L_u16TopValue = ((F_CPU)/50*PRESCALER_VAL)-1;

	/* 3- store top value in icr1 */
	TIMER_vSetICR1(19999);

	/* 4- Set Preload value to zero */
	TIMER_vSetPreloadValue(TIMER1 , 0);

	/* 5- Set PWM Pin as output */
	DIO_vWritePinDirection(DIO_PORTB, DIO_PIN3 ,DIO_HIGH);
}
void SERVO_vSetAngle(u8 A_u8Angle)
{
	TIMERS_vSetCompareMatchValue(TIMER1 , 1600 );

	TIMER_vSetBusyWait_Synch();

}

