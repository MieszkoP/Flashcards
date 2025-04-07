/*
 * structures.h
 *
 *  Created on: Mar 16, 2025
 *      Author: mieszko
 */

#ifndef INC_STRUCTURES_H_
#define INC_STRUCTURES_H_

#include "stddef.h"

typedef struct Question
{
	wchar_t* data;
} Question;

typedef union Answer
{
	wchar_t* string;
	wchar_t** picture2D;
	wchar_t* pictureMap;
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
extern Category* allCategories;

#endif /* INC_STRUCTURES_H_ */
