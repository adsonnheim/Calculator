#include <iostream>
#include <limits>
using namespace std;

bool isOperator(string input) {
    if (input == "+" || input == "-") {
        return true;
    }
    return false;
}

int main() {
    cout << "Hello, and welcome to my calculator program!" << endl;
    cout << "This program supports the following operations:" << endl;
    cout << "" << endl;
    cout << "To exit the program at any time, enter 'exit'." << endl;
    
    float value = 0.0;
    
    string input;
    double nextNum;
    
    while (input != "exit") {
        cout << "To exit the program at any time, enter 'exit'." << endl;
        cout << "Please enter a number or an operator." << endl;
        cout << "Current value : " << value << endl;
        cin >> input;
        if (isOperator(input)) {
            cout << value << " " << input << " ";
            while (!(cin >> nextNum)) {
                cout << "Invalid input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
            }
            if (input == "+") { 
                value = value + nextNum;
            } else if (input == "-") {
                value = value - nextNum;
            }
        }
    }

    return 0;
}