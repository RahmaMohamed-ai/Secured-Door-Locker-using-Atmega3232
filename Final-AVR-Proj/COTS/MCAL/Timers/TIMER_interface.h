/*
 * TIMER_interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: lapshop
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define TIMER0		0
#define TIMER1		1
#define TIMER2		0

/* --------------Function Prototypes -------------- */
void TIMER_vInit(void);
void TIMER_vSetBusyWait_Synch(/*u8 A_u8TimerId,*/ u32 A_u32Ticks);

void TIMERS_vStartTimer(/*u8 A_u8TimerId ,*/ void);
void TIMERS_vStopTimer(/*u8 A_u8TimerId,*/ void);
void TIMERS_vSetCallback(/*u8 A_u8TimerId, */void (*fptr) (void));

void TIMER_vSetPreloadValue(/*u8 A_u8TimerId ,*/ u16 A_u16Preload);
void TIMER_vSetCompareMatchValue(u8 A_u8TimerId, u16 A_u16OcrValue);
void TIMER_vSetICR1(u16 A_16IcrValue);
u16 TIMER_u16GetICR1(void);
u8 TIMERS_u16GetElapstedTime(u8 A_u8TimerId);

void TIMER_vSetICUSenseCTRL(u8 A_u8SenseCtrl);
void TIMER_vDisableInterrupt(u8 A_u8TimerId , u8 A_InterruptSource);
void TIMER_vEnableInterrupt(u8 A_u8TimerId , u8 A_InterruptSource);

/* -------------- Adjust Sense control ---------------- */

#define ICU_RISING			1
#define ICU_FALLING			2


#endif /* TIMER_INTERFACE_H_ */
