/*
 * testinit.c
 *
 *  Created on: Mar 18, 2025
 *      Author: mieszko
 */
//File used for trial initialization of structures
#include <creators.h>

void print(const char* data, UART_HandleTypeDef* wsk_huart)
{
	HAL_UART_Transmit(wsk_huart, (const uint8_t *)data, len_str(data)+1, HAL_MAX_DELAY);
}

unsigned int len_str(const char* source)
{
	unsigned int len = 0;
	const char* it = source;
	while(*it>4)
	{
		it++;
		len++;
	}
	return len;
}

unsigned int len_wstr(const uint16_t* source)
{
	unsigned int len = 0;
	const uint16_t* it = source;
	if(it==NULL)
		return 0;
	while(*it>4)
	{
		it++;
		len++;
	}
	return len;
}

void copy_wstr(uint16_t* const dest, const uint16_t* const source)
{
	const uint16_t* it = source;
	uint16_t* it_dest = dest;
	while(it!=0 && *it>4)
	{
		*it_dest = *it;
		it++;
		it_dest++;
	}
	*it_dest = 0;
}


void copy_wstr_to_str(uint8_t* const dest, const uint16_t* const source)
{
	const uint16_t* it = source;
	uint8_t* it_dest = dest;
	while(it!=0 && *it>4)
	{
		*it_dest = (uint8_t)*it;
		it++;
		it_dest++;
	}
	*it_dest = 0;
}

FlashCard CreateFlashcard(const uint16_t* question_data, const uint16_t* answer_data)
{
	Question question;
	Answer answer;
	answer.string = u"";
	question.data = u"";

	answer.string = (uint16_t*)calloc(len_wstr(answer_data)+1, sizeof(uint16_t));
	question.data = (uint16_t*)calloc(len_wstr(question_data)+1, sizeof(uint16_t));

	copy_wstr(answer.string, answer_data);
	copy_wstr(question.data, question_data);
	FlashCard flashcard;
	flashcard.answer = answer;
	flashcard.question = question;

	return flashcard;
}

void TestInit()
{
	FlashCard f1 = CreateFlashcard(u"Where is Mount Vinson located?", u"Mount Vinson is located in Antarctica");
	FlashCard f2 = CreateFlashcard(u"Which is the largest landlocked country?", u"Kazakhstan");
	FlashCard f3 = CreateFlashcard(u"What is the longest mountain range in the world??", u"The Andes");
	Category Geog;
	Geog.name = u"Geography";
	Geog.flashcard = (FlashCard*)calloc(3,sizeof(FlashCard));
	Geog.flashcard[0] = f1;
	Geog.flashcard[1] = f2;
	Geog.flashcard[2] = f3;
	Geog.numberOfFlashCards = 3;

	FlashCard f4 = CreateFlashcard(u"first emperor of China?", u"Qin Shi Huang");
	FlashCard f5 = CreateFlashcard(u"When did the Roman Empire officially fall?", u"476 AD");
	FlashCard f6 = CreateFlashcard(u"In which year did the Titanic sink?", u"The Titanic sank in 1912.");
	Category Hist;
	Hist.name = u"History";
	Hist.flashcard = (FlashCard*)calloc(3,sizeof(FlashCard));
	Hist.flashcard[0] = f4;
	Hist.flashcard[1] = f5;
	Hist.flashcard[2] = f6;
	Hist.numberOfFlashCards = 3;

	FlashCard f7 = CreateFlashcard(u"What is a real-time operating system (RTOS)?", u"An RTOS manages hardware and software resources to meet real-time application requirements");
	FlashCard f8 = CreateFlashcard(u"What is the difference between EEPROM and flash memory in firmware?", u"EEPROM can be written byte-by-byte, while flash memory is written in larger blocks.");
	FlashCard f9 = CreateFlashcard(u"What is a watchdog timer in firmware?", u"A watchdog timer resets the system if the firmware fails to respond within a timeout.");
	Category Prog;
	Prog.name = u"Firmware Programming";
	Prog.flashcard = (FlashCard*)calloc(3,sizeof(FlashCard));
	Prog.flashcard[0] = f7;
	Prog.flashcard[1] = f8;
	Prog.flashcard[2] = f9;
	Prog.numberOfFlashCards = 3;

	numberOfCategories=3;
	InitializedByTestInit = true;

	allCategories = (Category*)calloc(3,sizeof(Category));
	allCategories[0] = Geog;
	allCategories[1] = Hist;
	allCategories[2] = Prog;
}
