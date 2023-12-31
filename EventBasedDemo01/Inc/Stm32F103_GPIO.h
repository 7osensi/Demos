/*
 * Stm32F103_GPIO.h
 *
 *  Created on: May 12, 2023
 *      Author: Hussein Mohamed
 */

#ifndef INC_STM32F103_GPIO_H_
#define INC_STM32F103_GPIO_H_

/*================================== #include ==================================*/
#include"stm32f103.h"
#include"BIT_MATH.h"

/*================================== #define ===================================*/

/*================================== Mode ======================================*/
#define INPUT_MODE						0
#define OUTPUT_10MHZ_MODE				1
#define OUTPUT_2MHZ_MODE		 		2
#define OUTPUT_50MHZ_MODE				3

/*===================== Configuration =====================*/

/* Input Mode */
#define	ANALOG_MODE						0
#define	FLOATING_INPUT					1
#define	INPUT_PU_PL_MODE				2

/* Output Mode */
#define	GP_OUTPUT_PU_PL_MODE			0
#define	GP_OUTPUT_OPEN_DR_MODE	    	1
#define	ALT_FN_OUTPUT_PU_PL_MODE		2
#define	ALT_FN_OUTPUT_OPEN_DR_MODE		3


/*==================== GPIO Pin Numbers ====================*/

#define GPIO_PIN_NO_0       0
#define GPIO_PIN_NO_1       1
#define GPIO_PIN_NO_2       2
#define GPIO_PIN_NO_3       3
#define GPIO_PIN_NO_4       4
#define GPIO_PIN_NO_5       5
#define GPIO_PIN_NO_6       6
#define GPIO_PIN_NO_7       7
#define GPIO_PIN_NO_8       8
#define GPIO_PIN_NO_9       9
#define GPIO_PIN_NO_10      10
#define GPIO_PIN_NO_11      11
#define GPIO_PIN_NO_12      12
#define GPIO_PIN_NO_13      13
#define GPIO_PIN_NO_14      14
#define GPIO_PIN_NO_15      15

/*==================== GPIO Ports Numbers ====================*/
#define _GPIOA_PORT			0
#define _GPIOB_PORT			1
#define _GPIOC_PORT			2

/*========================== struct ==========================*/
typedef struct
{
	u8 GPIO_PinNumber;

	/* INPUT_MODE || OUTPUT_10MHZ_MODE || OUTPUT_2MHZ_MODE || OUTPUT_50MHZ_MODE */
	u8 GPIO_PinMode;

	/* ANALOG_MODE, FLOATING_INPUT, INPUT_PU_PL_MODE
	 * GP_OUTPUT_PU_PL_MODE, GP_OUTPUT_OPEN_DR_MODE, ALT_FN_OUTPUT_PU_PL_MODE, ALT_FN_OUTPUT_OPEN_DR_MODE */
	u8 GPIO_PinConfiguration;

}GPIO_PinConfig_t;

/*========================== struct ==========================*/
typedef struct
{
	GPIOx_t *pGPIOx; 					/* Holds The Base Address of The GPIO Port */
	GPIO_PinConfig_t GPIO_PinConfig; 	/* Holds GPIO Pin Configurations Settings */
}GPIO_Handle_t;

/*****************************************************************
/                                                  			     /
/                	   GPIO Driver APIs                          /
/                                                            	 /
*****************************************************************/

/*==================== CLK Control ====================*/
extern void MCAL_GPIO_PeripheralClkControl(GPIOx_t *pGPIOx, u8 EN_DIS);

/*==================== Init & DeInit ==================*/
extern void MCAL_GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void MCAL_GPIO_DeInit(GPIOx_t *pGPIOx);

/*======================= Read ========================*/
u8 MCAL_GPIO_ReadInputPin(GPIOx_t *pGPIOx, u8 u8PinNumber);
u16 MCAL_GPIO_ReadInputPort(GPIOx_t *pGPIOx);

/*======================= Write =======================*/
void MCAL_GPIO_WriteOutputPin(GPIOx_t *pGPIOx, u8 u8PinNumber, u8 u8Value);
void MCAL_GPIO_WriteOutputPort(GPIOx_t *pGPIOx, u16 u16Value);

void MCAL_GPIO_ToggleOutputPin(GPIOx_t *pGPIOx, u8 u8PinNumber);

/*======== IRQ Configurations and ISR Handling ========*/
void MCAL_GPIO_IRQConfig(u8 u8IRQNumber, u8 u8EN_DIS);

void MCAL_GPIO_IRQHandling (u8 u8PinNumber);

void GPIO_RegisterCallback(void (*CallBackFn)());

#endif /* INC_STM32F103_GPIO_H_ */
