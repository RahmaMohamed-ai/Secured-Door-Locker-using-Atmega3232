/*
 * TIMER_config.h
 *
 *  Created on: Sep 24, 2022
 *      Author: lapshop
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/* ------------- Timer0 Enables & Specs select --------------- */
#define TIMER0_ENABLE		DISABLE
#define TIMER0_PRELOAD		0
#define TIMER0_PRESCALER	PS_8

/* ------------- Timer1 Enables & Specs select --------------- */

#define TIMER1_ENABLE		ENABLE
#define TIMER1_PRESCALER	PS_265

/* ------------- Timer2 Enables & Specs select --------------- */

#define TIMER2_ENABLE		DISABLE
#define TIMER2_PRESCALER	PS_265

/* ------------------------------------------------------------- */
#define FADE				0
#define SERVO				0  // Servo motor Activation

#endif /* TIMER_CONFIG_H_ */
