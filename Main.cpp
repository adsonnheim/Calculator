#include <iostream>
using namespace std;

int main() {
    cout << "Hello, and welcome to my calculator program!" << endl;
    cout << "This program supports the following operations:" << endl;
    cout << "" << endl;
    cout << "To exit the program at any time, enter 'exit'." << endl;
    
    float value = 0.0;

    cout << "Current value : " << value << endl;
    
    string input;
    cin >> input;
    
    while (input != "exit") {
        cout << "Current value : " << value << endl;
        cin >> input;
    }

    return 0;
}