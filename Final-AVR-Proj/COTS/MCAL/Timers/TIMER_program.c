#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"

static void (*TIMER_OVF_Callback) (void);
static void (*TIMER_CTC_Callback) (void);
static void (*TIMER_ICU_Callback) (void);

void TIMER_vInit(void)
{
#if TIMER0_ENABLE == ENABLE
	/* 1- Select wave gerenation mode*/
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	CLR_BIT(TCCR0 , TCCR0_WGM01);

	/* 2- Output compare mode */
	CLR_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);

	/* 3- Preload */
	TCNT0 = TIMER0_PRELOAD;

	/* 4-Interrupt EN/DIS */
//	SET_BIT(TIMSK, TIMSK_TOV0);
//	SET_BIT(TIMSK, TIMSK_OCIE0);

	/* PWM: Disable Interrupts */
#endif
#if TIMER1_ENABLE == ENABLE

	SET_BIT(TCCR1B, TCCR1B_WGM13); //WGM13
	SET_BIT(TCCR1B, TCCR1B_WGM12); //WGM12
	SET_BIT(TCCR1A, TCCR1A_WGM11); //WGM11
	CLR_BIT(TCCR1A, TCCR1A_WGM10); //WGM10

#endif
#if TIMER2_ENABLE == ENABLE
#endif

}
void TIMER_vSetBusyWait_Synch(u8 A_u8TimerId,u32 A_u32Ticks)
{

}

void TIMERS_vStartTimer(u8 A_u8TimerId)
{

	TCCR0  = 0b01101010; //
	TCCR1A = 0b00000000; // Normal Mode
	TCCR1B = 0b01000010;
	TIMSK  = 0b00000010; // Overflow Interrupt Mode
//	switch(A_u8TimerId)
//	{
//	case TIMER0 :
//		TCCR0 = (TCCR0 & ~(0b111) | (TIMER0_PRESCALER));
//		break;
//
//	case TIMER1 :
//		TCCR1B = (TCCR1B & ~(0b111)) | (TIMER1_PRESCALER) ;
//		break;
}
void TIMERS_vStopTimer(u8 A_u8TimerId)
{
	switch(A_u8TimerId)
	{
	case TIMER0 :
		TCCR0 = (TCCR0 & ~(0b111) | (PS_NOCLK));
		break;

	case TIMER1 :
		TCCR1B = (TCCR1B & ~(0b111)) | (PS_NOCLK) ;
		break;
}

void TIMER_vSetPreloadValue(u8 A_u8TimerId, u16 A_u16Preload)
{
	switch(A_u8TimerId)
	{
	case TIMER0 :
		TCNT0 = A_u16Preload;
		break;

	case TIMER1:
		TCNT1 = A_u16Preload;
		break;
	}
}
}

void TIMERS_vSetCompareMatchValue(u8 A_u8TimerId, u16 A_u16OcrVal    )
{
	switch(A_u8TimerId)
	{
	case TIMER0:
		OCR0 = A_u16OcrVal ;
		break;

	case TIMER1:
		OCR1A = A_u16OcrVal ;
		break;
	}

}

void TIMER_vSetICR1(u16 A_16IcrValue)
{
	ICR1 = A_16IcrValue;
}

u16 TIMER_u16GetICR1(void)
{
	return ICR1;
}

void TIMERS_vSetCallback(/* TimerId , */void (*fptr) (void))
{
//	TIMER_OVF_Callback = fptr;
	TIMER_ICU_Callback = fptr;
}

void __vector_6(void)__attribute__((signal));
void __vector_6(void)
{
	if( TIMER_CTC_Callback != NULL)
	{
		TIMER_CTC_Callback();
	}
}

void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	if( TIMER_OVF_Callback != NULL)
	{
		TIMER_OVF_Callback();
	}
}

void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	if( TIMER_CTC_Callback != NULL)
	{
		TIMER_CTC_Callback();
	}
}



u8 TIMERS_u16GetElapstedTime(u8 A_u8TimerId)
{
	u16 L_u16TimerValue = 0;
	switch(A_u8TimerId)
	{
	case TIMER0 :
		L_u16TimerValue = A_u8TimerId;
		break;

	case TIMER1 :
		L_u16TimerValue = A_u8TimerId;
		break;
	}
	return L_u16TimerValue;
}

void TIMER_vSetICUSenseCTRL(u8 A_u8SenseCtrl)
{
	switch(A_u8SenseCtrl)
	{
	case ICU_RISING:
		SET_BIT(TCCR1B, TCCR1B_ICES1_BIT); //ICES1
		break;
	case ICU_FALLING:
		CLR_BIT(TCCR1B, TCCR1B_ICES1_BIT); //ICES1
		break;
	}
}

void TIMER_vEnableInterrupt(u8 A_u8TimerId , u8 A_InterruptSource)
{
	switch(A_InterruptSource)
	SET_BIT(TIMSK , TIMSK_TICIE1_BIT);//TICIE1
}

void TIMER_vDisableInterrupt(u8 A_u8TimerId , u8 A_InterruptSource)
{
	CLR_BIT(TIMSK , TIMSK_TICIE1_BIT);
}
