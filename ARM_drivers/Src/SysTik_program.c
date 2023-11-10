/*
 * SysTik_program.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Mostafa_Salem
 */
#include "STD_Types.h"
#include "Bit_Math.h"
#include "SysTik_private.h"
#include "SysTik_config.h"
#include "SysTik_interface.h"

void (*SysTik_GPFun)(void);
u8 L_u8PeriodicFlag;

void SysTik_voidInitialize(){

	SysTik->CTRL |= (SysTik_CLOCK_SOURCE << CLKSOURCE);

	SysTik->CTRL |= (SysTik_INTERRUPT_STATUS << TICK_INT);
}

void SysTik_voidDelay_ms(u32 A_u32Time_ms){
	u32 L_TimerFrequency;
	f32 L_TickTime;
	u32 L_Tick_No;

	switch(SysTik_CLOCK_SOURCE){
	case AHB_CLOCK:
		L_TimerFrequency = SysTik_AHB_CLOCK;
		break;
	case AHB_CLOCK_DIV_8:
		L_TimerFrequency = SysTik_AHB_CLOCK/AHB_PRESCALER;
		break;
	}

	L_TickTime = MILLIS_IN_SECOND/(f32)L_TimerFrequency;
	L_Tick_No = A_u32Time_ms/L_TickTime;

	SysTik->LOAD = L_Tick_No;
	SysTik->VAL = ZERO;

	SET_BIT(SysTik->CTRL,ENABLE);

	while(!(GET_BIT(SysTik->CTRL,COUNTFLAG)));

	CLR_BIT(SysTik->CTRL,ENABLE);
}

u32 SysTik_u32GetElapsedTime_ms(void){
	u32 L_TimerFrequency;
	f32 L_TickTime;
	u32 L_ElapsedTick_No;
	u32 L_ElapsedTime;
	u32 L_Load;
	u32 L_Value;

	switch(SysTik_CLOCK_SOURCE){
	case AHB_CLOCK:
		L_TimerFrequency = SysTik_AHB_CLOCK;
		break;
	case AHB_CLOCK_DIV_8:
		L_TimerFrequency = SysTik_AHB_CLOCK/AHB_PRESCALER;
		break;
	}
	L_TickTime = MILLIS_IN_SECOND/(f32)L_TimerFrequency;

	L_Load = SysTik->LOAD;
	L_Value = SysTik->VAL;
	L_ElapsedTick_No = L_Load - L_Value;
	L_ElapsedTime = L_ElapsedTick_No*L_TickTime;

	return	L_ElapsedTime;
}

u32 SysTik_u32GetRemainingTime_ms(void){
	u32 L_TimerFrequency;
	f32 L_TickTime;
	u32 L_RemainingTick_No;
	u32 L_RemainingTime;

	switch(SysTik_CLOCK_SOURCE){
	case AHB_CLOCK:
		L_TimerFrequency = SysTik_AHB_CLOCK;
		break;
	case AHB_CLOCK_DIV_8:
		L_TimerFrequency = SysTik_AHB_CLOCK/AHB_PRESCALER;
		break;
	}
	L_TickTime = MILLIS_IN_SECOND/(f32)L_TimerFrequency;

	L_RemainingTick_No = SysTik->VAL;
	L_RemainingTime = L_RemainingTick_No*L_TickTime;

	return	L_RemainingTime;
}

void SysTik_voidSetIntervalms_Single(u32 A_u32Time_ms,void(*ptr)(void)){
	u32 L_TimerFrequency;
	f32 L_TickTime;
	u32 L_Tick_No;

	CLR_BIT(SysTik->CTRL,ENABLE);
	L_u8PeriodicFlag = 0;

	switch(SysTik_CLOCK_SOURCE){
	case AHB_CLOCK:
		L_TimerFrequency = SysTik_AHB_CLOCK;
		break;
	case AHB_CLOCK_DIV_8:
		L_TimerFrequency = SysTik_AHB_CLOCK/AHB_PRESCALER;
		break;
	}
	L_TickTime = (f32)MILLIS_IN_SECOND/(f32)L_TimerFrequency;
	L_Tick_No = A_u32Time_ms/L_TickTime;

	SysTik->LOAD = L_Tick_No;
	SysTik->VAL = ZERO;

	SysTik->CTRL |= (SysTik_INTERRUPT_STATUS << TICK_INT);
	SET_BIT(SysTik->CTRL,ENABLE);
	SysTik_GPFun = ptr;
}

void SysTik_voidSetIntervalms_Periodic(u32 A_u32Time_ms,void(*ptr)(void)){
	u32 L_TimerFrequency;
	f32 L_TickTime;
	u32 L_Tick_No;

	CLR_BIT(SysTik->CTRL,ENABLE);
	L_u8PeriodicFlag = 1;

	switch(SysTik_CLOCK_SOURCE){
	case AHB_CLOCK:
		L_TimerFrequency = SysTik_AHB_CLOCK;
		break;
	case AHB_CLOCK_DIV_8:
		L_TimerFrequency = SysTik_AHB_CLOCK/AHB_PRESCALER;
		break;
	}
	L_TickTime = (f32)MILLIS_IN_SECOND/(f32)L_TimerFrequency;
	L_Tick_No = A_u32Time_ms/L_TickTime;

	SysTik->LOAD = L_Tick_No;
	SysTik->VAL = ZERO;

	SysTik->CTRL |= (SysTik_INTERRUPT_STATUS << TICK_INT);
	SET_BIT(SysTik->CTRL,ENABLE);
	SysTik_GPFun = ptr;
}

void SysTik_voidStopTimer(void){
	CLR_BIT(SysTik->CTRL,ENABLE);
}

void SysTick_Handler(void){
	if(SysTik_GPFun != NULL){
		SysTik_GPFun();
		if(L_u8PeriodicFlag == 0){
			CLR_BIT(SysTik->CTRL,ENABLE);
		}
	}
}
