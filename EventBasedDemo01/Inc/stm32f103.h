/*
 * stm32f103.h
 *
 *  Created on: May 12, 2023
 *      Author: Hussein Mohamed
 */

#ifndef INC_STM32F103_H_
#define INC_STM32F103_H_

/*================================= #include =================================*/
/*================================= #include =================================*/
/*================================= #include =================================*/
#include <Std_Types.h>

/*============================= #define =============================*/
/*============================= #define =============================*/
/*============================= #define =============================*/

#define FLASH_BASE				0x08000000U	/* Main Memory */
#define SRAM_BASE				0x20000000U


/*========================= NVIC Base Address =========================*/
#define NVIC_BASE				0xE000E100

/*========================= Peripherals Addresses =========================*/
#define PERIPHERALS_BASE		0x40000000U

/* APBx and AHB Busses Addresses */
#define APB1_BASE				PERIPHERALS_BASE
#define APB2_BASE				0x40010000U
#define AHB_BASE				0x40018000U

/*========================= Base Addresses of APB1 =========================*/
#define TIM2_BASE				(APB1_BASE + 0x0000)
#define TIM3_BASE				(APB1_BASE + 0x0400)
#define TIM4_BASE				(APB1_BASE + 0x0800)

#define RTC_BASE				(APB1_BASE + 0x2800)
#define WWDG_BASE				(APB1_BASE + 0x2C00)
#define SPI2_BASE				(APB1_BASE + 0x3800)

#define USART2_BASE				(APB1_BASE + 0x4400)
#define USART3_BASE				(APB1_BASE + 0x4800)

#define I2C1_BASE				(APB1_BASE + 0x5400)
#define I2C2_BASE				(APB1_BASE + 0x5800)

/*========================= Base Addresses of APB2 =========================*/
#define AFIO_BASE				(APB2_BASE + 0x0000)

#define EXTI_BASE				(APB2_BASE + 0x0400)

#define GPIOA_BASE				(APB2_BASE + 0x0800) /* 0x40010800 */
#define GPIOB_BASE				(APB2_BASE + 0x0C00) /* 0x40010C00 */
#define GPIOC_BASE				(APB2_BASE + 0x1000) /* 0x40011000 */

#define ADC1_BASE				(APB2_BASE + 0x2400)
#define ADC2_BASE				(APB2_BASE + 0x2800)
#define TIM1_BASE				(APB2_BASE + 0x2C00)
#define SPI1_BASE				(APB2_BASE + 0x3000)
#define USART1_BASE				(APB2_BASE + 0x3800)

/*========================= Base Addresses of AHB =========================*/
#define SDIO_BASE				(AHB_BASE  + 0x0000)

#define DMA1_BASE				(AHB_BASE  + 0x8000)
#define DMA2_BASE				(AHB_BASE  + 0x8400)

#define RCC_BASE				(AHB_BASE  + 0x9000) /* 0x40021000 */
#define CRC_BASE				(AHB_BASE  + 0xB000)


/*================================== Generic Macros ==================================*/

#define ENABLE					1
#define DISABLE					0

#define NULL					0

#define HIGH					1
#define LOW						0

#define SET						ENABLE
#define RESET					DISABLE

#define GPIO_PIN_SET			SET
#define GPIO_PIN_RESET			RESET

#define EXTI_ENABLE				ENABLE
#define EXTI_DISABLE			DISABLE

#define EXTI_R_EDGE				HIGH
#define EXTI_F_EDGE				LOW

#define GPIOA_PORT				0
#define GPIOB_PORT				1
#define GPIOC_PORT				2

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()   do{ (MRCC->APB2RSTR |= (1 << 0)); (MRCC->APB2RSTR &= ~(1 << 2) ); }while(0)
#define GPIOB_REG_RESET()   do{ (MRCC->APB2RSTR |= (1 << 1)); (MRCC->APB2RSTR &= ~(1 << 3) ); }while(0)
#define GPIOC_REG_RESET()   do{ (MRCC->APB2RSTR |= (1 << 2)); (MRCC->APB2RSTR &= ~(1 << 4) ); }while(0)

/*
 * IRQ(Interrupt Request) Numbers of STM32F446x MCU
 * This is Specific for Stm32F103 Medium Density Boards
 */
