#include "Bit_Math.h"
#include "STD_Types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SysTik_interface.h"

void SysTik_ISR(){

	GPIO_voidTogglePinValue(GPIO_PORTA,GPIO_PIN0);
}

int main(){

	RCC_voidInitialize();
	RCC_vEnablePeripheralClock(RCC_APB2,IOPA);

	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_DIRECTION_OUTPUT_10MHz,GP_PUSH_PULL_MODE);
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);

	SysTik_voidInitialize();
	SysTik_voidSetIntervalms_Periodic(1000,SysTik_ISR);

	while(1){
		/*GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);
		SysTik_voidDelay_ms(10000);
		GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
		SysTik_voidDelay_ms(10000);*/
	}
}
