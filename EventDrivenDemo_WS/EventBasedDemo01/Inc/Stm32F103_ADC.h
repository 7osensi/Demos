/*
 * Smt32F103_ADC.h
 *
 *  Created on: Jun 26, 2023
 *      Author: Hussein Mohamed
 */

#ifndef INC_STM32F103_ADC_H_
#define INC_STM32F103_ADC_H_

/*================================== #include ==================================*/
#include"stm32f103.h"
#include"BIT_MATH.h"

/*================================== #define ==================================*/

/*================================== struct ===================================*/

/**
  * @brief  ADC handle Structure definition
  */

typedef enum{
	ADC_CH0 = 0,
	ADC_CH1 = 1,
	ADC_CH2 = 2,
	ADC_CH3 = 3,
	ADC_CH4 = 4,
	ADC_CH5 = 5,
	ADC_CH6 = 6,
	ADC_CH7 = 7,
	ADC_CH8 = 8,
	ADC_CH9 = 9,
	ADC_CH10 = 10,
	ADC_CH11 = 11,
	ADC_CH12 = 12,
	ADC_CH13 = 13,
	ADC_CH14 = 14,
	ADC_CH15 = 15,
	ADC_CH16 = 16,
	ADC_CH17 = 17,
}ADC_ChannelNumber;

typedef struct
{
	ADC_t *pADCx;
	ADC_ChannelNumber ChannelNumber;
}ADC_HandleTypeDef;


/*******************************************************************************
/                                                  			     				/
/                	   			ADC Driver APIs                          		/
/                                                            	 				/
********************************************************************************/
extern void ADC_Init(ADC_HandleTypeDef *pADCxHandle);
extern void ADC_Conversion(void);
extern u16 ADC_Read(ADC_HandleTypeDef *pADCxHandle);

#endif /* INC_STM32F103_ADC_H_ */