#define IRQ_NO_WWDG                 0   /* Window Watchdog interrupt                                            */
#define IRQ_NO_PVD                  1   /* PVD through EXTI line detection interrupt                            */
#define IRQ_NO_TAMPER               2   /* Tamper and Time stamp interrupts through EXTI line                   */
#define IRQ_NO_RTC                  3   /* RTC Wakeup interrupt through EXTI line                               */
#define IRQ_NO_FLASH                4   /* Flash global interrupt                                               */
#define IRQ_NO_RCC                  5   /* RCC global interrupt                                                 */
#define IRQ_NO_EXTI0                6   /* EXTI Line0 interrupt                                                 */
#define IRQ_NO_EXTI1                7   /* EXTI Line1 interrupt                                                 */
#define IRQ_NO_EXTI2                8   /* EXTI Line2 interrupt                                                 */
#define IRQ_NO_EXTI3                9   /* EXTI Line3 interrupt                                                 */
#define IRQ_NO_EXTI4                10  /* EXTI Line4 interrupt                                                 */

/*================================== RCC ==================================*/
/*================================== RCC ==================================*/
/*================================== RCC ==================================*/

/*===============================================================
					RCC Macros :>:>: Register Map
=================================================================*/
#define RCC_CR                      (*( ( volatile u32* )(RCC_BASE + 0x00) ) )
#define RCC_CFGR                    (*( ( volatile u32* )(RCC_BASE + 0x04) ) )
#define RCC_CIR                     (*( ( volatile u32* )(RCC_BASE + 0x08) ) )
#define RCC_APB2RSTR                (*( ( volatile u32* )(RCC_BASE + 0x0C) ) )
#define RCC_APB1RSTR                (*( ( volatile u32* )(RCC_BASE + 0x10) ) )
#define RCC_AHBENR                  (*( ( volatile u32* )(RCC_BASE + 0x14) ) )
#define RCC_APB2ENR                 (*( ( volatile u32* )(RCC_BASE + 0x18) ) )
#define RCC_APB1ENR                 (*( ( volatile u32* )(RCC_BASE + 0x1C) ) )
#define RCC_BDCR                    (*( ( volatile u32* )(RCC_BASE + 0x20) ) )
#define RCC_CSR                  	(*( ( volatile u32* )(RCC_BASE + 0x24) ) )
#define RCC_AHBSTR                 	(*( ( volatile u32* )(RCC_BASE + 0x28) ) )
#define RCC_CFGR2                  	(*( ( volatile u32* )(RCC_BASE + 0x2C) ) )

/**********************************************************************/
#define CSSON   19U
/**********************************************************************/

typedef struct
{
  volatile u32 CR;
  volatile u32 CFGR;
  volatile u32 CIR;
  volatile u32 APB2RSTR;
  volatile u32 APB1RSTR;
  volatile u32 AHBENR;
  volatile u32 APB2ENR;
  volatile u32 APB1ENR;
  volatile u32 BDCR;
  volatile u32 CSR;
  volatile u32 AHBSTR;
  volatile u32 CFGR2;
} RCC_t;

/*===============================================================
			Macro: Pointer of Type RCC_t Pointing to RCC_BASE
=================================================================*/
#define MRCC      ((RCC_t *)RCC_BASE)

/*================================== GPIO ==================================*/
/*================================== GPIO ==================================*/
/*================================== GPIO ==================================*/

/*===============================================================================
					GPIO Macros :>:>: Register Map : GPIOA
=================================================================================*/

#define GPIOA_CRL              (*( (volatile u32 *)(GPIOA_BASE + 0x00) ) )	 /*  Address offset: 0x00      */
#define GPIOA_CRH              (*( (volatile u32 *)(GPIOA_BASE + 0x04) ) )   /*  Address offset: 0x04      */
#define GPIOA_IDR              (*( (volatile u32 *)(GPIOA_BASE + 0x08) ) )   /*  Address offset: 0x08      */
#define GPIOA_ODR              (*( (volatile u32 *)(GPIOA_BASE + 0x0C) ) )   /*  Address offset: 0x0C      */
#define GPIOA_BSRR             (*( (volatile u32 *)(GPIOA_BASE + 0x10) ) )   /*  Address offset: 0x10      */
#define GPIOA_BRR              (*( (volatile u32 *)(GPIOA_BASE + 0x14) ) )   /*  Address offset: 0x14      */
#define GPIOA_LCKR             (*( (volatile u32 *)(GPIOA_BASE + 0x18) ) )   /*  Address offset: 0x18      */

