#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>
#include <array>
#include <cstdio>
#include "launcher.hpp"
#include "utils/infacdisp/consolectl.hpp"
#include "utils/errcheck/inputhandler.hpp"

using namespace std;

void displayMainMenu() {
    clearScreen();
    cout << "=== MAIN LAUNCHER ===" << endl;
    cout << "1. Fraction Calculator" << endl;
    cout << "2. Complex Number Calculator" << endl;
    cout << "3. Project Information" << endl;
    cout << "4. Version Information" << endl;
    cout << "5. Exit" << endl;
    cout << "=====================" << endl;
    cout << endl;
    cout << "Choose your option: ";
}

void displayProjectInfo() {
    clearScreen();
    cout << "=== PROJECT INFORMATION ===" << endl;
    cout << "Fraction Calculator:" << endl;
    cout << "- Operations: +, -, *, / with fractions" << endl;
    cout << "- Input: numerator/denominator" << endl;
    cout << "- Features: auto-reduction, comparison" << endl;
    cout << endl;
    cout << "Complex Number Calculator:" << endl;
    cout << "- Operations: +, -, *, / with complex numbers" << endl;
    cout << "- Input: rectangular (a+bi) or polar form" << endl;
    cout << "- Features: magnitude, conjugate" << endl;
    pause(5);
    cout << endl;
    waitForAnyKey();
}

void showVersionInfo() {
    clearScreen();
    cout << "==============" << endl;
    cout << "Version: 1.0.0" << endl;
    cout << "Created: 2025" << endl;
    cout << "   M a d e" << endl;
    cout << "     b y" << endl;
    cout << "  d4ntes6xx" << endl;
    cout <<  endl;
    cout << "  (c)  2025" << endl;
    cout << "==============" << endl;
    pause(5);
    cout << endl;
    waitForAnyKey();
}

bool fileExists(const string& filename) {
    return filesystem::exists(filename);
}

bool compileProject(const string& projectPath, const string& projectName) {
    cout << "Compiling " << projectName << "..." << endl;
    
    string compileCmd;
    
#ifdef _WIN32
    compileCmd = "cd " + projectPath + " && g++ *.cpp ../utils/errcheck/inputhandler.cpp ../utils/infacdisp/consolectl.cpp -I.. -I../utils -o main.exe 2>&1";
#else
    compileCmd = "cd " + projectPath + " && g++ *.cpp ../utils/errcheck/inputhandler.cpp ../utils/infacdisp/consolectl.cpp -I.. -I../utils -o main 2>&1";
#endif

    cout << "Running: " << compileCmd << endl;

    int compileResult = system(compileCmd.c_str());
    
#ifdef _WIN32
    string executable = projectPath + "/main.exe";
#else
    string executable = projectPath + "/main";
#endif
    if (fileExists(executable)) {
        cout << "Compilation successful!" << endl;
        return true;
    } else {
        cout << "Compilation failed! Error code: " << compileResult << endl;
        cout << "Running diagnostic..." << endl;
#ifdef _WIN32
        system(("cd " + projectPath + " && dir *.cpp").c_str());
        system("dir utils\\errcheck\\*.cpp");
        system("dir utils\\infacdisp\\*.cpp");
#else
        system(("ls -la " + projectPath + "/*.cpp").c_str());
        system("ls -la utils/errcheck/*.cpp");
        system("ls -la utils/infacdisp/*.cpp");
#endif
        return false;
    }
}

void runLauncher() {
    while (true) {
        displayMainMenu();
        int choice = getValidatedInteger(1, 5);
        
        switch (choice) {
            case 1: {
                string projectPath = "task1";
                string executable;
                
                #ifdef _WIN32
                    executable = projectPath + "\\main.exe";
                #else
                    executable = projectPath + "/main";
                #endif

                cout << "Launching Fraction Calculator..." << endl;
                pause(2);
                
                int result;
                
                #ifdef _WIN32
                    result = system(executable.c_str());
                #else
                    result = system(("./" + executable).c_str());
                #endif

                if (result != 0) {
                    cout << "Executable not found or error. Trying to compile..." << endl;
                    if (compileProject(projectPath, "Fraction Calculator")) {
                        cout << "Launching Fraction Calculator..." << endl;
                        pause(2);
                        
                        #ifdef _WIN32  
                            system(executable.c_str());
                        #else
                            system(("./" + executable).c_str());
                        #endif
                    } else {
                        cout << "Failed to compile and run Fraction Calculator!" << endl;
                        pause(3);
                    }
                }
                break;
            }
            
            case 2: {
                string projectPath = "task2";
                string executable;
                
                #ifdef _WIN32
                    executable = projectPath + "\\main.exe";
                #else
                    executable = projectPath + "/main";
                #endif

                cout << "Launching Complex Number Calculator..." << endl;
                pause(2);
                
                int result;

                #ifdef _WIN32
                    result = system(executable.c_str());
                #else
                    result = system(("./" + executable).c_str());
                #endif

                if (result != 0) {
                    cout << "Executable not found or error. Trying to compile..." << endl;
                    if (compileProject(projectPath, "Complex Number Calculator")) {
                        cout << "Launching Complex Number Calculator..." << endl;
                        pause(2);
                        
                        #ifdef _WIN32
                            system(executable.c_str());
                        #else
                            system(("./" + executable).c_str());
                        #endif
                    } else {
                        cout << "Failed to compile and run Complex Number Calculator!" << endl;
                        pause(3);
                    }
                }
                break;
            }
            
            case 3: {
                displayProjectInfo();
                break;
            }

            case 4: {
                showVersionInfo();
                break;
            }

            case 5:
                cout << "\nGoodbye!" << endl;
                pause(3);
                clearScreen();
                return;
        }
    }
}