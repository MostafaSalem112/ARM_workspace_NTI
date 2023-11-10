#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define RCC_DISABLE			0
#define RCC_ENABLE			1

/**************************************************************************/
#define HSI_CLOCK_SOURCE		0b00
#define HSE_CLOCK_SOURCE		0b01
#define PLL_CLOCK_SOURCE		0b10
/***************************************************************************/

/*****************************************************************************/
#define MCO_System_clock		0b00
#define MCO_HSI_clock			0b01
#define MCO_HSE_clock			0b00
#define MCO_PLL_DIV_2_clock		0b00
/*****************************************************************************/

/***************************************************************************/
#define USB_PLL_DIV_1_5			0
#define USB_PLL					1
/****************************************************************************/

/******************************************************************************/
#define PLL_CLOCK_MUL_2			0b0000
#define PLL_CLOCK_MUL_3			0b0001
#define PLL_CLOCK_MUL_4			0b0010
#define PLL_CLOCK_MUL_5			0b0011
#define PLL_CLOCK_MUL_6			0b0100
#define PLL_CLOCK_MUL_7			0b0101
#define PLL_CLOCK_MUL_8			0b0110
#define PLL_CLOCK_MUL_9			0b0111
#define PLL_CLOCK_MUL_10		0b1000
#define PLL_CLOCK_MUL_11		0b1001
#define PLL_CLOCK_MUL_12		0b1010
#define PLL_CLOCK_MUL_13		0b1011
#define PLL_CLOCK_MUL_14		0b1100
#define PLL_CLOCK_MUL_15		0b1101
#define PLL_CLOCK_MUL_16		0b1110
/******************************************************************************/

/******************************************************************************/
#define HSE_clock			0
#define HSE_clock_DIV_2		1
/******************************************************************************/

/***************************************************************************/
#define HSI_CLOCK_DIV_2		0
#define HSE_CLOCK			1
/***************************************************************************/

/****************************************************************************/
#define PCLK2_DIV_2		0b00
#define PCLK2_DIV_4		0b01
#define PCLK2_DIV_6		0b10
#define PCLK2_DIV_8		0b11
/****************************************************************************/

/****************************************************************************/
#define HCLK_NOT_DIV		0b000
#define HCLK_DIV_2			0b100
#define HCLK_DIV_4			0b101
#define HCLK_DIV_8			0b110
#define HCLK_DIV_16			0b111
/****************************************************************************/

/****************************************************************************/
#define SYSCLK_NOT_DIV			0b0000
#define SYSCLK_DIV_2			0b1000
#define SYSCLK_DIV_4			0b1001
#define SYSCLK_DIV_8			0b1010
#define SYSCLK_DIV_16			0b1011
#define SYSCLK_DIV_64			0b1100
#define SYSCLK_DIV_128			0b1101
#define SYSCLK_DIV_256			0b1110
#define SYSCLK_DIV_512			0b1111
/****************************************************************************/


/****************** Bits of CR Register *********************************/
#define HSION	0
#define HSIRDY  1
#define HSITRIM 3
#define HSEON	16
#define HSERDY  17
#define HSEBYP	18
#define CSSON	19
#define PLLON	24
#define PLLRDY  25
/***********************************************************************/

/****************** Bits of CFGR Register *********************************/
#define SW			0
#define SWS			2
#define HPRE		4
#define PPRE1		8
#define PPRE2		11
#define ADCPRE		14
#define PLLSRC		16
#define PLLXTPRE	17
#define PLLMUL		18
#define USBPRE		22
#define MCO			24
/***************************************************************************/

/*********************** RCC BASE ADDRESS *******************************/
#define RCC_BASE_ADDRESS 0x40021000
/************************************************************************/

/*********************** RCC Registers **********************************/
typedef struct {
	u32 CR;
	u32 CFGR;
	u32 CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
	u32 APB2ENR;
	u32 APB1ENR;
	u32 BDCR;
	u32 CSR;
}RCC_t;

#define RCC ((volatile RCC_t*)(RCC_BASE_ADDRESS))
/***********************************************************************/

#endif 
