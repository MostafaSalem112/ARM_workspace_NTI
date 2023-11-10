#include "STD_Types.h"
#include "Bit_Math.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"


void RCC_voidInitialize(){
	
#if HSI_CLOCK_STATUS == RCC_ENABLE
	SET_BIT(RCC->CR,HSION);
	while(!GET_BIT(RCC->CR,HSIRDY));
#endif
#if HSE_CLOCK_STATUS == RCC_ENABLE
	SET_BIT(RCC->CR,HSEON);
	while(!GET_BIT(RCC>CR,HSERDY));
	RCC->CR |= (External_high_speed_clock_bypass<<HSEBYP);
#endif
#if PLL_CLOCK_STATUS == RCC_ENABLE
	SET_BIT(RCC->CR,PLLON);
	while(!GET_BIT(RCC>CR,PLLRDY));
	RCC->CFGR |= (PLL_MUL_FACTOR<<PLLMUL);
	RCC->CFGR |= (HSE_divider_for_PLL<<PLLXTPRE);
	RCC->CFGR |= (PLL_SOURCE<<PLLSRC);
#endif

	RCC->CR |= (Clock_security_system_STATUS<<CSSON);

	RCC->CFGR |= (MCO_SOURCE<<MCO);
	RCC->CFGR |= (USB_PRESCALER<<USBPRE);

	RCC->CFGR |= (ADC_PRESCALER<<ADCPRE);
	RCC->CFGR |= (APB2_PRESCALER<<PPRE2);
	RCC->CFGR |= (APB1_PRESCALER<<PPRE1);
	RCC->CFGR |= (AHB_PRESCALER<<HPRE);

	RCC->CFGR |= (CLOCK_SOURCE<<SW);
	while(((RCC->CFGR>>SWS)&0b11) != CLOCK_SOURCE);
}

void RCC_vEnablePeripheralClock(u8 Copy_u8Bus,u8 Copy_u8preipheral){

	switch(Copy_u8Bus){
		case RCC_AHB:
			SET_BIT(RCC->AHBENR,Copy_u8preipheral);
			break;
		case RCC_APB1:
			SET_BIT(RCC->APB1ENR,Copy_u8preipheral);
			break;
		case RCC_APB2:
			SET_BIT(RCC->APB2ENR,Copy_u8preipheral);
			break;
	}
}

void RCC_vDisablePeripheralClock(u8 Copy_u8Bus,u8 Copy_u8preipheral){

	switch(Copy_u8Bus){
		case RCC_AHB:
			CLR_BIT(RCC->AHBENR,Copy_u8preipheral);
			break;
		case RCC_APB1:
			CLR_BIT(RCC->APB1ENR,Copy_u8preipheral);
			break;
		case RCC_APB2:
			CLR_BIT(RCC->APB2ENR,Copy_u8preipheral);
			break;
	}
}
