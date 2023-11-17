/*
 * Stm32F103_LCD.c
 *
 *  Created on: May 19, 2023
 *      Author: Hussein Mohamed
 */

/*================================== #include  ==================================*/
/*================================== #include  ==================================*/
/*================================== #include  ==================================*/
#include "Stm32F103_LCD.h"
#include "Delay_interface.h"
#include "Std_Types.h"

/*================================== #define  ==================================*/
/*================================== #define  ==================================*/
/*================================== #define  ==================================*/

/* When RS is low, the IR is selected and DB7-DB0 are treated as an instruction code.
 * When RS is high, the DR is selected.
 * The R/W pin specifies whether we are writing to the module (R/W=0) or reading from it (R/W=1).
 * The E pin (for “Enable”) starts a read/write operation and will be discussed in the next section. */

/*============================================   Start_Function   ============================================*/

extern void HAL_LCD_LCDInit(void)
{
#if   LCD_MODE == _8_BIT_MODE

#elif LCD_MODE == _4_BIT_MODE

	GPIO_Handle_t LCD_D4, LCD_D5, LCD_D6, LCD_D7, LCD_EN, LCD_RS;

	/* Data Pins Configuration */
	LCD_D4.pGPIOx = LCD_DATA_PORT;
	LCD_D5.pGPIOx = LCD_DATA_PORT;
	LCD_D6.pGPIOx = LCD_DATA_PORT;
	LCD_D7.pGPIOx = LCD_DATA_PORT;

	LCD_D4.GPIO_PinConfig.GPIO_PinNumber = LCD_DATA4_PIN;
	LCD_D5.GPIO_PinConfig.GPIO_PinNumber = LCD_DATA5_PIN;
	LCD_D6.GPIO_PinConfig.GPIO_PinNumber = LCD_DATA6_PIN;
	LCD_D7.GPIO_PinConfig.GPIO_PinNumber = LCD_DATA7_PIN;

	LCD_D4.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_MODE;
	LCD_D5.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_MODE;
	LCD_D6.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_MODE;
	LCD_D7.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_MODE;

	LCD_D4.GPIO_PinConfig.GPIO_PinConfiguration = GP_OUTPUT_PU_PL_MODE;
	LCD_D5.GPIO_PinConfig.GPIO_PinConfiguration = GP_OUTPUT_PU_PL_MODE;
	LCD_D6.GPIO_PinConfig.GPIO_PinConfiguration = GP_OUTPUT_PU_PL_MODE;
	LCD_D7.GPIO_PinConfig.GPIO_PinConfiguration = GP_OUTPUT_PU_PL_MODE;

	MCAL_GPIO_Init(&LCD_D4);
	MCAL_GPIO_Init(&LCD_D5);
	MCAL_GPIO_Init(&LCD_D6);
	MCAL_GPIO_Init(&LCD_D7);

	/* Control Pins Configuration */
	LCD_EN.pGPIOx = LCD_CTRL_PORT;
	LCD_RS.pGPIOx = LCD_CTRL_PORT;

	LCD_EN.GPIO_PinConfig.GPIO_PinNumber = LCD_EN_PIN;
	LCD_RS.GPIO_PinConfig.GPIO_PinNumber = LCD_RS_PIN;

	LCD_EN.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_MODE;
	LCD_RS.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_MODE;

	LCD_EN.GPIO_PinConfig.GPIO_PinConfiguration = GP_OUTPUT_PU_PL_MODE;
	LCD_RS.GPIO_PinConfig.GPIO_PinConfiguration = GP_OUTPUT_PU_PL_MODE;

	MCAL_GPIO_Init(&LCD_EN);
	MCAL_GPIO_Init(&LCD_RS);

//	Delay_vMsIn16MHz(1000); //500

	HAL_LCD_LCDWriteCommand(_4_BIT_MODE_COMAND_1);
	HAL_LCD_LCDWriteCommand(_4_BIT_MODE_COMAND_2);
	HAL_LCD_LCDWriteCommand(_4_BIT_MODE_COMAND_3);
	HAL_LCD_LCDWriteCommand(DISPLAY_ON_CURSOR_OFF);
	HAL_LCD_LCDWriteCommand(LCD_RETURN_HOME);
	HAL_LCD_LCDWriteCommand(LCD_CLEAR);
#endif
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

void HAL_LCD_LCDWriteCommand(u8 u8Command)
{

	MCAL_GPIO_WriteOutputPin(LCD_CTRL_PORT, LCD_RS_PIN, LOW);

#if LCD_MODE ==_8_BIT_MODE

#elif LCD_MODE ==_4_BIT_MODE

	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA4_PIN, GET_BIT(u8Command, 4) );
	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA5_PIN, GET_BIT(u8Command, 5) );
	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA6_PIN, GET_BIT(u8Command, 6) );
	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA7_PIN, GET_BIT(u8Command, 7) );