/*===============================================================================
					GPIO Macros :>:>: Register Map : GPIOB
=================================================================================*/

#define GPIOB_CRL              (*( (volatile u32 *)(GPIOB_BASE + 0x00) ) )	 /*  Address offset: 0x00      */
#define GPIOB_CRH              (*( (volatile u32 *)(GPIOB_BASE + 0x04) ) )   /*  Address offset: 0x04      */
#define GPIOB_IDR              (*( (volatile u32 *)(GPIOB_BASE + 0x08) ) )   /*  Address offset: 0x08      */
#define GPIOB_ODR              (*( (volatile u32 *)(GPIOB_BASE + 0x0C) ) )   /*  Address offset: 0x0C      */
#define GPIOB_BSRR             (*( (volatile u32 *)(GPIOB_BASE + 0x10) ) )   /*  Address offset: 0x10      */
#define GPIOB_BRR              (*( (volatile u32 *)(GPIOB_BASE + 0x14) ) )   /*  Address offset: 0x14      */
#define GPIOB_LCKR             (*( (volatile u32 *)(GPIOB_BASE + 0x18) ) )   /*  Address offset: 0x18      */

/*===============================================================================
					GPIO Macros :>:>: Register Map : GPIOC
=================================================================================*/

#define GPIOC_CRL              (*( (volatile u32 *)(GPIOC_BASE + 0x00) ) )	 /*  Address offset: 0x00      */
#define GPIOC_CRH              (*( (volatile u32 *)(GPIOC_BASE + 0x04) ) )   /*  Address offset: 0x04      */
#define GPIOC_IDR              (*( (volatile u32 *)(GPIOC_BASE + 0x08) ) )   /*  Address offset: 0x08      */
#define GPIOC_ODR              (*( (volatile u32 *)(GPIOC_BASE + 0x0C) ) )   /*  Address offset: 0x0C      */
#define GPIOC_BSRR             (*( (volatile u32 *)(GPIOC_BASE + 0x10) ) )   /*  Address offset: 0x10      */
#define GPIOC_BRR              (*( (volatile u32 *)(GPIOC_BASE + 0x14) ) )   /*  Address offset: 0x14      */
#define GPIOC_LCKR             (*( (volatile u32 *)(GPIOC_BASE + 0x18) ) )   /*  Address offset: 0x18      */

/*===============================================================*/

/*===============================================================
			GPIO Struct :>:>: Register Map : GPIOx
=================================================================*/
typedef struct
{
	 volatile u32 CR[2]		;  		/*   CRL : Address offset: 0x00 & CRH : Address offset: 0x04     */
	 volatile u32 IDR  		;  		/*   Address offset: 0x08      				*/
	 volatile u32 ODR  		;  		/*   Address offset: 0x0C      				*/
	 volatile u32 BSRR 		;  		/*   Address offset: 0x10      				*/
	 volatile u32 BRR  		;  		/*   Address offset: 0x14      				*/
	 volatile u32 Reserved  ;  		/*   Address offset: 0x18      				*/
	 volatile u32 LCKR 		;  		/*   Address offset: 0x1C      				*/
}GPIOx_t;

/*================================================================
		Macro: Pointer of Type GPIOx_t Pointing to GPIOA_BASE
=================================================================*/
#define MGPIOA        ( (GPIOx_t *)GPIOA_BASE)

/* MGPIOA->IDR = 11; == *(0x40010800 + 0x08) = 11; */

/*================================================================
		Macro: Pointer of Type GPIOx_t Pointing to GPIOA_BASE
=================================================================*/
#define MGPIOB        ( (GPIOx_t *)GPIOB_BASE)

/*================================================================
		Macro: Pointer of Type GPIOx_t Pointing to GPIOA_BASE
=================================================================*/
#define MGPIOC        ( (GPIOx_t *)GPIOC_BASE)

/*===============================================================================*/

