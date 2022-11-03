/*
 * SERVO_interface.h
 *
 *  Created on: Sep 28, 2022
 *      Author: lapshop
 */

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#define F_CPU			8000000//HZ
#define PRESCALER_VAL	8
/*-----------------------------------------*/

void SERVO_vInit(void);
void SERVO_vSetAngle(u8 A_u8Angle);

#endif /* SERVO_INTERFACE_H_ */
