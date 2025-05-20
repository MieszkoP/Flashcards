/*
 * signals.c
 *
 *  Created on: Mar 16, 2025
 *      Author: mieszko
 */
#include "signals.h"
#include "states.h"
#include "structures.h"

void ClickedBackOrOption()
{
	switch(currentStateMain)
	{
	case LEARNING:
		currentStateMain = CATEGORY_SELECTION;
	break;
	case CATEGORY_SELECTION:
		currentStateMain = UPLOAD_DATA;
		/*switch(currentStateOption)
		{
		case OPTION:
			currentStateOption = DEFAULT;
			break;
		case DEFAULT:
			//currentStateOption = OPTION;
			break;
		}*/
	break;
	case UPLOAD_DATA:
		currentStateMain = CATEGORY_SELECTION;
		break;
	}
}

void ClickedLeft()
{
	switch(currentStateOption)
	{
	case OPTION:
		//change selected option
		return;
		break;
	case DEFAULT:
		break;
	}


	switch(currentStateMain)
	{
	case LEARNING:
	if(State_FlashCardNumber>0)
	{
		State_FlashCardNumber -=1;
		currentStateFlashCardSide = QUESTION;
	}
	break;
	case CATEGORY_SELECTION:
	if(State_CategoryNumber>0)
	{
		State_FlashCardNumber = 0;
		State_CategoryNumber -=1;
	}
	break;
	case UPLOAD_DATA:
			break;
	}
}

void ClickedSelect()
{
	switch(currentStateMain)
	{
	case CATEGORY_SELECTION:
		currentStateMain = LEARNING;
		currentStateFlashCardSide = QUESTION;
		break;
	case LEARNING:
		switch(currentStateFlashCardSide)
		{
		case QUESTION:
			currentStateFlashCardSide = ANSWER;
			break;
		case ANSWER:
			currentStateFlashCardSide = QUESTION;
			break;
		}
	case UPLOAD_DATA:
			break;
	}
}

void ClickedRight()
{
	switch(currentStateOption)
	{
	case OPTION:
		//change selected option
		return;
		break;
	case DEFAULT:
		break;
	}


	switch(currentStateMain)
	{
	case LEARNING:
	if(State_FlashCardNumber<allCategories[State_CategoryNumber].numberOfFlashCards-1)
	{
		State_FlashCardNumber +=1;
		currentStateFlashCardSide = QUESTION;
	}
	break;
	case CATEGORY_SELECTION:
	if(State_CategoryNumber<numberOfCategories-1)
	{
		State_FlashCardNumber = 0;
		State_CategoryNumber +=1;
	}
	break;
	case UPLOAD_DATA:
			break;
	}
}

