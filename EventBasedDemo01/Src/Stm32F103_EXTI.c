/*
 * Stm32F103_EXTI.c
 *
 *  Created on: May 15, 2023
 *      Author: Hussein Mohamed
 */

/*================================== #include ==================================*/
/*================================== #include ==================================*/
/*================================== #include ==================================*/
#include"Stm32F103_EXTI.h"

/*****************************************************************
 * @fn          - MCAL_EXTI_Enable
 *
 * @brief       - This function Takes The Number Of Line To Set Or Not Mask It As EXTI
 *
 * @param[in]   - Line Number
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
void MCAL_EXTI_Enable(u8 u8LineNumber)
{
	MEXTI->IMR |= (1 << u8LineNumber);
}

/*****************************************************************
 * @fn          - MCAL_EXTI_Disable
 *
 * @brief       - Function Takes The Number Of Line To Disable Or Mask It As EXTI
 *
 * @param[in]   - Line Number
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
void MCAL_EXTI_Disable(u8 u8LineNumber)
{
	MEXTI->IMR &= ~(1 << u8LineNumber);
}

/*****************************************************************
 * @fn          - MCAL_EXTI_InterruptEdgeType
 *
 * @brief       - Function to Set Trigger on Rising Or Falling
 *
 * @param[in]   - Line Number
 *
 * @param[in]   - Edge: EXTI_R_EDGE || EXTI_F_EDGE
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
void MCAL_EXTI_InterruptEdgeType(u8 u8LineNumber, u8 u8Edge)
{
	switch(u8Edge)
	{
	/* Rising Edge Trigger Selection */
	case EXTI_R_EDGE:
		MEXTI->RTSR |= (1 << u8LineNumber);
		/* Clear The FTSR Corresponding Pin */
		MEXTI->FTSR &= ~(1 << u8LineNumber);		break;
	/* Falling Edge Trigger Selection */
	case EXTI_F_EDGE:
		MEXTI->FTSR |= (1 << u8LineNumber);
		/* Clear The RTSR Corresponding Pin */
		MEXTI->RTSR &= ~(1 << u8LineNumber);		break;
	default:										break;
	}
}

/*****************************************************************
 * @fn          - MCAL_EXTI_ClearPending
 *
 * @brief       - This Function Clears Pending Register For The Corresponding Bit
 *
 * @param[in]   - Pin number
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
void MCAL_EXTI_ClearPending(u8 u8PinNumber)
{
	/* Clear Pending Register Bit */
	if(MEXTI->PR & (1 << u8PinNumber) )
	{
		MEXTI->PR |= (1 << u8PinNumber);
	}
}

void MCAL_EXTI_SWTrigger(u8 u8LineNumber)
{
	MEXTI->SWIER |= (1 << u8LineNumber);
}
