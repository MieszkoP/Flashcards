/*
 * testinit.h
 *
 *  Created on: Mar 18, 2025
 *      Author: mieszko
 */

#ifndef INC_CREATORS_H_
#define INC_CREATORS_H_
#include "stm32f1xx_hal.h"
#include "structures.h"
#include "stdlib.h"
void print(const char* data, UART_HandleTypeDef* wsk_huart);
unsigned int len_str(const char* source);
unsigned int len_wstr(const uint16_t* source);
void copy_wstr(uint16_t* dest, const uint16_t* source);
FlashCard CreateFlashcard(const uint16_t* question_data, const uint16_t* answer_data);
void TestInit();
void copy_wstr_to_str(uint8_t* const dest, const uint16_t* const source);
#endif /* INC_CREATORS_H_ */
