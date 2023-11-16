/*==============================================================================================
===============================   - RCC				 		     ===============================
===============================   - RCC_interface.h				 ===============================
===============================   - Created:24/2/2023			 ===============================
===============================   - Author: Hussein Mohamed      ===============================
===============================   - Version : _1_				 ===============================
===============================   - Note :
									     *-
									     *-
=================================================================================================*/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include <Std_Types.h>
#include "stm32f103.h"
#include "RCC_config.h"

	/*
	Configure RCC Enum
	- Crystal CLK SRC (RCC_HSE : External , RCC_HSI : Internal  , RCC_PLL Use_PLL) ----> ClkSrcName_t
	- For External Crystal CLK From (HSE_Crystal , HSE_RC )---> HSESrcName_t
	- For PLL Can Be For (HSE, HSI) ---------> PllSrcName_t
	- PLL  Prescaler ( M /(2:63) N *(50:432) P Q )           ---> User Select By #define
	- Select Bus ( AHB, APB1, APB2 )  ---> BusName_t
	*/
	
/**********   **********/
   typedef enum{
	   AHB =0,
	   APB1,
	   APB2
   }BusName_t;
	  
/**********   **********/
typedef enum{
	RCC_HSE = 0,
	RCC_HSI ,
	RCC_PLL
}CLKSrcName_t ;

/**********   **********/
typedef enum{
	HSE_PLL  = 0U,
	HSI_PLL,
}PLLSrc_t;

/**********   **********/
typedef enum{
	HSE_CRYSTAL  = 0U ,
	HSE_RC,
}HSESrc_t;

/* MCO_1 Prescaler */
typedef enum
{
	MCO_1_Div_1 =0 ,
	MCO_1_Div_2    ,
	MCO_1_Div_3    ,
	MCO_1_Div_4    ,
	MCO_1_Div_5    ,
}MCO_1_Pre_t;

/**********   **********/
#define AHB_BUS    		0U
#define APB1_BUS   		2U
#define APB2_BUS   		3U
/**********   **********/
#define  HSE   			0U
#define  HSI   			1U
#define  PLL   			2U
/**********   **********/
#define _HSE_CRYSTAL  	0U
#define _HSE_RC       	1U
/**********   **********/
#define _HSE_PLL       	0U
#define _HSI_PLL       	1U
/**********   **********/
#define MC0_1_LSE   	0U
#define MC0_1_HSE   	1U
#define MC0_1_HSI   	2U
#define MC0_1_PLL   	3U

/*=========================================== Prototypes ===========================================*/

/*
- Function To Enable Peripheral :
				- BusName_t      :  The Bus Of The Peripheral ( AHB, APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
				- Copy_u8PerName :  The Order Of Peripheral On The Selected Register
*/
void MRCC_vEnableClock(BusName_t BusName , u8 Copy_u8PerNum);

/*
- Function To Disable Peripheral :
				- BusName_t      :  The Bus Of The Peripheral ( AHB, APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
				- Copy_u8PerName :  The Order Of Peripheral On The Selected Register
*/
void MRCC_vDisableClock(BusName_t BusName , u8 Copy_u8PerNum);

/*Function To Enable Security System*/
void MRCC_vEnableSecuritySystem(void);

/*Function To Disable Security System */
void MRCC_vDisableSecuritySystem(void);

/* Function To Set System CLK  */
extern void MRCC_vInitSystemCLK(void);


/*********** Macros Of :- RCC AHB CLK ENABLE ***************/
#define _PERIPHERAL_EN_DMA1EN    				0U
#define _PERIPHERAL_EN_DMA2EN    				1U
#define _PERIPHERAL_EN_SRAMEN    				2U

/********* Macros Of :- RCC APB1 peripheral clock enable register *********/
#define PERIPHERAL_EN_TIM2EN					0U
#define PERIPHERAL_EN_TIM3EN					1U
#define PERIPHERAL_EN_TIM4EN					2U
#define PERIPHERAL_EN_TIM5EN					3U
#define PERIPHERAL_EN_TIM6EN					4U
#define PERIPHERAL_EN_TIM7EN					5U
#define PERIPHERAL_EN_WWDEN						11U
#define PERIPHERAL_EN_SPI2EN					14U
#define PERIPHERAL_EN_SPI3EN					15U
#define PERIPHERAL_EN_USART2EN					17U
#define PERIPHERAL_EN_USART3EN					18U
#define PERIPHERAL_EN_USART4EN					19U
#define PERIPHERAL_EN_USART5EN					20U
#define PERIPHERAL_EN_I2C1EN					21U
#define PERIPHERAL_EN_I2C2EN					22U


/**********  Macros Of :- RCC APB2 peripheral clock enable register (RCC_APB2ENR) *********/
#define _PERIPHERAL_EN_AFIO      				0U
#define _PERIPHERAL_EN_IOPAEN     				2U
#define _PERIPHERAL_EN_IOPBEN     				3U
#define _PERIPHERAL_EN_IOPCEN     				4U
#define _PERIPHERAL_EN_IOPDEN     				5U
#define _PERIPHERAL_EN_IOPEEN     				6U
#define _PERIPHERAL_EN_IOPFEN     				7U
#define _PERIPHERAL_EN_IOPGEN     				8U
#define PERIPHERAL_EN_ADC1						9U
#define PERIPHERAL_EN_ADC2						10U
#define PERIPHERAL_EN_TIM1      				11U
#define PERIPHERAL_EN_SPI1						12U
#define PERIPHERAL_EN_TIM8						13U
#define PERIPHERAL_EN_USART1					14U
#define PERIPHERAL_EN_ADC3						15U
#define PERIPHERAL_EN_TIM9      				19U
#define PERIPHERAL_EN_TIM10      				20U
#define PERIPHERAL_EN_TIM11      				21U
/*****************************************************************************************/

#endif //RCC_INTERFACE_H
