#include "Bit_Math.h"
#include "STD_Types.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"

void GPIO_voidSetPinMode(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8Direction,u8 A_u8Mode){

	switch(A_u8PortID){
		case GPIO_PORTA:
			if(A_u8PinNo < 8){
				GPIOA->CRL &= ~(FOUR_BITS_HIGH << (A_u8PinNo*NIBBLE_SIZE));
				GPIOA->CRL |= (A_u8Direction << (A_u8PinNo*NIBBLE_SIZE));
				GPIOA->CRL |= (A_u8Mode << ((A_u8PinNo*NIBBLE_SIZE)+2));
			}else{
				A_u8PinNo -= 8;
				GPIOA->CRH &= ~(FOUR_BITS_HIGH << (A_u8PinNo*NIBBLE_SIZE));
				GPIOA->CRH |= (A_u8Direction << (A_u8PinNo*NIBBLE_SIZE));
				GPIOA->CRH |= (A_u8Mode << ((A_u8PinNo*NIBBLE_SIZE)+2));
			}
			break;
		case GPIO_PORTB:
			if(A_u8PinNo < 8){
				GPIOB->CRL &= ~(FOUR_BITS_HIGH << (A_u8PinNo*NIBBLE_SIZE));
				GPIOB->CRL |= (A_u8Direction << (A_u8PinNo*NIBBLE_SIZE));
				GPIOB->CRL |= (A_u8Mode << ((A_u8PinNo*NIBBLE_SIZE)+2));
			}else{
				A_u8PinNo -= 8;
				GPIOB->CRH &= ~(FOUR_BITS_HIGH << (A_u8PinNo*NIBBLE_SIZE));
				GPIOB->CRH |= (A_u8Direction << (A_u8PinNo*NIBBLE_SIZE));
				GPIOB->CRH |= (A_u8Mode << ((A_u8PinNo*NIBBLE_SIZE)+2));
			}
			break;
		case GPIO_PORTC:
			if(A_u8PinNo < 8){
				GPIOC->CRL &= ~(FOUR_BITS_HIGH << (A_u8PinNo*NIBBLE_SIZE));
				GPIOC->CRL |= (A_u8Direction << (A_u8PinNo*NIBBLE_SIZE));
				GPIOC->CRL |= (A_u8Mode << ((A_u8PinNo*NIBBLE_SIZE)+2));
			}else{
				A_u8PinNo -= 8;
				GPIOC->CRH &= ~(FOUR_BITS_HIGH << (A_u8PinNo*NIBBLE_SIZE));
				GPIOC->CRH |= (A_u8Direction << (A_u8PinNo*NIBBLE_SIZE));
				GPIOC->CRH |= (A_u8Mode << ((A_u8PinNo*NIBBLE_SIZE)+2));
			}
			break;
	}
}

u8 GPIO_u8GetPinValue(u8 A_u8PortID,u8 A_u8PinNo){

	u8 data = 0;

	switch(A_u8PortID){
		case GPIO_PORTA:
			data = GET_BIT(GPIOA->IDR,A_u8PinNo);
			break;
		case GPIO_PORTB:
			data = GET_BIT(GPIOB->IDR,A_u8PinNo);
			break;
		case GPIO_PORTC:
			data = GET_BIT(GPIOC->IDR,A_u8PinNo);
			break;
	}

	return data;
}

void GPIO_voidSetPinValue(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8PinValue){

	switch(A_u8PortID){
		case GPIO_PORTA:
			if(A_u8PinValue == GPIO_LOW){
				CLR_BIT(GPIOA->ODR,A_u8PinNo);
			}else if(A_u8PinValue == GPIO_HIGH){
				SET_BIT(GPIOA->ODR,A_u8PinNo);
			}
			break;
		case GPIO_PORTB:
			if(A_u8PinValue == GPIO_LOW){
				CLR_BIT(GPIOB->ODR,A_u8PinNo);
			}else if(A_u8PinValue == GPIO_HIGH){
				SET_BIT(GPIOB->ODR,A_u8PinNo);
			}
			break;
		case GPIO_PORTC:
			if(A_u8PinValue == GPIO_LOW){
				CLR_BIT(GPIOC->ODR,A_u8PinNo);
			}else if(A_u8PinValue == GPIO_HIGH){
				SET_BIT(GPIOC->ODR,A_u8PinNo);
			}
			break;
	}
}

void GPIO_voidTogglePinValue(u8 A_u8PortID,u8 A_u8PinNo){

	switch(A_u8PortID){
		case GPIO_PORTA:
			TOG_BIT(GPIOA->ODR,A_u8PinNo);
			break;
		case GPIO_PORTB:
			TOG_BIT(GPIOB->ODR,A_u8PinNo);
			break;
		case GPIO_PORTC:
			TOG_BIT(GPIOC->ODR,A_u8PinNo);
			break;
	}
}
