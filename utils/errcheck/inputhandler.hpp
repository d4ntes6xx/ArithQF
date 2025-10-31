#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <iostream>
#include <limits>
#include <string>

using namespace std;

void clearInputBuffer();
int getValidatedInteger(int minValue, int maxValue);
int getIntegerInput(const string& message);
double getDoubleInput(const string& message);
char getOperationInput();
char getComplexInputType();
bool confirmAction(const string& message);

#endif