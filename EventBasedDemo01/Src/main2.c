/*
 * main2.c
 *
 *  Created on: Dec 14, 2023
 *      Author: 7osensi
 */

#include <stdint.h>

#include "stm32f103.h"
#include "Stm32f103_GPIO.h"
#include "Stm32f103_EXTI.h"
#include "Stm32f103_AFIO.h"
#include "Stm32f103_LCD.h"
#include "Stm32F103_USART.h"
#include "Stm32F103_NVIC.h"
#include "ringbuf.h"


void delay()
{
	for(u32 i = 0; i < 800000 / 2; i++);
}

volatile u8 Buf = '\0';

#define RINGBUF_SIZE (128)

volatile u8 rb_buf[RINGBUF_SIZE + 1];

ringBuffer rb = {RINGBUF_SIZE, rb_buf, 0, 0};


int main(void)
{
	/* Activate RCC for GPIOA, GPIOB, GPIOC */
	GPIOA_PCLK_EN();
	GPIOB_PCLK_EN();
	GPIOC_PCLK_EN();
	/* AFIO Clock Enable */
	AFIO_PCLK_EN();

	/* Enable USART1 */
	MCAL_NVIC_EnableInterrupt(37, ENABLE);

	/* USART1_TX */
	GPIO_PinConfig_t PA_A9 = {9, OUTPUT_50MHZ_MODE, ALT_FN_OUTPUT_PU_PL_MODE};
	GPIO_Handle_t PA9 = {MGPIOA, PA_A9};
	MCAL_GPIO_Init(&PA9);

	/* USART1_RX */
	GPIO_PinConfig_t PA_A10 = {10, INPUT_MODE, FLOATING_INPUT};
	GPIO_Handle_t PA10 = {MGPIOA, PA_A10};
	MCAL_GPIO_Init(&PA10);

	/* 	u8 USART_Mode;u32 USART_Baud;u8 USART_NoOfStopBits;u8 USART_WordLength;
	u8 USART_ParityControl;u8 USART_HWFlowControl; */
	USART_Handle_t USART1H = {MUSART1, USART_MODE_TXRX, USART_STD_BAUD_9600, USART_STOPBITS_1, USART_WORDLEN_8BITS, USART_PARITY_DISABLE, USART_HW_FLOW_CTRL_NONE};

	USART_Init(&USART1H);

	HAL_LCD_LCDInit();

	HAL_LCD_LCDClear();
	HAL_LCD_LCDWriteString("Hello");

    /* Loop forever */
	for(;;) {

	}
}

void USART1_IRQHandler(void) {
	static int i = 0;
	if (MUSART1->USART_SR >> 5 & 1) {
		Buf = MUSART1->USART_DR;
		ringbuf_write(rb, Buf);
		USART_SendByte(MUSART1, &Buf);
//		HAL_LCD_LCDClear();
//		HAL_LCD_LCDWriteCharacter(rb_buf[++i]);
//		HAL_LCD_LCDWriteCharacter(Buf);
	}
}

