/*
 * Stm32F103_GPIO.c
 *
 *  Created on: May 12, 2023
 *      Author: Hussein Mohamed
 */

/*================================== #include ==================================*/
#include"Stm32F103_GPIO.h"

/*================================== definitions ==================================*/
void (*ptrToFunction)(void) = NULL;

/*****************************************************************
 * @fn          - MCAL_GPIO_PeripheralClkControl
 *
 * @brief       - This function enables or disables peripheral
 *                clock for the given GPIO port
 *
 * @param[in]   - Base address of the GPIO peripheral
 * @param[in]   - Macros: ENABLE or DISABLE
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/

/*================================= FUNC_START ================================*/

extern void MCAL_GPIO_PeripheralClkControl(GPIOx_t *pGPIOx, u8 EN_DIS)
{
	if(EN_DIS == ENABLE)
	{
		if(pGPIOx == MGPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if (pGPIOx == MGPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if (pGPIOx == MGPIOC)
		{
			GPIOC_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx == MGPIOA)
		{
			GPIOA_PCLK_DIS();
		}
		else if (pGPIOx == MGPIOB)
		{
			GPIOB_PCLK_DIS();
		}
		else if (pGPIOx == MGPIOC)
		{
			GPIOC_PCLK_DIS();
		}
	}
}
/*================================== FUNC_END ==================================*/

/*****************************************************************
 * @fn          - MCAL_GPIO_Init
 *
 * @brief       - This function initialize GPIO peripherals
 *
 * @param[in]   - Pointer to GPIO Handle structure
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/

/*================================= FUNC_START ================================*/

extern void MCAL_GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{

	u32 TempReg = 0;

	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber <= 7) /* CRL : CR[0] : Pins 0 : 7 */
	{
		/* 1. Configure The Mode of The GPIO Pin */

		TempReg = ( (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode) << ( (4 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) ) ) );

		pGPIOHandle->pGPIOx->CR[0]  &= ~(0x3 << (4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); /* Clearing Pins */

		pGPIOHandle->pGPIOx->CR[0] |= TempReg;

		TempReg = 0;

		/* 2. Configure The Configuration of The GPIO Pin */

		TempReg = ( (pGPIOHandle->GPIO_PinConfig.GPIO_PinConfiguration) << ( (4 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) ) + 2) );

		pGPIOHandle->pGPIOx->CR[0]  &= ~(0x3 << ( (4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) + 2) ); /* Clearing Pins */

		pGPIOHandle->pGPIOx->CR[0] |= TempReg;

		TempReg = 0;
	}
	else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber >= 8) /* CRH : CR[1] : Pins 8 : 15 */
	{
		/* 1. Configure The Mode of The GPIO Pin */

		TempReg = ( (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode) << ( (4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) - 32)  );

		pGPIOHandle->pGPIOx->CR[1]  &= ~(0x3 << ( (4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) - 32) ); /* Clearing Pins */

		pGPIOHandle->pGPIOx->CR[1] |= TempReg;

		TempReg = 0;

		/* 2. Configure The Configuration of The GPIO Pin */

		TempReg = ( (pGPIOHandle->GPIO_PinConfig.GPIO_PinConfiguration) << ((4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) - 32 + 2));

		pGPIOHandle->pGPIOx->CR[1]  &= ~(0x3 << ((4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) - 32 + 2)); /* Clearing Pins */

		pGPIOHandle->pGPIOx->CR[1] |= TempReg;

		TempReg = 0;
	}
}
/*================================== FUNC_END ==================================*/

/*****************************************************************
 * @fn          - MCAL_GPIO_DeInit
 *
 * @brief       - This function de-initialize GPIO peripherals
 *
 * @param[in]   - Base address of the GPIO peripheral
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/

/*================================= FUNC_START ================================*/

