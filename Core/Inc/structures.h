/*
 * structures.h
 *
 *  Created on: Mar 16, 2025
 *      Author: mieszko
 */

#ifndef INC_STRUCTURES_H_
#define INC_STRUCTURES_H_

#include "stddef.h"
#include <stdint.h>
#include <stdbool.h>
typedef struct Question
{
	uint16_t* data;
} Question;

typedef union Answer
{
	uint16_t* string;
	uint16_t** picture2D;
	uint16_t* pictureMap;
} Answer;

typedef struct FlashCard
{
	Question question;
	Answer answer;
} FlashCard;

typedef struct Category
{
	wchar_t* name;
	FlashCard* flashcard;
	//unsigned int currentFlashcard;
	unsigned int numberOfFlashCards;
} Category;

extern unsigned int numberOfCategories;
extern bool InitializedByTestInit;
extern Category* allCategories;

#endif /* INC_STRUCTURES_H_ */
