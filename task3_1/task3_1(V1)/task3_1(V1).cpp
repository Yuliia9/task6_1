/*
* @file			task3_1.cpp
* @brief		Program finds the longest word in inputed sentences and shows it

* Copyright 2014 by Yuliia Lyubchik Inc.,
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*
*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "task3_1h.h"  /*defines prototypes of used in this file functions*/
#include <windows.h>

void Interface(void)
{
	printf("------------------------------------------------------------------\n");
	printf("Hi! Welcome to the genius word finder.\n ");
	printf(" Enter sentences and program will find for you the longest word.\n\n ");
	printf("Program made by Yuliia Lyubchik.\n");
	printf("------------------------------------------------------------------\n\n");
}


int main()
{
	Interface();
#ifdef USE_MY_DLL
	if (Check_Loading_Library() == FAIL)
	{
		puts("Can't load library.");
		return (int)FAIL;
	}
#endif

	char* riadok = NULL;
	unsigned char retCode;
	char* word = NULL;
	unsigned int max_len = 0;
	
	retCode = Input(&riadok);

	if (retCode == FAIL)
	{
		puts("Error occurs while trying to input string.\n");
		free(riadok);
		return (int) FAIL;
	}

	puts("The first longest word is: ");
	max_len = Get_longest_word(riadok, &word);
	if (max_len == (int) FAIL)
	{
		puts("Error occurs while trying to estimate the longest word. \n");
		free(riadok);
		return (int) FAIL;
	}

	free(riadok);
	system("pause");
	return MAIN_SUCCESS;
}