//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA7_PIN, u8Command & (u8)(1 << 7) );
//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA6_PIN, u8Command & (u8)(1 << 6) );
//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA5_PIN, u8Command & (u8)(1 << 5) );
//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA4_PIN, u8Command & (u8)(1 << 4) );


	MCAL_GPIO_WriteOutputPin(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);

	Delay_vMsIn16MHz(1); //1

	MCAL_GPIO_WriteOutputPin(LCD_CTRL_PORT, LCD_EN_PIN, LOW);

	Delay_vMsIn16MHz(1); //1

	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA4_PIN, GET_BIT(u8Command, 0) );
	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA5_PIN, GET_BIT(u8Command, 1) );
	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA6_PIN, GET_BIT(u8Command, 2) );
	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA7_PIN, GET_BIT(u8Command, 3) );

//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA7_PIN, u8Command & (u8)(1 << 3) );
//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA6_PIN, u8Command & (u8)(1 << 2) );
//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA5_PIN, u8Command & (u8)(1 << 1) );
//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA4_PIN, u8Command & (u8)(1 << 0) );


	MCAL_GPIO_WriteOutputPin(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);

	Delay_vMsIn16MHz(1); //1

	MCAL_GPIO_WriteOutputPin(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
#endif
	Delay_vMsIn16MHz(5); //5
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

extern void HAL_LCD_LCDWriteCharacter(u8 u8Character)
{
	/* Data Register Select */
	MCAL_GPIO_WriteOutputPin(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);

#if LCD_MODE ==_8_BIT_MODE

#elif LCD_MODE ==_4_BIT_MODE

	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA4_PIN, GET_BIT(u8Character, 4) );
	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA5_PIN, GET_BIT(u8Character, 5) );
	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA6_PIN, GET_BIT(u8Character, 6) );
	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA7_PIN, GET_BIT(u8Character, 7) );

//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA7_PIN, u8Character & (u8)(1 << 7) );
//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA6_PIN, u8Character & (u8)(1 << 6) );
//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA5_PIN, u8Character & (u8)(1 << 5) );
//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA4_PIN, u8Character & (u8)(1 << 4) );

    /* H -> L : LCD Reads The Data */
	MCAL_GPIO_WriteOutputPin(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	Delay_vMsIn16MHz(1); //1
	MCAL_GPIO_WriteOutputPin(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
	Delay_vMsIn16MHz(1); //1

	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA4_PIN, GET_BIT(u8Character, 0) );
	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA5_PIN, GET_BIT(u8Character, 1) );
	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA6_PIN, GET_BIT(u8Character, 2) );
	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA7_PIN, GET_BIT(u8Character, 3) );

//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA7_PIN, u8Character & (u8)(1 << 3) );
//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA6_PIN, u8Character & (u8)(1 << 2) );
//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA5_PIN, u8Character & (u8)(1 << 1) );
//	MCAL_GPIO_WriteOutputPin(LCD_DATA_PORT, LCD_DATA4_PIN, u8Character & (u8)(1 << 0) );

	/* H -> L : LCD Reads The Data */
	MCAL_GPIO_WriteOutputPin(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	Delay_vMsIn16MHz(1); //1
	MCAL_GPIO_WriteOutputPin(LCD_CTRL_PORT, LCD_EN_PIN, LOW);

#endif
	Delay_vMsIn16MHz(5); //5
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

extern void HAL_LCD_LCDWriteString(u8* u8String)
{
	u8 u8Character;
	while(*u8String != '\0')
	{
		u8Character = *u8String;
		HAL_LCD_LCDWriteCharacter(u8Character);
		u8String++;
	}
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

extern void HAL_LCD_LCDWriteNumber(s32 f32Number)
{
	u8 u8Arr [10] = {0};
	s8 s8Counter = 0;
	s8 s8DecimalPoint = 0;
	s32 s32Number;

	if(f32Number < 0)
	{
		f32Number *= -1;
		HAL_LCD_LCDWriteCharacter('-');
	}

	s32Number = f32Number;

	if (s32Number == 0)
	{
		HAL_LCD_LCDWriteCharacter(48);
	}

	while (s32Number != f32Number)
	{
		f32Number = f32Number * 10;
		s32Number = f32Number;
		s8DecimalPoint++;
	}


	while (s32Number != 0)
	{
		u8Arr[s8Counter] = s32Number % 10;
		s32Number = s32Number / 10;
		s8Counter++;
	}

	s8Counter--;

	while (s8Counter >= 0)
	{
		if( (s8DecimalPoint > 0) && (s8DecimalPoint - 1 == s8Counter) )
		{
			HAL_LCD_LCDWriteCharacter('.');
		}
		HAL_LCD_LCDWriteCharacter(u8Arr[s8Counter] + 48);
		s8Counter--;
	}
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

extern void HAL_LCD_LCDGoTo(u8 u8Row, u8 u8Col)
{
	u8 u8Arr[2] = {LCD_R0_C0_COMAND, LCD_R1_C0_COMAND};
	HAL_LCD_LCDWriteCommand(u8Arr[u8Row] + u8Col);
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

extern void HAL_LCD_LCDClear(void)
{
	HAL_LCD_LCDWriteCommand(LCD_CLEAR);
}
/*============================================   End_Function     ============================================*/
