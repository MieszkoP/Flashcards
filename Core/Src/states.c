/*
 * states.c
 *
 *  Created on: Mar 16, 2025
 *      Author: mieszko
 */


#include "states.h"


unsigned int State_FlashCardNumber = 0;
unsigned int State_CategoryNumber =0;

enum State_Main currentStateMain = CATEGORY_SELECTION;
enum State_Option currentStateOption = DEFAULT;
enum State_FlashCardSide currentStateFlashCardSide = QUESTION;

