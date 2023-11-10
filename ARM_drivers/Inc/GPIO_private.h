#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define GPIOA_BASE_ADDRESS 0x40010800
#define GPIOB_BASE_ADDRESS 0x40010C00
#define GPIOC_BASE_ADDRESS 0x40011000

typedef struct{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;
}GPIOx_t;

#define GPIOA ((volatile GPIOx_t*)(GPIOA_BASE_ADDRESS))
#define GPIOB ((volatile GPIOx_t*)(GPIOB_BASE_ADDRESS))
#define GPIOC ((volatile GPIOx_t*)(GPIOC_BASE_ADDRESS))

#endif
