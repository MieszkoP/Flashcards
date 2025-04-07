/*
 * states.c
 *
 *  Created on: Mar 16, 2025
 *      Author: mieszko
 */


#include "states.h"


volatile unsigned int State_FlashCardNumber = 0;
volatile unsigned int State_CategoryNumber =0;

volatile enum State_Main currentStateMain = CATEGORY_SELECTION;
volatile enum State_Option currentStateOption = DEFAULT;
volatile enum State_FlashCardSide currentStateFlashCardSide = QUESTION;

