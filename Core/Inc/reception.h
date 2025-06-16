/*
 * reception.h
 *
 *  Created on: Apr 5, 2025
 *      Author: mieszko
 */

#ifndef INC_RECEPTION_H_
#define INC_RECEPTION_H_
#define FLASH_PAGE_SIZE     1024                    // 1 KB for STM32F103
#define FLASH_START_ADDRESS 0x08007800

//#include "stdlib.h"
//#include "structures.h"
//#include <stdint.h>
//#include <stdbool.h>
//#include "main.h"
void SaveIncomingDataToFlashMemory();
void MapFlashMemoryToStructures();
void FreeCurrentSpace();
//static uint16_t GetNumberOfCategories();
//static uint16_t GetNumberOfFlashcardsInCategory(const uint16_t* startAdress);
// static void Flash_WritePage(uint32_t address, uint16_t* data, uint16_t length);
#endif /* INC_RECEPTION_H_ */
