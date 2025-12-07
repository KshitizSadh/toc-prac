#include <iostream>
#include <string>
using namespace std;

bool acceptsEvenEven(const string& str) {
    int state = 0; // 0: even a, even b; 1: odd a, even b; 2: even a, odd b; 3: odd a, odd b
    for (char c : str) {
        if (c == 'a') {
            if (state == 0) state = 1;
            else if (state == 1) state = 0;
            else if (state == 2) state = 3;
            else state = 2;
        } else if (c == 'b') {
            if (state == 0) state = 2;
            else if (state == 1) state = 3;
            else if (state == 2) state = 0;
            else state = 1;
        }
    }
    return state == 0;
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;
    cout << (acceptsEvenEven(input) ? "Accepted" : "Rejected") << endl;
    return 0;
}
