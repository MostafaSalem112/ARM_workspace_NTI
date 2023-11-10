/*
 * SysTik_private.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Mostafa_Salem
 */

#ifndef SYSTIK_PRIVATE_H_
#define SYSTIK_PRIVATE_H_


#define AHB_PRESCALER		8
#define MILLIS_IN_SECOND	1000
#define ZERO				0

/***************************************************************************/
#define SysTik_DISABLE		0
#define SysTik_ENABLE		1
/***************************************************************************/

/***************************************************************************/
#define ENABLE		0
#define TICK_INT	1
#define CLKSOURCE	2
#define COUNTFLAG	16
/***************************************************************************/

/***************************************************************************/
#define AHB_CLOCK_DIV_8		0
#define AHB_CLOCK			1
/***************************************************************************/

/***************************************************************************/
#define SysTik_BASE_ADDRESS			0xE000E010

typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}SysTik_t;

#define SysTik		((volatile SysTik_t*)(SysTik_BASE_ADDRESS))
/***************************************************************************/

#endif /* SYSTIK_PRIVATE_H_ */