/*===============================================================================
					NVIC Macros :>:>: Register Map : NVIC
=================================================================================*/

#define NVIC_ISER0                  (*( (volatile u32 *)(NVIC_BASE + 0x000) ) )	 /*  Interrupt set-enable register 0 Address offset: 0x000 */
#define NVIC_ISER1                  (*( (volatile u32 *)(NVIC_BASE + 0x004) ) )	 /*  Interrupt set-enable register 1 Address offset: 0x004 */
#define NVIC_ISER2                  (*( (volatile u32 *)(NVIC_BASE + 0x008) ) )	 /*  Interrupt set-enable register 2 Address offset: 0x008 */
#define NVIC_ICER0                  (*( (volatile u32 *)(NVIC_BASE + 0x080) ) )	 /*  Address offset: 0x080      */
#define NVIC_ICER1                  (*( (volatile u32 *)(NVIC_BASE + 0x084) ) )	 /*  Address offset: 0x084      */
#define NVIC_ICER2                  (*( (volatile u32 *)(NVIC_BASE + 0x088) ) )	 /*  Address offset: 0x088      */
#define NVIC_ISPR0                  (*( (volatile u32 *)(NVIC_BASE + 0x100) ) )	 /*  Address offset: 0x100      */
#define NVIC_ISPR1                  (*( (volatile u32 *)(NVIC_BASE + 0x104) ) )	 /*  Address offset: 0x104      */
#define NVIC_ISPR2                  (*( (volatile u32 *)(NVIC_BASE + 0x108) ) )	 /*  Address offset: 0x108      */
#define NVIC_ICPR0                  (*( (volatile u32 *)(NVIC_BASE + 0x180) ) )	 /*  Address offset: 0x180      */
#define NVIC_ICPR1                  (*( (volatile u32 *)(NVIC_BASE + 0x184) ) )	 /*  Address offset: 0x184      */
#define NVIC_ICPR2                  (*( (volatile u32 *)(NVIC_BASE + 0x188) ) )	 /*  Address offset: 0x188      */
#define NVIC_IABR0                  (*( (volatile u32 *)(NVIC_BASE + 0x200) ) )	 /*  Address offset: 0x200      */
#define NVIC_IABR1                  (*( (volatile u32 *)(NVIC_BASE + 0x204) ) )	 /*  Address offset: 0x204      */
#define NVIC_IABR2                  (*( (volatile u32 *)(NVIC_BASE + 0x208) ) )	 /*  Address offset: 0x208      */


/*================================================================
			NVIC Struct :>:>: Register Map : NVIC
=================================================================*/

typedef struct
{
    volatile u32 IMR;      	/* EXTI Interrupt mask register,            Address offset: 0x00 */
    volatile u32 EMR;      	/* EXTI Event mask register,                Address offset: 0x04 */
    volatile u32 RTSR;     	/* EXTI Rising trigger selection register,  Address offset: 0x08 */
    volatile u32 FTSR;     	/* EXTI Falling trigger selection register, Address offset: 0x0C */
    volatile u32 SWIER;    	/* EXTI Software interrupt event register,  Address offset: 0x10 */
    volatile u32 PR;       	/* EXTI Pending register,                   Address offset: 0x14 */
}NVIC_t;

/*================================================================
		Macro: Pointer of Type EXTI_t Pointing to EXTI_BASE
=================================================================*/
#define MNVIC        ( (NVIC_t *)NVIC_BASE)
/*===============================================================*/

/*================================================================
			EXTI Struct :>:>: Register Map : EXTI
=================================================================*/

typedef struct
{
    volatile u32 IMR;      	/* EXTI Interrupt mask register,            Address offset: 0x00 */
    volatile u32 EMR;      	/* EXTI Event mask register,                Address offset: 0x04 */
    volatile u32 RTSR;     	/* EXTI Rising trigger selection register,  Address offset: 0x08 */
    volatile u32 FTSR;     	/* EXTI Falling trigger selection register, Address offset: 0x0C */
    volatile u32 SWIER;    	/* EXTI Software interrupt event register,  Address offset: 0x10 */
    volatile u32 PR;       	/* EXTI Pending register,                   Address offset: 0x14 */
}EXTI_t;

