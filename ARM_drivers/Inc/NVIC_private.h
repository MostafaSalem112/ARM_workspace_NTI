/*
 * NVIC_private.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Mostafa_Salem
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NIBBLE_SIZE		4
#define FIVE_BITS_SIZE	5
#define SIX_BITS_SIZE	6
#define SEVEN_BITS_SIZE	7
#define BYTE_SIZE		8
#define REGISTER_SIZE	32

#define NVIC_BASE_ADDRESS		0xE000E100


typedef struct{
	u32 ISER[3];
	u32 RES1[29];
	u32 ICER[3];
	u32 RES2[29];
	u32 ISPR[3];
	u32 RES3[29];
	u32 ICPR[3];
	u32 RES4[29];
	u32 IABR[3];
	u32 RES5[61];
	u8 IPR[84];
}NVIC_t;

#define NVIC  ((volatile NVIC_t*)(NVIC_BASE_ADDRESS))

#define AIRCR 	(*(volatile u32*)(0xE000ED00 + 0x0C))

#define VECTKEY		0x05FA0000

#define PRIGROUP		8


#endif /* NVIC_PRIVATE_H_ */