void MCAL_GPIO_DeInit(GPIOx_t *pGPIOx)
{
	if(pGPIOx == MGPIOA)
	{
		GPIOA_REG_RESET();

	}
	else if (pGPIOx == MGPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if (pGPIOx == MGPIOC)
	{
		GPIOC_REG_RESET();
	}
}
/*================================== FUNC_END ==================================*/

/*****************************************************************
 * @fn          - MCAL_GPIO_ReadFromInputPin
 *
 * @brief       - This function reads value of input pin, on
 *                a specific port
 *
 * @param[in]   - Base address of the GPIO peripheral
 * @param[in]   - Pin number
 *
 * @return      - Content of the input data
 *
 * @Note        - 0 or 1
 *
 *****************************************************************/

/*================================= FUNC_START ================================*/

u8 MCAL_GPIO_ReadInputPin(GPIOx_t *pGPIOx, u8 u8PinNumber)
{
	u8 Value = 0;

	Value = (u8)((pGPIOx->IDR >> u8PinNumber) & 0x00000001);

	return Value;
}
/*================================== FUNC_END ==================================*/

/*****************************************************************
 * @fn          - MCAL_GPIO_ReadFromInputPort
 *
 * @brief       - This function reads value of input port
 *
 * @param[in]   - Base address of the GPIO peripheral
 *
 * @return      - Content of the input data
 *
 * @Note        - None
 *
 *****************************************************************/

/*================================= FUNC_START ================================*/

u16 MCAL_GPIO_ReadInputPort(GPIOx_t *pGPIOx)
{
	u16 Value = 0;

	Value = (u16)(pGPIOx->IDR);

	return Value;
}
/*================================== FUNC_END ==================================*/

/*****************************************************************
 * @fn          - MCAL_GPIO_WriteToOutputPin
 *
 * @brief       - This function writes value on a specific
 *                output pin
 *
 * @param[in]   - Base address of the GPIO peripheral
 * @param[in]   - Pin number
 * @param[in]   - Value (Set/Reset Macro)
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/

/*================================= FUNC_START ================================*/

void MCAL_GPIO_WriteOutputPin(GPIOx_t *pGPIOx, u8 u8PinNumber, u8 u8Value)
{
	if(u8Value == GPIO_PIN_SET)
	{
		pGPIOx->BSRR = (1 << u8PinNumber);

	}
	else if (u8Value == GPIO_PIN_RESET)
	{
		pGPIOx->BSRR = (1 << (u8PinNumber + 16) );
	}
}
/*================================== FUNC_END ==================================*/

/*****************************************************************
 * @fn          - MCAL_GPIO_WriteToOutputPort
 *
 * @brief       - This Function Writes Value on a Specific Output Port
 *
 * @param[in]   - Base address of the GPIO peripheral
 * @param[in]   - Value (Set/Reset Macro)
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/

/*================================= FUNC_START ================================*/

void MCAL_GPIO_WriteOutputPort(GPIOx_t *pGPIOx, u16 u16Value)
{
	pGPIOx->BSRR = u16Value;
}
/*================================== FUNC_END ==================================*/

/*****************************************************************
 * @fn          - MCAL_GPIO_ToggleOutputPin
 *
 * @brief       - This Function Toggles Specific Output Pin
 *
 * @param[in]   - Base Address of the GPIO Peripheral
 * @param[in]   - Pin Number
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/

/*================================= FUNC_START ================================*/

void MCAL_GPIO_ToggleOutputPin(GPIOx_t *pGPIOx, u8 u8PinNumber)
{
	pGPIOx->ODR ^= (1 << u8PinNumber);
}
/*================================== FUNC_END ==================================*/

/*****************************************************************
 * @fn          - MCAL_GPIO_IRQConfig
 *
 * @brief       - This function configures interrupt
 *
 * @param[in]   - IRQ Interrupt number
 * @param[in]   - Macro: Enable/Disable
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/

/*================================= FUNC_START ================================*/

void MCAL_GPIO_IRQConfig(u8 u8IRQNumber, u8 u8EN_DIS) /* Configuration of NVIC Registers */
{
	/* Enable Interrupt */
	if(u8EN_DIS == EXTI_ENABLE)
	{
		if((u8IRQNumber >= 0) && (u8IRQNumber <= 31))
		{
			NVIC_ISER0 |= (1 << u8IRQNumber);
		}

		else if((u8IRQNumber >= 32) && (u8IRQNumber <= 63))
		{
			NVIC_ISER1 |= (1 << (u8IRQNumber - 32));
		}
	}
	/* Disable Interrupt */
	else
	{
		if( (u8IRQNumber >= 0) && (u8IRQNumber <= 31) )
		{
			NVIC_ICER0 |= (1 << u8IRQNumber);
		}

		else if( (u8IRQNumber >= 32) && (u8IRQNumber <= 63) )
		{
			NVIC_ICER1 |= (1 << u8IRQNumber);
		}
	}
}

/*================================== FUNC_END ==================================*/

/*================================= FUNC_START ================================*/
void MCAL_GPIO_IRQHandling (u8 u8PinNumber)
{
	/* Check Bit */
//	if( MEXTI->PR & (0x1 << u8PinNumber))
//	{
//		MEXTI->PR |= (1 << u8PinNumber); /* Reset By Setting The Pin */
//	}
	MEXTI->PR |= (1 << u8PinNumber); /* Reset By Setting The Pin */
}
/*================================== FUNC_END ==================================*/

void GPIO_RegisterCallback(void (*CallBackFn)()) {
	ptrToFunction = CallBackFn;
}
/*================================= FUNC_START ================================*/
//void EXTI15_10_IRQHandler(void) {
//	ptrToFunction();
//}
/*================================== FUNC_END ==================================*/
