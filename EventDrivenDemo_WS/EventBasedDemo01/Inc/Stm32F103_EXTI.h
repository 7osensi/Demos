/*
 * Stm32F103_EXTI.h
 *
 *  Created on: May 15, 2023
 *      Author: Hussein Mohamed
 */

#ifndef INC_STM32F103_EXTI_H_
#define INC_STM32F103_EXTI_H_

/*================================== #include ==================================*/
/*================================== #include ==================================*/
/*================================== #include ==================================*/
#include"stm32f103.h"

/*================================== #define  ==================================*/
/*================================== #define  ==================================*/
/*================================== #define  ==================================*/

/*==================================   APIs   ==================================*/
/*==================================   APIs   ==================================*/
/*==================================   APIs   ==================================*/

/*	Function Take The Number Of Line To Set Or Not Mask It As EXTI */
void MCAL_EXTI_Enable(u8 u8LineNum);

/*	Function Take The Number Of Line To Disable Or Mask It As EXTI */
void MCAL_EXTI_Disable(u8 u8LineNum);

/* Function to Set Trigger on Rising Or Falling */
void MCAL_EXTI_InterruptEdgeType(u8 u8LineNum, u8 u8Event);

/* Function to Clear The Pending Register for The Corresponding Bit */
void MCAL_EXTI_ClearPending(u8 u8PinNumber);

/* Function To Make Fake Trigger  */
void MCAL_EXTI_SWTrigger(u8 u8LineNumber);

#endif /* INC_STM32F103_EXTI_H_ */