/*================================================================
		Macro: Pointer of Type EXTI_t Pointing to EXTI_BASE
=================================================================*/
#define MEXTI        ( (EXTI_t *)EXTI_BASE)
/*===============================================================*/

/*================================================================
			AFIO Struct :>:>: Register Map : AFIO
=================================================================*/

typedef struct
{
    volatile u32 EVCR;     			/*   Address offset: 0x00 */
    volatile u32 MAPR;      		/*   Address offset: 0x04 */
    volatile u32 EXTICR1;     		/*   Address offset: 0x08 */
    volatile u32 EXTICR2;     		/*   Address offset: 0x0C */
    volatile u32 EXTICR3;    		/*   Address offset: 0x10 */
    volatile u32 EXTICR4;       	/*   Address offset: 0x14 */
    volatile u32 Reserved;			/*   Address offset: 0x18 */
    volatile u32 MAPR2;				/*   Address offset: 0x1C */
}AFIO_t;

/*================================================================
		Macro: Pointer of Type AFIO_t Pointing to AFIO_BASE
=================================================================*/
#define MAFIO        ( (AFIO_t *)AFIO_BASE)
/*===============================================================*/

/*================================================================
			ADC Struct :>:>: Register Map : ADC
=================================================================*/

typedef struct
{
    u32 SR;     			/*   Address offset: 0x00 */
    u32 CR1;      			/*   Address offset: 0x04 */
    u32 CR2;     			/*   Address offset: 0x08 */
    u32 SMPR1;     		/*   Address offset: 0x0C */
    u32 SMPR2;    			/*   Address offset: 0x10 */
    u32 JOFR1;       		/*   Address offset: 0x14 */
    u32 JOFR2;				/*   Address offset: 0x18 */
    u32 JOFR3;				/*   Address offset: 0x1C */
    u32 JOFR4;				/*   Address offset: 0x20 */
    u32 HTR;				/*   Address offset: 0x24 */
    u32 LTR;				/*   Address offset: 0x28 */
    u32 SQR1;				/*   Address offset: 0x2C */
    u32 SQR2;				/*   Address offset: 0x30 */
    u32 SQR3;				/*   Address offset: 0x34 */
    u32 JSQR;				/*   Address offset: 0x38 */
    u32 JDR1;				/*   Address offset: 0x3C */
    u32 JDR2;				/*   Address offset: 0x40 */
    u32 JDR3;				/*   Address offset: 0x44 */
    u32 JDR4;				/*   Address offset: 0x48 */
    u32 DR;				/*   Address offset: 0x4C */
}volatile ADC_t;

/*================================================================
		Macro: Pointer of Type ADC_t Pointing to ADC1_BASE
=================================================================*/
#define MADC1        ((ADC_t *)ADC1_BASE)

/*================================================================
		Macro: Pointer of Type ADC_t Pointing to ADC2_BASE
=================================================================*/
#define MADC2        ((ADC_t *)ADC2_BASE)

/*================================================================
			USART Struct :>:>: Register Map : USART
=================================================================*/
typedef struct{
	u32 USART_SR;
	u32 USART_DR;
	u32 USART_BRR;
	u32 USART_CR1;
	u32 USART_CR2;
	u32 USART_CR3;
	u32 USART_GTPR;
}volatile USART_t;

/*================================================================
		Macro: Pointer of Type USART_t Pointing to USART1_BASE
=================================================================*/
#define MUSART1	((USART_t *)USART1_BASE)

/*================================================================
		Macro: Pointer of Type USART_t Pointing to USART2_BASE
=================================================================*/
#define MUSART2	((USART_t *)USART2_BASE)

/*================================================================
		Macro: Pointer of Type USART_t Pointing to USART3_BASE
=================================================================*/
#define MUSART3	((USART_t *)USART3_BASE)

/*======================================== CLK Enable ========================================*/
/*======================================== CLK Enable ========================================*/
/*======================================== CLK Enable ========================================*/

/*================================================================
				Clock Enable Macros for GPIOx
=================================================================*/
#define GPIOA_PCLK_EN()		MRCC->APB2ENR |= (1 << 2); 	/* GPIOA Clock Enable */
#define GPIOB_PCLK_EN()		MRCC->APB2ENR |= (1 << 3); 	/* GPIOB Clock Enable */
#define GPIOC_PCLK_EN()		MRCC->APB2ENR |= (1 << 4); 	/* GPIOC Clock Enable */

