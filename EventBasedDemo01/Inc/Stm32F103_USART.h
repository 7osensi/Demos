/*
 * Stm32F103_UART.h
 *
 *  Created on: Dec 12, 2023
 *      Author: 7osensi
 */

#ifndef STM32F103_USART_H_
#define STM32F103_USART_H_

#include "stm32f103.h"
#include "Std_Types.h"

/*
 * Configuration structure for USARTx peripheral
 */
typedef struct
{
	u8 USART_Mode;
	u32 USART_Baud;
	u8 USART_NoOfStopBits;
	u8 USART_WordLength;
	u8 USART_ParityControl;
	u8 USART_HWFlowControl;
}volatile USART_Config_t;


/*
 * Handle structure for USARTx peripheral
 */
typedef struct
{
	USART_t *pUSARTx;
	USART_Config_t   USART_Config;
}volatile USART_Handle_t;

/*
 *@USART_Mode
 *Possible options for USART_Mode
 */
#define USART_MODE_ONLY_TX      0
#define USART_MODE_ONLY_RX      1
#define USART_MODE_TXRX         2


/*
 *@USART_OR_UART
 *Possible options for USART_OR_UART
 */
//#define UART_MODE 0
//#define USART_MODE 1

/*
 *@USART_Baud
 *Possible options for USART_Baud
 */
#define USART_STD_BAUD_1200					1200
#define USART_STD_BAUD_2400					400
#define USART_STD_BAUD_9600					9600
#define USART_STD_BAUD_19200 				19200
#define USART_STD_BAUD_38400 				38400
#define USART_STD_BAUD_57600 				57600
#define USART_STD_BAUD_115200 				115200
#define USART_STD_BAUD_230400 				230400
#define USART_STD_BAUD_460800 				460800
#define USART_STD_BAUD_921600 				921600
#define USART_STD_BAUD_2M 					2000000
#define SUART_STD_BAUD_3M 					3000000


/*
 *@USART_NoOfStopBits
 *Possible options for USART_NoOfStopBits
 */
#define USART_STOPBITS_1     0
#define USART_STOPBITS_0_5   1
#define USART_STOPBITS_2     2
#define USART_STOPBITS_1_5   3

/*
 *@USART_WordLength
 *Possible options for USART_WordLength
 */
#define USART_WORDLEN_8BITS  0
#define USART_WORDLEN_9BITS  1

/*
 *@USART_ParityControl
 *Possible options for USART_ParityControl
 */
#define USART_PARITY_DISABLE   	0
#define USART_PARITY_EN_EVEN  	1
#define USART_PARITY_EN_ODD   	2



/*
 *@USART_HWFlowControl
 *Possible options for USART_HWFlowControl
 */
#define USART_HW_FLOW_CTRL_NONE    	0
#define USART_HW_FLOW_CTRL_CTS    	1
#define USART_HW_FLOW_CTRL_RTS    	2
#define USART_HW_FLOW_CTRL_CTS_RTS	3

/*
 */
#define FLAG_SET					1
#define FLAG_RESET					0

/*
 * USART Flags
 */
#define USART_FLAG_TXE      ( 1 <<  7) // USART_SR_TXE
#define USART_FLAG_RXNE     ( 1 <<  5) // USART_SR_RXNE
#define USART_FLAG_TC       ( 1 <<  6) // USART_SR_TC

/*
 * Application states
 */
#define USART_READY         0
#define USART_BUSY_IN_RX    1
#define USART_BUSY_IN_TX    2


/* Application events */
#define USART_EVENT_TX_CMPLT    0
#define	USART_EVENT_RX_CMPLT    1
#define	USART_EVENT_IDLE        2
#define	USART_EVENT_CTS         3
#define	USART_EVENT_PE          4
#define	USART_ERR_FE            5
#define	USART_ERR_NE            6
#define	USART_ERR_ORE           7

/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/
/*
 * Peripheral Clock setup
 */
void USART_PeriClockControl(USART_t *pUSARTx, u8 EnorDi);
void USART_PeriControl(USART_t *pUSARTx, u8 EnorDi);


/*
 * Init and De-init
 */
void USART_Init(USART_Handle_t *pUSARTHandle);
void USART_DeInit(USART_t *pUSARTx);

void USART_SetBaudRate(USART_t *pUSARTx, u32 BaudRate);

/*
 * Data Send and Receive
 */
void USART_SendByte(USART_t *pUSARTx, u8 *pTxBuffer);
void USART_ReceiveByte(USART_t *pUSARTx, u8 *pRxBuffer);
void USART_SendByteIT(USART_Handle_t *pUSARTHandle,u8 *pTxBuffer);
void USART_ReceiveByteIT(USART_Handle_t *pUSARTHandle);

/*
 * IRQ Configuration and ISR handling
 */
void USART_IRQInterruptConfig(u8 IRQNumber, u8 EnorDi);
void USART_IRQPriorityConfig(u8 IRQNumber, u32 IRQPriority);
void USART_IRQHandling(USART_Handle_t *pHandle);

/*
 * Other Peripheral Control APIs
 */
void USART_PeripheralControl(USART_t *pUSARTx, u8 EnOrDi);
u8 USART_GetFlagStatus(USART_t *pUSARTx , u32 FlagName);
void USART_ClearFlag(USART_t *pUSARTx, u16 StatusFlagName);

/*
 * Application callback
 */
void USART_ApplicationEventCallback(USART_Handle_t *pUSARTHandle,u8 AppEv);

#endif /* STM32F103_USART_H_ */
