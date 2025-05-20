/*
 * reception.c
 *
 *  Created on: Apr 5, 2025
 *      Author: mieszko
 */
#include "reception.h"

void Flash_WritePage(uint32_t address, uint16_t* data, uint16_t length)
{
    HAL_FLASH_Unlock();

    FLASH_EraseInitTypeDef eraseInitStruct;
    uint32_t pageError = 0;

    eraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
    eraseInitStruct.PageAddress = address;
    eraseInitStruct.NbPages     = 1;

    if (HAL_FLASHEx_Erase(&eraseInitStruct, &pageError) != HAL_OK)
    {
        HAL_FLASH_Lock();
        return;
    }

    for (uint16_t i = 0; i < length; i++)
    {
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address + i * 2, data[i]) != HAL_OK)
        {
            HAL_FLASH_Lock();
            return;
        }
    }

    HAL_FLASH_Lock();
}

void SaveIncomingDataToFlashMemory()
{
	uint8_t buffer[1024];
	bool isEnd = false;
	int page_number = 0;
	while(!isEnd)
	{
		HAL_UART_Receive(&huart2, buffer, 1024, HAL_MAX_DELAY);
		uint16_t buffer2[512];
		for (int i = 0; i < 512; i++)
		{
			buffer2[i] = (uint16_t)(buffer[2*i] | (buffer[2*i+1] << 8));  // little endian
			if(buffer2[i]==0x0004)
			{
				isEnd=true;
			}
		}
		Flash_WritePage(FLASH_START_ADDRESS+page_number*1024, buffer2, 512);
	}
}

void FreeCurrentSpace()
{
	for(int i = 0; i<numberOfCategories; i++)
	{
		for(int j = 0; j< allCategories[i].numberOfFlashCards; j++)
		{
			free(allCategories[i].flashcard[j].answer.string);
			free(allCategories[i].flashcard[j].question.data);
		}
		free(allCategories[i].flashcard);
	}
	free(allCategories);
}

void MapFlashMemoryToStructures()
{
	FreeCurrentSpace();
	uint16_t* it = FLASH_START_ADDRESS;
	numberOfCategories = GetNumberOfCategories();
	allCategories = (Category*)calloc(numberOfCategories,sizeof(Category));
	int currentCategory = -1;
	int currentFlashcard = -1;
	while(*it!=0x0004)
	{
		if(*it==0x0001)
		{
			currentCategory +=1;
			currentFlashcard = -1;
			allCategories[currentCategory].name = (it+1);
			int numberOfFlashcardsInCategory = GetNumberOfFlashcardsInCategory();
			allCategories[currentCategory].flashcard = (FlashCard*)calloc(numberOfFlashcardsInCategory,sizeof(FlashCard));
		}
		if(*it==0x0002)
		{
			currentFlashcard+=1;
			allCategories[currentCategory].flashcard[currentFlashcard].question.data = (it+1);

		}
		if(*it==0x0003)
		{
			allCategories[currentCategory].flashcard[currentFlashcard].answer.string = (it+1);
		}
		it++;
	}
}

int GetNumberOfCategories()
{
	int counter = 0;
	uint16_t* it = FLASH_START_ADDRESS;
	while(*it!=0x0004)
	{
		if(*it==0x0001)
		{
			counter +=1;
		}
		it++;
	}
	return counter;
}

int GetNumberOfFlashcardsInCategory(const uint16_t* startAdress)
{
	int counter = 0;
	uint16_t* it = startAdress;
	while(*it!=0x0001)
	{
		if(*it==0x0002)
		{
			counter +=1;
		}
		it++;
	}
	return counter;
}

