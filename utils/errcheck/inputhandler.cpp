#include "inputhandler.hpp"

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidatedInteger(int minValue, int maxValue) {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail() || value < minValue || value > maxValue) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between " 
                 << minValue << " and " << maxValue << ": ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int getIntegerInput(const string& message) {
    int value;
    while (true) {
        cout << message;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid integer: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

double getDoubleInput(const string& message) {
    double value;
    while (true) {
        cout << message;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

char getOperationInput() {
    char op;
    while (true) {
        cout << "Enter operation (+, -, *, /): ";
        cin >> op;
        if (op == '+' || op == '-' || op == '*' || op == '/') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return op;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid operation! Please enter +, -, *, or /" << endl;
        }
    }
}

char getComplexInputType() {
    char type;
    while (true) {
        cout << "Enter complex number as (r)ectangular or (p)olar? (r/p): ";
        cin >> type;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (type == 'r' || type == 'R' || type == 'p' || type == 'P') {
            return tolower(type);
        }
        cout << "Invalid input! Please enter 'r' for rectangular or 'p' for polar." << endl;
    }
}

bool confirmAction(const string& message) {
    string input;
    while (true) {
        cout << message << " (y/n): ";
        getline(cin, input);
        
        if (input.length() == 1) {
            char choice = input[0];
            if (choice == 'y' || choice == 'Y') {
                return true;
            } else if (choice == 'n' || choice == 'N') {
                return false;
            }
        }
        cout << "Invalid input! Please enter 'y' for yes or 'n' for no." << endl;
    }
}