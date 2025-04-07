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
unsigned int len_wstr(const wchar_t* source);
void copy_wstr(wchar_t* dest, const wchar_t* source);
FlashCard CreateFlashcard(const wchar_t* question_data, const wchar_t* answer_data);
void TestInit();
void copy_wstr_to_str(uint8_t* const dest, const wchar_t* const source);
#endif /* INC_CREATORS_H_ */
