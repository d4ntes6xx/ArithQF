#ifndef LAUNCHER_HPP
#define LAUNCHER_HPP

#include <string>

void displayMainMenu();
void displayProjectMenu();
void showVersionInfo();
void runLauncher();
bool compileProject(const std::string& projectPath, const std::string& projectName);
bool fileExists(const std::string& filename);


#endif