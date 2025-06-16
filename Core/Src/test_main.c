/*
 * test_main.c
 *
 *  Created on: Jun 14, 2025
 *      Author: mieszko
 */
#include "creators.h"
#include "displays.h"
#include "signals.h"
#include <assert.h>
#include <stdbool.h>
#include "main.h"
#include "states.h"
#include "LCD.h"

#define TEST_RUN(TEST_) DisplayTestIfFailed((TEST_), u"Function " #TEST_ " failed")

#ifdef TEST

void SystemClock_Config(void);

	static bool isCorrect;

	//creators
	bool len_str_test()
	{
		bool result = (14 == len_str("Testowy string"));
		return result;
	}

	bool len_wstr_test()
	{
		bool result = (14 == len_wstr(u"Testowy string"));
		return result;
	}

	bool copy_wstr_test()
	{
		uint16_t source[] = u"Test001";
		uint16_t dest[100];
		copy_wstr(dest, source);

		bool result = true;
		uint16_t* it_source = source;
		for(uint16_t* it = dest; (*it)!=0x0; it++)
		{
			result = result && (*it==*it_source);
			it_source++;
		}
		return result;
	}

	bool copy_wstr_to_str_test()
	{
		uint16_t source[] = u"Test001";
		uint8_t dest[100];
		copy_wstr_to_str(dest, source);

		bool result = true;
		uint16_t* it_source = source;
		for(uint8_t* it = dest; (*it)!=0x0; it++)
		{
			result = result && (*it==*it_source);
			it_source++;
		}
		return result;
	}

	//Test of application logic:

	bool application_start_test()
	{
		TestInit();
		currentStateMain = CATEGORY_SELECTION;
		bool result = true;
		uint16_t* it_source = allCategories[State_CategoryNumber].name;
		for(uint16_t* it = u"Geography"; (*it)!=0x0; it++)
		{
			result = result && (*it==*it_source);
			it_source++;
		}
		return result;
	}

	bool go_to_answer_test()
	{
		bool result = true;
		TestInit();
		currentStateMain = CATEGORY_SELECTION;
		ClickedSelect();
		ClickedSelect();
		uint16_t* it_source = allCategories[State_CategoryNumber].flashcard[State_FlashCardNumber].answer.string;
		for(uint16_t* it = u"Mount Vinson is located in Antarctica"; (*it)!=0x0; it++)
		{
			result = result && (*it==*it_source);
			it_source++;
		}
		return result;
	}

	void DisplayTestIfFailed(bool (*FunctionToCall)(), const uint16_t* TextToDisplay)
	{
		if(FunctionToCall()==false)
		{
			BACK_COLOR = 0xF800;
			isCorrect = false;
			DisplayString(TextToDisplay);
		}
	}

	void DisplayTestIfOK()
	{
		if(isCorrect==true)
		{
			BACK_COLOR = 0x07E0;
			DisplayString(u"Every test passed!");
		}
	}


	int main()
	{
		HAL_Init();
		SystemClock_Config();
		MX_GPIO_Init();
		//MX_USART2_UART_Init();

		BACK_COLOR = 0x8430;
		POINT_COLOR = 0x0000;
		Lcd_Init();
		LCD_Clear(BACK_COLOR);

		isCorrect = true;

		do{

		TEST_RUN(len_str_test);
		TEST_RUN(len_wstr_test);
		TEST_RUN(copy_wstr_test);
		TEST_RUN(copy_wstr_to_str_test);
		TEST_RUN(application_start_test);
		TEST_RUN(go_to_answer_test);

		}while(!isCorrect);

		DisplayTestIfOK();

	}
#endif
