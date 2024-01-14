/*
 * Stm32F103_GPIO.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Hussein Mohamed
 */

/*================================== #include ==================================*/
#include"Stm32F103_ADC.h"

void (*ADCptrFunction)(void) = NULL;

/*================================= FUNC_START ================================*/
extern void ADC_Init(ADC_HandleTypeDef *pADCxHandle)
{
	if(pADCxHandle->pADCx == MADC1)
	{
		ADC1_PCLK_EN(); 							/* ADC1 Clock Enable */

	}
	else if (pADCxHandle->pADCx == MADC2)
	{
		ADC2_PCLK_EN(); 							/* ADC1 Clock Enable */
	}

	pADCxHandle->pADCx->CR2 &= ~(1 << 0); 			/* Disable Bit 0 ADON: A/D converter ON / OFF */

	if (pADCxHandle->ChannelNumber <= 17)
	{
		pADCxHandle->pADCx->SQR3 |= (pADCxHandle->ChannelNumber << 0); 		/* Enable ADC Channel */
	}
	else
	{
		/* Error */
	}

	pADCxHandle->pADCx->CR2 |= (7 << 17); 			/* External event select for regular group */

	pADCxHandle->pADCx->CR2 |= (1 << 20); 			/* External trigger conversion mode for regular channels */

	pADCxHandle->pADCx->CR2 |= (1 << 1);			/* Enable continuous conversion mode  */

	pADCxHandle->pADCx->CR2 |= (1 << 0); 			/* Enable Bit 0 ADON: A/D converter ON / OFF */
}
/*================================= FUNC_END   ================================*/

/*================================= FUNC_START ================================*/
extern void ADC_Conversion(void)
{
	MADC1->CR2 |= (1 << 22); 						/* Start conversion of regular channels */
}
/*================================= FUNC_END   ================================*/

/*================================= FUNC_START ================================*/
extern u16 ADC_Read(ADC_HandleTypeDef *pADCxHandle)
{
	while(!(pADCxHandle->pADCx->SR & (1 << 1))){} 	/* Check if conversion is done */
	return pADCxHandle->pADCx->DR;
}
/*================================= FUNC_END   ================================*/

/*================================= FUNC_START ================================*/
void ADC_Registering(void(*pCallBack)(void))
{
	ADCptrFunction = pCallBack;
}
/*================================= FUNC_END   ================================*/

//void ADC1_2_IRQHandler()
//{
//	ptrFunction();
//}
