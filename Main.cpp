#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

bool isOperator(string input) {
    if (input == "+" || input == "-" || input == "*" || input == "/") {
        return true;
    }
    return false;
}

bool isNumber(const string &str) {
    auto result = double();
    auto i = istringstream(str);

    i >> result;

    return !i.fail() && i.eof();
}

// TODO: Add capabilities to start with a number
//       Add ability to reset the number to zero
//       Store the history of all operations done in a session
//       Add ability to use operations with different bases

int main() {
    cout << "Hello, and welcome to my calculator program!" << endl;
    cout << "This program supports the following operations:" << endl;
    cout << "+, -" << endl;
    
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
            } else if (input == "*") {
                value = value * nextNum;
            } else if (input == "/") {
                while (nextNum == 0) {
                    cout << "Invalid input! Cannot divide by zero!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<int>::max(), '\n');
                    cout << value << " " << input << " ";
                    cin >> nextNum;
                }
                value = value / nextNum;
            }
        } else if (isNumber(input)) {
            cout << "That is a number!" << endl;
        }
    }

    return 0;
}