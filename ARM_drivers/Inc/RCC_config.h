#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/******************************************************************/
/*
 * RCC_DISABLE
 * RCC_ENABLE
 */
#define HSI_CLOCK_STATUS		RCC_ENABLE
#define HSE_CLOCK_STATUS		RCC_DISABLE
#define PLL_CLOCK_STATUS		RCC_DISABLE
/******************************************************************/

/*******************************************************************/
/*
 * HSI_CLOCK_SOURCE
 * HSE_CLOCK_SOURCE
 * PLL_CLOCK_SOURCE
 */
#define CLOCK_SOURCE		HSI_CLOCK_SOURCE
/******************************************************************/

/****************************************************************/
/*
 * RCC_DISABLE
 * RCC_ENABLE
 */
#define Clock_security_system_STATUS		RCC_ENABLE
/*******************************************************************/

/**************************************************************************/
/*
 * RCC_DISABLE
 * RCC_ENABLE
 */
#define External_high_speed_clock_bypass	RCC_DISABLE
/***************************************************************************/

/***********************************************************************/
/*
 * MCO_System_clock
 * MCO_HSI_clock
 * MCO_HSE_clock
 * MCO_PLL_DIV_2_clock
 */
#define MCO_SOURCE			MCO_HSI_clock
/************************************************************************/

/*************************************************************************/
/*
 * USB_PLL_DIV_1_5
 * USB_PLL
 */
#define USB_PRESCALER		USB_PLL_DIV_1_5
/*************************************************************************/

/***********************************************************************/
/*
 * PLL_CLOCK_MUL_2
 * PLL_CLOCK_MUL_3
 * PLL_CLOCK_MUL_4
 * PLL_CLOCK_MUL_5
 * PLL_CLOCK_MUL_6
 * PLL_CLOCK_MUL_7
 * PLL_CLOCK_MUL_8
 * PLL_CLOCK_MUL_9
 * PLL_CLOCK_MUL_10
 * PLL_CLOCK_MUL_11
 * PLL_CLOCK_MUL_12
 * PLL_CLOCK_MUL_13
 * PLL_CLOCK_MUL_14
 * PLL_CLOCK_MUL_15
 * PLL_CLOCK_MUL_16
 */
#define PLL_MUL_FACTOR			PLL_CLOCK_MUL_2
/**************************************************************************/

/**************************************************************************/
/*
 * HSE_clock
 * HSE_clock_DIV_2
 */
#define HSE_divider_for_PLL			HSE_clock
/***************************************************************************/

/*******************************************************************************/
/*
 * HSI_CLOCK_DIV_2
 * HSE_CLOCK
 */
#define PLL_SOURCE				HSI_CLOCK_DIV_2
/*******************************************************************************/

/********************************************************************************/
/*
 * PCLK2_DIV_2
 * PCLK2_DIV_4
 * PCLK2_DIV_6
 * PCLK2_DIV_8
 */
#define ADC_PRESCALER			PCLK2_DIV_2
/********************************************************************************/

/********************************************************************************/
/*
 * HCLK_NOT_DIV
 * HCLK_DIV_2
 * HCLK_DIV_4
 * HCLK_DIV_8
 * HCLK_DIV_16
 */
#define APB1_PRESCALER			HCLK_NOT_DIV
#define APB2_PRESCALER			HCLK_NOT_DIV
/**********************************************************************************/

/********************************************************************************/
/*
 * SYSCLK_NOT_DIV
 * SYSCLK_DIV_2
 * SYSCLK_DIV_4
 * SYSCLK_DIV_8
 * SYSCLK_DIV_16
 * SYSCLK_DIV_64
 * SYSCLK_DIV_128
 * SYSCLK_DIV_256
 * SYSCLK_DIV_512
 */
#define AHB_PRESCALER			SYSCLK_NOT_DIV
/********************************************************************************/

#endif 
