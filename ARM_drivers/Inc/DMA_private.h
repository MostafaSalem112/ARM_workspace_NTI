/*
 * DMA_private.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Mostafa_Salem
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

/*********************************************************************/
#define DMA_DISABLE		0
#define DMA_ENABLE		1
/*********************************************************************/

/*********************************************************************/
#define Read_from_peripheral		0
#define Read_from_memory			1
/*********************************************************************/

/*********************************************************************/
#define DMA_DATA_SIZE_8_BITS		0b00
#define DMA_DATA_SIZE_16_BITS		0b01
#define DMA_DATA_SIZE_32_BITS		0b10
/*********************************************************************/

/*********************************************************************/
#define priority_level_Low			0b00
#define priority_level_Medium		0b01
#define priority_level_High			0b10
#define priority_level_Very_high	0b11
/*********************************************************************/

/*********************************************************************/
#define MEMORY_TO_MEMORY		0b00
#define MEMORY_TO_PERIPHERAL	0b01
#define PERIPHERAL_TO_MEMORY	0b10
/*********************************************************************/

/*********************************************************************/
#define GIF		0
#define TCIF	1
#define HTIF	2
#define TEIF	3
/*********************************************************************/

/*********************************************************************/
#define EN			0
#define TCIE		1
#define HTIE		2
#define TEIE		3
#define DIR			4
#define CIRC		5
#define PINC		6
#define MINC		7
#define PSIZE		8
#define MSIZE		10
#define PL			12
#define MEM2MEM		14
/*********************************************************************/

/*********************************************************************/
#define DMA_BASE_ADDRESS		0x40020000

typedef struct{
	u32 CCR;
	u32 CNDTR;
	u32 CPAR;
	u32 CMAR;
	u32 RES;
}CHANEEL_REG_t;

typedef struct{
	u32 ISR;
	u32 IFCR;
	CHANEEL_REG_t CHANEEL_REG[7];
}DMA_t;

#define DMA		((volatile DMA_t*)(DMA_BASE_ADDRESS))
/*********************************************************************/

#endif /* DMA_PRIVATE_H_ */
