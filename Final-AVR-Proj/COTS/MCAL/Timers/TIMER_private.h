/*
 * TIMER_private.h
 *
 *  Created on: Sep 24, 2022
 *      Author: lapshop
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/* ----------- Timers Registers ----------- */
/*----- TIMER0 ------*/
#define TCCR0	(*(volatile u8*)(0x53))
#define TCNT0	(*(volatile u8*)(0x52))
#define OCR0	(*(volatile u8*)(0x5C))
#define TIMSK	(*(volatile u8*)(0x59))
#define TIFR	(*(volatile u8*)(0x58))

/*----- TIMER1 ------*/

#define TCCR1A  *((volatile u8*)(0x4F))
#define TCCR1B  *((volatile u8*)(0x4E))
#define TCNT1	*((volatile u16*)(0x4C))
#define OCR1A   *((volatile u16*)(0x4A))
#define OCR1B	*((volatile u16*)(0x48))
#define ICR1	*((volatile u16*)(0x46))

/*----- TIMER2 ------*/

#define TCCR2  	*((volatile u8*)(0x45))
#define TCNT2	*((volatile u16*)(0x44))
#define OCR2   	*((volatile u16*)(0x43))


/*---------------- Activate Certain Timer ---------------*/

#define	ENABLE		1
#define	DISABLE		0

/* ------------------ Registers Used Bits -------------- */

/* TIMER0 REGs */
#define TCCR0_WGM00		6
#define TCCR0_WGM01		3
#define TCCR0_COM00		4
#define TCCR0_COM01		5
#define TIMSK_TOV0		0
#define TIMSK_OCIE0		1

#define TIMSK_TICIE1_BIT		5//bit that controls EN/DIS interrupt

/* TIMER1 REGs */
#define TCCR1B_WGM13		4
#define TCCR1B_WGM12		3
#define TCCR1A_WGM11		1
#define TCCR1A_WGM10		0

#define  TCCR1B_ICES1_BIT		6


/* TIMER2 REGs */

//#define TCCR1B_WGM13		4
//#define TCCR1B_WGM12		3
//#define TCCR1A_WGM11		1
//#define TCCR1A_WGM10		0

/* ----------------- PreScaller Adjustment ------------------ */

#define PS_NOCLK	0b000
#define PS_1		0b001
#define PS_8		0b010
#define PS_265      0b100



#endif /* TIMER_PRIVATE_H_ */
