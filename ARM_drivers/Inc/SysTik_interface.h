/*
 * SysTik_interface.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Mostafa_Salem
 */

#ifndef SYSTIK_INTERFACE_H_
#define SYSTIK_INTERFACE_H_

void SysTik_voidInitialize();
void SysTik_voidDelay_ms(u32 A_u32Time_ms);
u32 SysTik_u32GetElapsedTime_ms();
u32 SysTik_u32GetRemainingTime_ms();
void SysTik_voidSetIntervalms_Single(u32 A_u32Time_ms,void(*ptr)(void));
void SysTik_voidSetIntervalms_Periodic(u32 A_u32Time_ms,void(*ptr)(void));
void SysTik_voidStopTimer(void);

#endif /* SYSTIK_INTERFACE_H_ */
