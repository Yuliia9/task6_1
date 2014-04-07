/*
*@file		task3_1.h
*@brief		header file that defines prototypes of functions used in file task3_1.cpp
*/

#ifndef TASK3_1_H_
#define TASK3_1_H_

#include "stdafx.h"
const unsigned char FAIL = 0;
const unsigned char SUCCESS = 1;
const unsigned int MAIN_SUCCESS = 0;

/*for choosing what library to use*/
//#define USE_STRING_H
#define USE_MY_LIB
//#define USE_MY_DLL

/**
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface(void);

/**
* @brief				This function checks if string dll library was loaded
* @param	void
* @return	void
*/
unsigned int Check_Loading_Library(void);


/**
* @brief					Function for inputing string
* @param	[in/out]		char** riadok - a pointer to null pointer to string for sentences
*						
*@return	unsigned char	Return ERROR if error occurs while trying to allocate memory for string
							Return SUCCESS if string was inputed
*/
unsigned char Input(char** riad);



/**
* @brief				Function finds the longest word in sequence of sentences
* @param	[in]		char* riadok - a pointer to inputed sequence of sentences
			[in/out]	char** word - a pointer to pointer to longest word in sentences
*						
*/
unsigned int Get_longest_word(char* riadok, char** word);


#endif

