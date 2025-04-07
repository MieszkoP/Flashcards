/*
 * LCD.h
 *
 *  Created on: Mar 26, 2025
 *      Author: mieszko
 */
#include "stm32f1xx_hal.h"
#ifndef INC_LCD_H_
#define INC_LCD_H_

#define LCD_CS  	GPIO_PIN_8
#define LCD_AO     	GPIO_PIN_6
#define LCD_SDA   	GPIO_PIN_5
#define LCD_SCK 	GPIO_PIN_4
#define LCD_REST 	GPIO_PIN_7

#define LCD_W 128
#define LCD_H 160
extern uint16_t BACK_COLOR, POINT_COLOR;
extern uint8_t asc2_1608[1520];
extern unsigned int size_of_prev_string;
void Lcd_Init(void);
void LCD_Clear(uint16_t Color);
void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
void LCD_WR_DATA8(char da);
void LCD_WR_REG(char da);
void LCD_WR_DATA(uint16_t da);
void LCD_DrawPoint(uint16_t x,uint16_t y);
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t mode);
void LCD_Clear_size(uint16_t Color, int x, int y, int x_delta);
uint8_t LCD_ShowString(uint16_t x,uint16_t y,const uint8_t *p);

#endif /* INC_LCD_H_ */
