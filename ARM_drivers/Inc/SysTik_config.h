/*
 * SysTik_config.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Mostafa_Salem
 */

#ifndef SYSTIK_CONFIG_H_
#define SYSTIK_CONFIG_H_

/**************************************************************************/
#define SysTik_AHB_CLOCK			8000000
/**************************************************************************/

/***************************************************************************/
/*
 * AHB_CLOCK_DIV_8
 * AHB_CLOCK
 */
#define SysTik_CLOCK_SOURCE		AHB_CLOCK_DIV_8
/***************************************************************************/

/***************************************************************************/
/*
 * SysTik_DISABLE
 * SysTik_ENABLE
 */
#define SysTik_INTERRUPT_STATUS		SysTik_ENABLE
/***************************************************************************/

#endif /* SYSTIK_CONFIG_H_ */
