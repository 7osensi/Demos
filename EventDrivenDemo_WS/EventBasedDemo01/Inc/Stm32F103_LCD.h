/*
 * Stm32F103_LCD.h
 *
 *  Created on: May 19, 2023
 *      Author: Hussein Mohamed
 */

#ifndef INC_STM32F103_LCD_H_
#define INC_STM32F103_LCD_H_

/*================================== #include  ==================================*/
/*================================== #include  ==================================*/
/*================================== #include  ==================================*/
#include"stm32f103.h"
#include"Stm32F103_GPIO.h"

/*================================== #define  ==================================*/
/*================================== #define  ==================================*/
/*================================== #define  ==================================*/

/*================================== SELECT_LCD_MODE ==================================*/
#define _8_BIT_MODE      8
#define _4_BIT_MODE      4

/* Option_1 -> [ _8_BIT_MODE ]   */
/* Option_2 -> [ _4_BIT_MODE ]   */
#define LCD_MODE                      _4_BIT_MODE

/*=============== SELECT_LCD_PINS ===============*/
#if   LCD_MODE   ==   _8_BIT_MODE
#define LCD_DATA0_PIN                   GPIO_PIN_0
#define LCD_DATA1_PIN                   GPIO_PIN_1
#define LCD_DATA2_PIN                   GPIO_PIN_2
#define LCD_DATA3_PIN                   GPIO_PIN_3
#define LCD_DATA4_PIN                   GPIO_PIN_4
#define LCD_DATA5_PIN                   GPIO_PIN_5
#define LCD_DATA6_PIN                   GPIO_PIN_6
#define LCD_DATA7_PIN                   GPIO_PIN_7
#define LCD_EN_PIN                      GPIO_PIN_8
#define LCD_RS_PIN                      GPIO_PIN_9

#elif LCD_MODE   ==   _4_BIT_MODE
#define LCD_DATA4_PIN                   GPIO_PIN_NO_15
#define LCD_DATA5_PIN                   GPIO_PIN_NO_14
#define LCD_DATA6_PIN                   GPIO_PIN_NO_13
#define LCD_DATA7_PIN                   GPIO_PIN_NO_12

#define LCD_EN_PIN                      GPIO_PIN_NO_8
#define LCD_RS_PIN                      GPIO_PIN_NO_11

#endif

/*==================== SELECT_LCD_DATA_PORT ====================*/
#define LCD_DATA_PORT                   MGPIOB  /* _GPIOB_PORT */

/*==================== SELECT_LCD_CTRL_PORT ====================*/
#define LCD_CTRL_PORT                   MGPIOA  /* _GPIOA_PORT  */


/*======================== LCD_COMMANDS ========================*/
#define LCD_CLEAR                              0x01
#define LCD_RETURN_HOME                        0x02
#define LCD_UNDERLINE_ON                       0x03
#define LCD_BLINK_CURSOR_ON                    0x04
#define LCD_FIRST_ROW                          0x05
#define LCD_SECOND_HOME                        0x06
#define DISPLAY_ON_CURSOR_OFF                  0x0C
#define _8_BIT_MODE_COMAND                     0x38
#define _4_BIT_MODE_COMAND                     0x33
#define _4_BIT_MODE_COMAND_1                   0x33
#define _4_BIT_MODE_COMAND_2                   0x32
#define _4_BIT_MODE_COMAND_3                   0x28
#define LCD_R0_C0_COMAND                       0x80
#define LCD_R1_C0_COMAND                       0xC0

/*==================== APIs Prototypes ====================*/
/*==================== APIs Prototypes ====================*/
/*==================== APIs Prototypes ====================*/

extern void HAL_LCD_LCDInit(void);
extern void HAL_LCD_LCDWriteCharacter(u8);
extern void HAL_LCD_LCDWriteString(u8*);
extern void HAL_LCD_LCDWriteNumber(s32);
extern void HAL_LCD_LCDGoTo(u8, u8);
void HAL_LCD_LCDWriteCommand(u8 u8Command);
extern void HAL_LCD_LCDClear(void);

#endif /* INC_STM32F103_LCD_H_ */