/*================================================================
				Clock Enable Macros for I2Cx
=================================================================*/
#define I2C1_PCLK_EN()		MRCC->APB1ENR |= (1 << 21); /* I2C1 Clock Enable */
#define I2C2_PCLK_EN()		MRCC->APB1ENR |= (1 << 22); /* I2C2 Clock Enable */

/*================================================================
				Clock Enable Macros for SPIx
=================================================================*/
#define SPI1_PCLK_EN()		MRCC->APB2ENR |= (1 << 12); /* SPI1 Clock Enable */
#define SPI2_PCLK_EN()		MRCC->APB1ENR |= (1 << 14); /* SPI2 Clock Enable */

/*================================================================
				Clock Enable Macros for USARTx
=================================================================*/
#define USART1_PCLK_EN()	MRCC->APB2ENR |= (1 << 14); /* USART1 Clock Enable */
#define USART2_PCLK_EN()	MRCC->APB1ENR |= (1 << 17); /* USART2 Clock Enable */
#define USART3_PCLK_EN()	MRCC->APB1ENR |= (1 << 18); /* USART3 Clock Enable */

/*================================================================
				Clock Enable Macro for AFIO
=================================================================*/
#define AFIO_PCLK_EN()		MRCC->APB2ENR |= (1 << 0); 	/* AFIO Clock Enable */

/*================================================================
				Clock Enable Macro for ADCx
=================================================================*/
#define ADC1_PCLK_EN()		MRCC->APB2ENR |= (1 << 9); 	/* ADC1 Clock Enable */
#define ADC2_PCLK_EN()		MRCC->APB2ENR |= (1 << 10); /* ADC2 Clock Enable */


/*======================================== CLK Disable ========================================*/
/*======================================== CLK Disable ========================================*/
/*======================================== CLK Disable ========================================*/

/*================================================================
				Clock Disable Macros for GPIOx
=================================================================*/
#define GPIOA_PCLK_DIS()	MRCC->APB2RSTR |= (1 << 2); /* GPIOA Clock Disable */
#define GPIOB_PCLK_DIS()	MRCC->APB2RSTR |= (1 << 3); /* GPIOB Clock Disable */
#define GPIOC_PCLK_DIS()	MRCC->APB2RSTR |= (1 << 4); /* GPIOC Clock Disable */

/*================================================================
				Clock Disable Macros for I2Cx
=================================================================*/
#define I2C1_PCLK_DIS()		MRCC->APB1RSTR |= (1 << 21); /* I2C1 Clock Disable */
#define I2C2_PCLK_DIS()		MRCC->APB1RSTR |= (1 << 22); /* I2C2 Clock Disable */

/*================================================================
				Clock Disable Macros for SPIx
=================================================================*/
#define SPI1_PCLK_DIS()		MRCC->APB2RSTR |= (1 << 12); /* SPI1 Clock Disable */
#define SPI2_PCLK_DIS()		MRCC->APB1RSTR |= (1 << 14); /* SPI2 Clock Disable */

/*================================================================
				Clock Disable Macros for USARTx
=================================================================*/
#define USART1_PCLK_DIS()	MRCC->APB2RSTR |= (1 << 14); /* USART1 Clock Disable */
#define USART2_PCLK_DIS()	MRCC->APB1RSTR |= (1 << 17); /* USART2 Clock Disable */
#define USART3_PCLK_DIS()	MRCC->APB1RSTR |= (1 << 18); /* USART3 Clock Disable */

/*================================================================
				Clock Enable Macro for AFIO
=================================================================*/
#define AFIO_PCLK_DIS()		MRCC->APB2STR |= (1 << 0); 	/* AFIO Clock Enable */

/*================================================================
				Clock Disable Macro for ADCx
=================================================================*/
#define ADC1_PCLK_DIS()		MRCC->APB2STR |= (1 << 9); 	/* ADC1 Clock Disable */
#define ADC2_PCLK_DIS()		MRCC->APB2STR |= (1 << 10); /* ADC2 Clock Disable */


#endif /* INC_STM32F103_H_ */
