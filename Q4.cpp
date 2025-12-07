//Language a(a+b)*b
#include <iostream>
#include <string>
using namespace std;

bool acceptsAStartBEnd(const string& str) {
    if (str.length() < 2) return false;
    int state = 0;
    for (char c : str) {
        if (state == 0) state = (c == 'a') ? 1 : -1;
        else if (state == 1) state = (c == 'a' || c == 'b') ? 1 : -1;
        else state = -1;
    }
    return state == 1 && str.back() == 'b';
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;
    cout << (acceptsAStartBEnd(input) ? "Accepted" : "Rejected") << endl;
    return 0;
}
