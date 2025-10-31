#include "consolectl.hpp"

#include <cstdlib>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#endif

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause(int seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}

void waitForAnyKey() {
    std::cout << "Press any key to continue..." << std::endl;
    
    #ifdef _WIN32
        int key;
        do {
            key = _getch(); 
        } while (key != 27 && key != 32 && key != 13);

        if (key == 13) return;      
        else if (key == 32) return;
        else if (key == 27) return;
    #else
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        
        int key;
        do {
            key = getchar();
        } while (key != 27 && key != 32 && key != 10);
        
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        if (key == 13) return;      
        else if (key == 32) return;
        else if (key == 27) return;
    #endif
}