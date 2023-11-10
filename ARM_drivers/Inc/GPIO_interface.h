#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define CRUMB_SIZE	2
#define NIBBLE_SIZE	4
#define BYTE_SIZE	8
#define WORD_SIZE	16

#define TWO_BITS_HIGH	0b11
#define FOUR_BITS_HIGH	0b1111

// GPIO Ports
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

// GPIO Pins
#define GPIO_PIN0	0
#define GPIO_PIN1	1
#define GPIO_PIN2	2
#define GPIO_PIN3	3
#define GPIO_PIN4	4
#define GPIO_PIN5	5
#define GPIO_PIN6	6
#define GPIO_PIN7	7
#define GPIO_PIN8	8
#define GPIO_PIN9	9
#define GPIO_PIN10	10
#define GPIO_PIN11	11
#define GPIO_PIN12	12
#define GPIO_PIN13	13
#define GPIO_PIN14	14
#define GPIO_PIN15	15

// Pins Output Level
#define GPIO_LOW	0
#define GPIO_HIGH	1

// Pins Direction
#define GPIO_DIRECTION_INPUT				0b00
#define GPIO_DIRECTION_OUTPUT_10MHz			0b01
#define GPIO_DIRECTION_OUTPUT_2MHz			0b10
#define GPIO_DIRECTION_OUTPUT_50MHz			0b11

// input modes
#define ANALOG_MODE			0b00
#define FLOATING_MODE		0b01
#define PULL_UP_DOWN_MODE	0b10

// output modes
#define GP_PUSH_PULL_MODE		0b00
#define GP_OPEN_DRAIIN_MODE		0b01
#define AF_PUSH_PULL_MODE		0b10
#define AF_OPEN_DRAIIN_MODE		0b11

void GPIO_voidSetPinMode(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8Direction,u8 A_u8Mode);
u8 GPIO_u8GetPinValue(u8 A_u8PortID,u8 A_u8PinNo);
void GPIO_voidSetPinValue(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8PinValue);
void GPIO_voidTogglePinValue(u8 A_u8PortID,u8 A_u8PinNo);

#endif
