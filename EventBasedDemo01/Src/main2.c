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



volatile u8 Buf = '\0';

volatile u8 rb_buf[RINGBUF_SIZE + 1];

ringBuffer rb = { RINGBUF_SIZE, rb_buf, {EV_INIT}, 0, 0 };

void delay();
void UART1_callbackFunction(void);

void SemaphoreWait(void);
void SemaphoreSignal(void);

void EnqueueEvent(EventType Ev, u8 data);
void DequeueEvent(Event event);

void APP_HandleQueue(void);

u16 count = 0;

u8 read = 0;

int main(void) {
	/* Activate RCC for GPIOA, GPIOB, GPIOC */
	GPIOA_PCLK_EN();
	GPIOB_PCLK_EN();
	GPIOC_PCLK_EN();
	/* AFIO Clock Enable */
	AFIO_PCLK_EN();

	// Determine the function to be called when ISR is fired
	UART_CB_Assignment(UART1_callbackFunction);

	/* Enable USART1 INT */
	MCAL_NVIC_EnableInterrupt(37, ENABLE);

	/* USART1_TX */
	GPIO_PinConfig_t PA_A9 = { 9, OUTPUT_50MHZ_MODE, ALT_FN_OUTPUT_PU_PL_MODE };
	GPIO_Handle_t PA9 = { MGPIOA, PA_A9 };
	MCAL_GPIO_Init(&PA9);

	/* USART1_RX */
	GPIO_PinConfig_t PA_A10 = { 10, INPUT_MODE, FLOATING_INPUT };
	GPIO_Handle_t PA10 = { MGPIOA, PA_A10 };
	MCAL_GPIO_Init(&PA10);

	/* 	u8 USART_Mode;u32 USART_Baud;u8 USART_NoOfStopBits;u8 USART_WordLength;
	 u8 USART_ParityControl;u8 USART_HWFlowControl; */
	USART_Handle_t USART1H = { MUSART1, { USART_MODE_TXRX, USART_STD_BAUD_9600,
	USART_STOPBITS_1, USART_WORDLEN_8BITS, USART_PARITY_DISABLE,
	USART_HW_FLOW_CTRL_NONE } };

	USART_Init(&USART1H);

	HAL_LCD_LCDInit();

	HAL_LCD_LCDClear();

	/* Loop forever */
	for (;;) { APP_HandleQueue(); }
}

void delay() {
	for (u32 i = 0; i < 800000 / 2; i++);
}

void APP_HandleQueue(void){
    Event currentEvent;
    DequeueEvent(currentEvent);

    // Process the event
    switch (currentEvent.type) {
        case EV_UART_FRAME_REC:
        	HAL_LCD_LCDWriteCommand(read); 	break;
        default:							break;
    }
}

void UART1_callbackFunction(void) {
	Buf = MUSART1->USART_DR;
	EnqueueEvent(EV_UART_FRAME_REC, Buf);
}

void EnqueueEvent(EventType Ev, u8 data) {
	SemaphoreWait();

	rb.buf[rb.write] = data;
	rb.events[rb.write].type = Ev;
	if ((rb.write + 1) >= rb.len) {
		rb.write = 0;
	} else {
		rb.write = rb.write + 1;
	}
	count++;
	SemaphoreSignal();
}

void DequeueEvent(Event event) {
	SemaphoreWait();

	if (rb.read != rb.write) {
		read = rb.buf[rb.read];
		event.type = EV_UART_FRAME_REC;
		rb.read = (rb.read < (rb.len - 1)) ? (rb.read + 1) : 0;
		count--;
	}
	SemaphoreSignal();
}

// Wait until the count is greater than zero
void SemaphoreWait(void) {
	while (count <= 0) {
	}
}


// Signal that the count has increased
void SemaphoreSignal(void) {
	count++;
}
