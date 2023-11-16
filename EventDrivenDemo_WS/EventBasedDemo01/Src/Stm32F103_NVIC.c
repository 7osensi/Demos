/*
 * Stm32F103_NVIC.c
 *
 *  Created on: May 16, 2023
 *      Author: Hussein Mohamed
 */

/*================================== #include ==================================*/
#include"Stm32F103_NVIC.h"

/*================================= FUNC_START ================================*/

/*****************************************************************
 * @fn          - MCAL_NVIC_EnableInterrupt
 *
 * @brief       - This Function Used to Enable IRQ
 *
 * @param[in]   - IRQ Number
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
void MCAL_NVIC_EnableInterrupt(u8 IRQNumber, u8 IRQStatus)
{
	if(IRQStatus == ENABLE)
	{
		if(IRQNumber <= 31)
		{
			NVIC_ISER0 |= (1 << IRQNumber);

		}
		else if(IRQNumber <= 63)
		{
			NVIC_ISER1 |= (1 << (IRQNumber - 32) );
		}
	}
	else
	{
		if(IRQNumber <= 31)
		{
			NVIC_ICER0 |= (1 << IRQNumber);

		}
		else if(IRQNumber <= 63)
		{
			NVIC_ICER1 |= (1 << (IRQNumber - 32) );
		}
	}
}
/*================================== FUNC_END ==================================*/
