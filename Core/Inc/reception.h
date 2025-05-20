/*
 * reception.h
 *
 *  Created on: Apr 5, 2025
 *      Author: mieszko
 */

#ifndef INC_RECEPTION_H_
#define INC_RECEPTION_H_
#define FLASH_PAGE_SIZE     1024                    // 1 KB for STM32F103
#define FLASH_START_ADDRESS 0x0800F800

#include "stdlib.h"
#include "structures.h"
#include <stdint.h>
#include <stdbool.h>
#include "main.h"
void SaveIncomingDataToFlashMemory();
void MapFlashMemoryToStructures();
uint16_t GetNumberOfCategories();
uint16_t GetNumberOfFlashcardsInCategory(const uint16_t* startAdress);
#endif /* INC_RECEPTION_H_ */
