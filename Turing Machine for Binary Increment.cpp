#include <iostream>
#include <string>
using namespace std;

string turingMachineBinaryIncrement(string tape) {
    if (tape.empty()) return "1";
    
    int head = tape.length() - 1; // Start from rightmost digit
    
    // Handle carry propagation
    while (head >= 0) {
        if (tape[head] == '0') {
            tape[head] = '1'; // Change 0 to 1, done
            return tape;
        } else if (tape[head] == '1') {
            tape[head] = '0'; // Change 1 to 0, continue carry
            head--;
        } else {
            return "Error: Invalid binary digit";
        }
    }
    
    // If we exit loop, all digits were 1, need extra bit
    return "1" + tape;
}

int main() {
    string input;
    cout << "Enter binary number: ";
    cin >> input;
    
    string result = turingMachineBinaryIncrement(input);
    cout << "Result after increment: " << result << endl;
    
    // Test cases
    cout << "\nTest Cases:" << endl;
    cout << "0 -> " << turingMachineBinaryIncrement("0") << endl;
    cout << "1 -> " << turingMachineBinaryIncrement("1") << endl;
    cout << "10 -> " << turingMachineBinaryIncrement("10") << endl;
    cout << "0111 -> " << turingMachineBinaryIncrement("0111") << endl;
    cout << "1111 -> " << turingMachineBinaryIncrement("1111") << endl;
    cout << "10000 -> " << turingMachineBinaryIncrement("10000") << endl;
    cout << "101010 -> " << turingMachineBinaryIncrement("101010") << endl;
    
    return 0;
}
