#include <iostream>
#include <vector>
#include "fraction.hpp"
#include "utils/infacdisp/consolectl.hpp"
#include "utils/errcheck/inputhandler.hpp"

using namespace std;

void displayMenu() {
    clearScreen();
    cout << "=== FRACTION CALCULATOR ===" << endl;
    cout << "1. Calculate with fractions" << endl;
    cout << "2. Compare fractions" << endl;
    cout << "3. Convert fraction to decimal" << endl;
    cout << "4. Exit" << endl;
    cout << "============================" << endl;
    cout << endl;
    cout << "Choose your option: ";
}

Fraction inputFraction(int fractionNumber) {
    cout << "\n--- Enter Fraction " << fractionNumber << " ---" << endl;
    int numerator = getIntegerInput("Enter numerator: ");
    int denominator;
    
    while (true) {
        denominator = getIntegerInput("Enter denominator: ");
        if (denominator != 0) {
            break;
        }
        cout << "Denominator cannot be zero! Please try again." << endl;
    }
    
    return Fraction(numerator, denominator);
}

void performOperations() {
    int numFractions;
    while (true) {
        numFractions = getIntegerInput("How many fractions do you want to use? (2 or more): ");
        if (numFractions >= 2) {
            break;
        }
        cout << "Please enter at least 2 fractions!" << endl;
    }
    
    vector<Fraction> fractions;
    vector<char> operations;
    
    for (int i = 0; i < numFractions; i++) {
        fractions.push_back(inputFraction(i + 1));
        
        if (i < numFractions - 1) {
            operations.push_back(getOperationInput());
        }
    }
    
    Fraction result = fractions[0];
    cout << "\nCalculation: " << result;
    
    for (size_t i = 0; i < operations.size(); i++) {
        cout << " " << operations[i] << " " << fractions[i + 1];
        
        try {
            switch (operations[i]) {
                case '+': result = result + fractions[i + 1]; break;
                case '-': result = result - fractions[i + 1]; break;
                case '*': result = result * fractions[i + 1]; break;
                case '/': result = result / fractions[i + 1]; break;
            }
        } catch (const std::exception& e) {
            cout << "\nError during calculation: " << e.what() << endl;
            pause(3);
            return;
        }
    }
    
    cout << " = " << result << endl;
    cout << "Decimal value: " << static_cast<double>(result) << endl;
    
    pause(3);
}

void compareFractions() {
    clearScreen();
    cout << "=== COMPARE FRACTIONS ===" << endl;
    
    Fraction f1 = inputFraction(1);
    Fraction f2 = inputFraction(2);
    
    cout << "\nComparison results:" << endl;
    cout << f1 << " == " << f2 << " : " << (f1 == f2 ? "true" : "false") << endl;
    cout << f1 << " != " << f2 << " : " << (f1 != f2 ? "true" : "false") << endl;
    cout << f1 << " <  " << f2 << " : " << (f1 < f2 ? "true" : "false") << endl;
    cout << f1 << " >  " << f2 << " : " << (f1 > f2 ? "true" : "false") << endl;
    cout << f1 << " <= " << f2 << " : " << (f1 <= f2 ? "true" : "false") << endl;
    cout << f1 << " >= " << f2 << " : " << (f1 >= f2 ? "true" : "false") << endl;
    
    pause(3);
}

void convertToDecimal() {
    clearScreen();
    cout << "=== CONVERT FRACTION TO DECIMAL ===" << endl;
    
    Fraction f = inputFraction(1);
    cout << "\nFraction: " << f << endl;
    cout << "Decimal: " << static_cast<double>(f) << endl;
    
    pause(3);
}

int main() {
    while (true) {
        displayMenu();
        int choice = getValidatedInteger(1, 4);
        
        switch (choice) {
            case 1:
                performOperations();
                break;
            case 2:
                compareFractions();
                break;
            case 3:
                convertToDecimal();
                break;
            case 4:
                if (confirmAction("Are you sure you want to exit?")) {
                    cout << "Goodbye!" << endl;
                    pause(3);
                    clearScreen();
                    return 0;
                }
                break;
        }
    }
    
    return 0;
}