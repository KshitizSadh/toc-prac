#include <iostream>
#include <string>
using namespace std;

bool acceptsThreeConsecutiveOnes(const string& str) {
    int state = 0;
    for (char c : str) {
        if (state == 0) state = (c == '1') ? 1 : 0;
        else if (state == 1) state = (c == '1') ? 2 : 0;
        else if (state == 2) state = (c == '1') ? 3 : 0;
        else if (state == 3) state = 3; // accepting state
    }
    return state == 3;
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;
    cout << (acceptsThreeConsecutiveOnes(input) ? "Accepted" : "Rejected") << endl;
    return 0;
}
