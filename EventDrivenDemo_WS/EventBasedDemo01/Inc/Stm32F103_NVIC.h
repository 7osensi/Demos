/*
 * Stm32F103_NVIC.h
 *
 *  Created on: May 16, 2023
 *      Author: Hussein Mohamed
 */

#ifndef INC_STM32F103_NVIC_H_
#define INC_STM32F103_NVIC_H_

/*================================== #include ==================================*/
#include"stm32f103.h"

/*================================== #define ==================================*/

/*****************************************************************
/                                                  			     /
/                	   NVIC Driver APIs                          /
/                                                            	 /
*****************************************************************/
void MCAL_NVIC_EnableInterrupt(u8 IRQNumber, u8 IRQStatus);

#endif /* INC_STM32F103_NVIC_H_ */
