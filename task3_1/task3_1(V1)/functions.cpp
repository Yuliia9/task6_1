/*
*@file		functions.cpp
*@brief		implements functions used in file task3_1.cpp
			uses developed dll and lib library for working with C string
*/
#include "stdafx.h"
#include "task3_1h.h"
#include <stdio.h>
#include <stdlib.h>


typedef int(*STRLEN_PRINT) (const char*);
typedef char* (*STRTOK) (char*, const char*);


#ifdef USE_STRING_H
#include <string.h>
#define STREND '\0'
STRLEN_PRINT mystrlen = (STRLEN_PRINT)strlen;
STRLEN_PRINT myprintf = puts;
STRTOK mystrtok = (STRTOK)strtok;


#elif defined (USE_MY_LIB)
#include "my_string.h"
STRLEN_PRINT mystrlen = (STRLEN_PRINT) my_strlen;
STRLEN_PRINT myprintf = (STRLEN_PRINT)my_strprintf;
STRTOK mystrtok = my_strtok;


#elif defined (USE_MY_DLL) 
#include <windows.h> 
HINSTANCE stringdll = LoadLibrary(TEXT("stringdll.dll"));
char* end = (char*) GetProcAddress(stringdll, LPCSTR("STREND"));
const char STREND = *end;
STRLEN_PRINT mystrlen = (STRLEN_PRINT)GetProcAddress(stringdll, LPCSTR("my_strlen"));
STRLEN_PRINT myprintf = (STRLEN_PRINT)GetProcAddress(stringdll, LPCSTR("my_strprintf"));
STRTOK mystrtok = (STRTOK)GetProcAddress(stringdll, LPCSTR("my_strtok"));
#endif

unsigned int Check_Loading_Library(void)
{
	if (stringdll == NULL)
	{
		return FAIL;
	}
	else if (end == NULL || mystrlen == NULL || myprintf == NULL || mystrtok == NULL)
	{
		return FAIL;
	}
}


unsigned char Input(char** riad)
{
	char temp;
	int count = 0;
	do
	{
		printf("Please enter sentence: ");
		do
		{
			scanf("%c", &temp);
			++count;
			*riad = (char*)realloc(*riad, count * sizeof(char));
			if (*riad != NULL) {

				*(*riad + count - 1) = temp;
			}
			else
			{
				free(riad);
				puts("Error (re)allocating memory. \n");
				return FAIL;
			}
		}
		while (temp != '\n' && temp != EOF);
		*(*riad + count - 1) = STREND;
	} 
	while (riad == NULL || mystrlen(*riad) == 0);

	return SUCCESS;
}



unsigned int Get_longest_word(char* riadok, char** word)
{
	if (riadok == NULL)
	{
		puts("Error, can't get access to string. \n");
		return (int) FAIL;
	}

	char* temp;
	unsigned int len, maxl = 0;
	char delimiters[] = { ' ', ',', '-', '.', ':', ';', '(', ')', '[', ']', '!', '?', STREND};

	temp = mystrtok(riadok, delimiters);
	while (temp != NULL)
	{
		len = mystrlen(temp);
		if (len > maxl)
		{
			*word = temp;
			maxl = len;
		}
		temp = mystrtok(NULL, delimiters);
	}
	myprintf(*word);
	puts("\n");
#ifdef USE_MY_DLL
	FreeLibrary(stringdll);
#endif
	return maxl;
}

