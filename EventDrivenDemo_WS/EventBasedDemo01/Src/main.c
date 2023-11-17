/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include"stm32f103.h"
#include"Stm32f103_GPIO.h"
#include"Stm32f103_EXTI.h"
#include"Stm32f103_AFIO.h"
#include"Stm32f103_LCD.h"


//void vToggleLedBLUE_CB() {
//	MCAL_GPIO_IRQHandling(GPIO_PIN_NO_11);
//	MCAL_GPIO_ToggleOutputPin(MGPIOC, 14);
//}

/* Declare global variables */

u8 events[2];

enum events {
	PB1_EV = 0,
	PB2_EV
};

void HandleEvent() {
	if(events[0] == '1') {
		if(MCAL_GPIO_ReadInputPin(MGPIOB, 11) == 0) {
			MCAL_GPIO_ToggleOutputPin(MGPIOC, 14);
		}
	}
	else if(events[1] == '1') {
		if(MCAL_GPIO_ReadInputPin(MGPIOB, 0) == 0) {
			MCAL_GPIO_ToggleOutputPin(MGPIOA, 2);
		}
	}
}

void SetEvent(u8 eventNum) {
	if(eventNum == PB1_EV) {
		events[0] = '1';
	}
	else if(eventNum == PB2_EV) {
		events[1] = '1';
	}
}


void delay()
{
	for(u32 i = 0; i < 500000 / 2; i++);
}

int main(void)
{
	/* Activate RCC for GPIOC */
	GPIOA_PCLK_EN();
	/* Activate RCC for GPIOB */
	GPIOB_PCLK_EN();
	/* Activate RCC for GPIOC */
	GPIOC_PCLK_EN();

	/* Initialize LCD */
	HAL_LCD_LCDInit();

	/* Configure SW1 (B11) as input */
	GPIO_PinConfig_t PB_B11 = {11, INPUT_MODE, INPUT_PU_PL_MODE};
	GPIO_Handle_t SW1 = {MGPIOB, PB_B11};
	MCAL_GPIO_Init(&SW1);

	/* Configure SW1 (B0) as input */
	GPIO_PinConfig_t PB_B0 = {0, INPUT_MODE, INPUT_PU_PL_MODE};
	GPIO_Handle_t SW2 = {MGPIOB, PB_B0};
	MCAL_GPIO_Init(&SW2);

	GPIO_PinConfig_t LED_C14 = {14, OUTPUT_10MHZ_MODE, GP_OUTPUT_PU_PL_MODE};
	GPIO_Handle_t LED_BLUE = {MGPIOC, LED_C14};
	MCAL_GPIO_Init(&LED_BLUE);

	GPIO_PinConfig_t LED_A2 = {2, OUTPUT_10MHZ_MODE, GP_OUTPUT_PU_PL_MODE};
	GPIO_Handle_t LED_RED1 = {MGPIOA, LED_A2};
	MCAL_GPIO_Init(&LED_RED1);

	/*==================== Interrupt Configurations for SW1 ====================*/
	AFIO_PCLK_EN();	/* AFIO Clock Enable */
	MCAL_AFIO_SelectPort(11, 1); /* Line Number, Port ID */
	MCAL_EXTI_InterruptEdgeType(11, EXTI_F_EDGE);
	MCAL_GPIO_IRQConfig(40 , EXTI_ENABLE);
	MCAL_EXTI_Enable(11);

	/*==================== Interrupt Configurations for SW2 ====================*/
//	MCAL_AFIO_SelectPort(0, 1); /* Line Number, Port ID */
//	MCAL_EXTI_InterruptEdgeType(0, EXTI_F_EDGE);
//	MCAL_GPIO_IRQConfig(6 , EXTI_ENABLE);
//	MCAL_EXTI_Enable(0);

//	HAL_LCD_LCDClear();
//	u8 string[] = "Hello System";
//	HAL_LCD_LCDWriteString(string);

    /* Loop forever */
	for(;;) {}
}

void EXTI15_10_IRQHandler(void) {
	MCAL_GPIO_IRQHandling(GPIO_PIN_NO_11);
	SetEvent(PB1_EV);
}

void EXTI0_IRQHandler(void) {
	MCAL_GPIO_IRQHandling(GPIO_PIN_NO_0);
	SetEvent(PB2_EV);
}
