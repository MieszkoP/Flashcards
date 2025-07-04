/*
 * states.h
 *
 *  Created on: Mar 16, 2025
 *      Author: mieszko
 */

#ifndef INC_STATES_H_
#define INC_STATES_H_

typedef enum State_Main
{
	CATEGORY_SELECTION,
	LEARNING,
	UPLOAD_DATA
} State_Main;

typedef enum State_Option
{
	DEFAULT,
	OPTION
} State_Option;

typedef enum State_FlashCardSide
{
	QUESTION,
	ANSWER
} State_FlashCardSide;

extern unsigned int State_FlashCardNumber;
extern unsigned int State_CategoryNumber;

extern State_Main currentStateMain;
extern State_Option currentStateOption;
extern State_FlashCardSide currentStateFlashCardSide;



#endif /* INC_STATES_H_ */
