#include <iostream>
#include <vector>
#include <cmath>
#include "complex.hpp"
#include "utils/infacdisp/consolectl.hpp"
#include "utils/errcheck/inputhandler.hpp"

using namespace std;

void displayMenu() {
    clearScreen();
    cout << "=== COMPLEX NUMBER CALCULATOR ===" << endl;
    cout << "1. Calculate with complex numbers" << endl;
    cout << "2. Compare complex numbers" << endl;
    cout << "3. Additional operations" << endl;
    cout << "4. Exit" << endl;
    cout << "==================================" << endl;
    cout << endl;
    cout << "Choose your option: ";
}

Complex inputComplex(int number) {
    cout << "\n--- Enter Complex Number " << number << " ---" << endl;
    
    char type = getComplexInputType();
    
    if (type == 'r') {
        double real = getDoubleInput("Enter real part: ");
        double imaginary = getDoubleInput("Enter imaginary part: ");
        return Complex(real, imaginary);
    } else {
        double magnitude = getDoubleInput("Enter magnitude: ");
        double angle = getDoubleInput("Enter angle in radians: ");
        double real = magnitude * cos(angle);
        double imaginary = magnitude * sin(angle);
        return Complex(real, imaginary);
    }
}

void performOperations() {
    int numComplex;
    while (true) {
        numComplex = getIntegerInput("How many complex numbers do you want to use? (2 or more): ");
        if (numComplex >= 2) {
            break;
        }
        cout << "Please enter at least 2 complex numbers!" << endl;
    }
    
    vector<Complex> numbers;
    vector<char> operations;
    
    for (int i = 0; i < numComplex; i++) {
        numbers.push_back(inputComplex(i + 1));
        
        if (i < numComplex - 1) {
            operations.push_back(getOperationInput());
        }
    }
    
    Complex result = numbers[0];
    cout << "\nCalculation: " << result;
    
    for (size_t i = 0; i < operations.size(); i++) {
        cout << " " << operations[i] << " " << numbers[i + 1];
        
        try {
            switch (operations[i]) {
                case '+': result = result + numbers[i + 1]; break;
                case '-': result = result - numbers[i + 1]; break;
                case '*': result = result * numbers[i + 1]; break;
                case '/': result = result / numbers[i + 1]; break;
            }
        } catch (const std::exception& e) {
            cout << "\nError during calculation: " << e.what() << endl;
            pause(3);
            return;
        }
    }
    
    cout << " = " << result << endl;
    cout << "Magnitude: " << result.magnitude() << endl;
    
    pause(3);
}

void compareNumbers() {
    clearScreen();
    cout << "=== COMPARE COMPLEX NUMBERS ===" << endl;
    
    Complex c1 = inputComplex(1);
    Complex c2 = inputComplex(2);
    
    cout << "\nComparison results:" << endl;
    cout << c1 << " == " << c2 << " : " << (c1 == c2 ? "true" : "false") << endl;
    cout << c1 << " != " << c2 << " : " << (c1 != c2 ? "true" : "false") << endl;
    
    pause(3);
}

void additionalOperations() {
    clearScreen();
    cout << "=== ADDITIONAL OPERATIONS ===" << endl;
    
    Complex c = inputComplex(1);
    
    cout << "\nNumber: " << c << endl;
    cout << "Conjugate: " << c.conjugate() << endl;
    cout << "Magnitude: " << c.magnitude() << endl;
    cout << "Negation: " << -c << endl;
    
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
                compareNumbers();
                break;
            case 3:
                additionalOperations();
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