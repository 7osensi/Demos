/*
 * Stm32F103_AFIO.c
 *
 *  Created on: May 15, 2023
 *      Author: Hussein Mohamed
 */

/*================================== #include ==================================*/
/*================================== #include ==================================*/
/*================================== #include ==================================*/
#include"Stm32F103_AFIO.h"

/* Function To Select Pin From Line Or Select Port From Line */
void MCAL_AFIO_SelectPort(u8 u8LineNumber, u8 u8PortID)
{
	if(u8LineNumber <= 3) {
		/* Clear For Safety */
//		MAFIO->EXTICR1 &= ~(0b1111 << (4 * u8LineNumber) );

		MAFIO->EXTICR1 |= (u8PortID << (4 * u8LineNumber) );
	}
	else if(u8LineNumber <= 7) {
		MAFIO->EXTICR2 |= (u8PortID << (4 * (u8LineNumber - 4)) );
	}
	else if(u8LineNumber <= 11) {
		MAFIO->EXTICR3 |= (u8PortID << (4 * (u8LineNumber - 8)) );
	}
	else if(u8LineNumber <= 15) {
		MAFIO->EXTICR4 |= (u8PortID << (4 * (u8LineNumber - 12)) );
	}
	else {
		/* Do Nothing */
	}
}
