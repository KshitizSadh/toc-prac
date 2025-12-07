#include <iostream>
#include <string>
using namespace std;

bool acceptsFirstTwoEqualsLastTwo(const string& str) {
    if (str.length() < 4) return false;
    return str.substr(0, 2) == str.substr(str.length() - 2, 2);
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;
    cout << (acceptsFirstTwoEqualsLastTwo(input) ? "Accepted" : "Rejected") << endl;
    return 0;
}
