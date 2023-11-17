/*========================================================================================
===========================   - Delay_Prog.c		     =============================
===========================   - Created: 9/4/2021	     =============================
===========================   - Author: Hussein Mohamed  =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
					*-
					*-
========================================================================================*/ 

/*============= INCLUDE LIB ==============*/
	 #include <Std_Types.h>
#include "BIT_MATH.h"
/*========================================*/	 
/*============= INCLUDE MCAL ==============*/
	#include "Delay_interface.h"
/*========================================*/	

/*========================================= Start_FUNCTION  =========================================*/

/*
*		Function To Delay By Milliseconds ( 16MHz CPU CLK )
*/
extern void Delay_vMsIn16MHz(u16 Copy_u16CountNum)
{
	volatile u16 u16Local_Count1 ;
	volatile u16 u16Local_Count2 ;
	for(u16Local_Count1 = 0; u16Local_Count1 < Copy_u16CountNum; u16Local_Count1++)
	for(u16Local_Count2 = 0; u16Local_Count2 < 3180  ; u16Local_Count2++)
	{} // Do nothing for 1 ms
}
/*========================================= End_FUNCTION    =========================================*/
/*========================================= Start_FUNCTION  =========================================*/

/*
*		Function To Delay By Microseconds ( 16MHz CPU CLK )
*/
extern void Delay_vUsIn16MHzint(u16 copy_u16CountNum)
{
	volatile u16 u16Local_Count1 ;
	volatile u16 u16Local_Count2 ;
	for(u16Local_Count1  = 0; u16Local_Count1  < copy_u16CountNum  ; u16Local_Count1++)
	for(u16Local_Count2  = 0; u16Local_Count2  < 3  ; u16Local_Count2++)
	{} // Do nothing for 1 ms
}
/*========================================= End_FUNCTION    =========================================*/

