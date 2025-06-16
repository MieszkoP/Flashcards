/*
 * displays.c
 *
 *  Created on: Mar 18, 2025
 *      Author: mieszko
 */
#include "displays.h"
#include "stddef.h"
#include "LCD.h"
#include "creators.h"
void DisplayString(const uint16_t* string)
{
	//We must convert w_char_t to char. Currently wide char is not supported.
	uint8_t dest[500] = {0};
	LCD_Clear_size(BACK_COLOR, 5,5, size_of_prev_string*8);
	size_of_prev_string = len_wstr(string);
	copy_wstr_to_str(dest, string);
	LCD_ShowString(5,5,dest);
}

void DisplayPicture(const char** picture)
{

}
