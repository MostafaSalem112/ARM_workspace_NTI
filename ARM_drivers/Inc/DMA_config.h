/*
 * DMA_config.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Mostafa_Salem
 */

#ifndef DMA_CONFIG_H_
#define DMA_CONFIG_H_

/***************************************************************/
/*
 * MEMORY_TO_MEMORY
 * MEMORY_TO_PERIPHERAL
 * PERIPHERAL_TO_MEMORY
 */
#define CHANEEL_1_DATA_DIRECTION		MEMORY_TO_MEMORY
#define CHANEEL_2_DATA_DIRECTION		MEMORY_TO_MEMORY
#define CHANEEL_3_DATA_DIRECTION		MEMORY_TO_MEMORY
#define CHANEEL_4_DATA_DIRECTION		MEMORY_TO_MEMORY
#define CHANEEL_5_DATA_DIRECTION		MEMORY_TO_MEMORY
#define CHANEEL_6_DATA_DIRECTION		MEMORY_TO_MEMORY
#define CHANEEL_7_DATA_DIRECTION		MEMORY_TO_MEMORY
/***************************************************************/

/***************************************************************/
/*
 * priority_level_Low
 * priority_level_Medium
 * priority_level_High
 * priority_level_Very_high
 */
#define Channel_1_priority_level		priority_level_Low
#define Channel_2_priority_level		priority_level_Low
#define Channel_3_priority_level		priority_level_Low
#define Channel_4_priority_level		priority_level_Low
#define Channel_5_priority_level		priority_level_Low
#define Channel_6_priority_level		priority_level_Low
#define Channel_7_priority_level		priority_level_Low
/***************************************************************/


#endif /* DMA_CONFIG_H_ */
