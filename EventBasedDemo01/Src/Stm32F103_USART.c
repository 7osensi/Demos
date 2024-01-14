/*
 * Stm32F103_UART.c
 *
 *  Created on: Dec 12, 2023
 *      Author: 7osensi
 */
#include <Stm32F103_USART.h>

void (*UARTptrToFunction)(void) = NULL;

void USART_PeriClockControl(USART_t *pUSARTx, u8 EnorDi) {
	if(pUSARTx == MUSART1) {
		switch(EnorDi) {
			case ENABLE:
				USART1_PCLK_EN();
				break;
			case DISABLE:
				USART1_PCLK_DIS();
			default:
				break;
		}
	}
	else if(pUSARTx == MUSART2) {
		switch(EnorDi) {
			case ENABLE:
				USART2_PCLK_EN();	break;
			case DISABLE:
				USART2_PCLK_DIS();	break;
			default:				break;
		}
	}
	else if(pUSARTx == MUSART3) {
		switch(EnorDi) {
			case ENABLE:
				USART3_PCLK_EN();	break;
			case DISABLE:
				USART3_PCLK_DIS();	break;
			default:				break;
		}
	}
}

void USART_PeriControl(USART_t *pUSARTx, u8 EnorDi) {
	if(EnorDi == ENABLE) {
		pUSARTx->USART_CR1 |= (1 << 13);
	}
	else if(EnorDi == DISABLE) {
		pUSARTx->USART_CR1 &= ~(1 << 13);
	}
}

void USART_Init(USART_Handle_t *pUSARTHandle) {
	u32 tempReg = 0;
	/* Enable clock  */
	USART_PeriClockControl(pUSARTHandle->pUSARTx, ENABLE);

	USART_PeriControl(pUSARTHandle->pUSARTx, ENABLE);

	/**************************************************************/
	/* USART_Mode  USART_Mode  USART_Mode  USART_Mode  USART_Mode */
	/**************************************************************/
	if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_TX){
		tempReg |= (1 << 3); // TX only
	}
	else if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_RX){
		tempReg |= (1 << 2); // RX only
	}
	else if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_TXRX){
		tempReg |= (1 << 3); // TX
		tempReg |= (1 << 2); // RX
	}

	/**************************************************************/
	/* USART_WordLength  USART_WordLength  USART_WordLength       */
	/**************************************************************/
	if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLEN_8BITS) {
		tempReg &= ~(1 << 12); // 8-bit word length
	}
	else if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLEN_9BITS) {
		tempReg |= (1 << 12); // 9-bit word length
	}

	/**************************************************************/
	/* USART_ParityControl  USART_ParityControl  		          */
	/**************************************************************/
	if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE) {
		tempReg &= ~(1 << 10); // parity disable
	}
	else if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_EVEN) {
		tempReg |= (1 << 10); // parity enable
		tempReg &= ~(1 << 9); // even parity
	}
	else if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_ODD) {
		tempReg |= (1 << 10); // parity enable
		tempReg |= (1 << 9); // odd parity
	}

	pUSARTHandle->pUSARTx->USART_CR1 |= tempReg; // Initialize CR1 Register

    tempReg=0; // Zeroing tempReg

	/**************************************************************/
	/* USART_NoOfStopBits  USART_NoOfStopBits  USART_NoOfStopBits */
	/**************************************************************/
    if(pUSARTHandle->USART_Config.USART_NoOfStopBits == USART_STOPBITS_1) {
    	tempReg &= ~(1 << 12);
    }
    else {
    	tempReg |= pUSARTHandle->USART_Config.USART_NoOfStopBits << 12;
    }

    /* Programming CR2 register */
    pUSARTHandle->pUSARTx->USART_CR2 |= tempReg; // Initialize CR2 Register

    tempReg=0; // Zeroing tempReg

    /**************************************************************/
    /* USART_HWFlowControl  USART_HWFlowControl  				  */
    /**************************************************************/
    if ( pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS) {
        tempReg |= (1 << 9); // Enabling CTS Flow control
    }
    else if (pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_RTS) {
        tempReg |= (1 << 10); // Enabling RTS Flow control
    }
    else if (pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS_RTS) {
        /* Enabling both CTS and RTS Flow control */
        tempReg |= (1 << 10);
        tempReg |= (1 << 9);
    }
    pUSARTHandle->pUSARTx->USART_CR3 |= tempReg;

    USART_SetBaudRate(pUSARTHandle->pUSARTx, pUSARTHandle->USART_Config.USART_Baud);

    /* Receive interrupt */
    pUSARTHandle->pUSARTx->USART_CR1 |= (1 << 5);
}

void USART_SetBaudRate(USART_t *pUSARTx, u32 BaudRate)
{
    /* HSI is used as the clock source which is 8MHz */
    u16 usartdiv;

    usartdiv = (8000000 / BaudRate); // eg. BR = 9600 >> usartdiv = 52


    /* Placing Mantissa part in appropriate bit position. USART_BRR */
    pUSARTx->USART_BRR = (((usartdiv / 16) << 4) | ((usartdiv % 16) << 0));
}

/* Receive data blocking mode */
void USART_ReceiveByte(USART_t *pUSARTx, u8 *pRxBuffer) {
	/* Wait for data to be received */
	while(!(pUSARTx->USART_SR >> 5 & 1));

	*pRxBuffer = pUSARTx->USART_DR;
}

/* Receive data blocking mode */
void USART_SendByte(USART_t *pUSARTx, u8 *pRxBuffer) {
	/* Wait for data to be send */
	while(!(pUSARTx->USART_SR >> 7 & 1));

	pUSARTx->USART_DR = *pRxBuffer;
}

void UART_CB_Assignment(void (*Callback_ptr)(void)) {
	UARTptrToFunction = Callback_ptr;
}

void USART1_IRQHandler(void) {
	if (MUSART1->USART_SR >> 5 & 1) {
		UARTptrToFunction();
	}
}



