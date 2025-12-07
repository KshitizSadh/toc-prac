#include <iostream>
#include <string>
using namespace std;

bool L1(const string& s) {
    return s.length() >= 4 && s.substr(0, 2) == s.substr(s.length() - 2, 2);
}

bool L2(const string& s) {
    return s.length() >= 2 && s[0] == 'a' && s.back() == 'b';
}

bool unionFA(const string& s) { return L1(s) || L2(s); }
bool intersectionFA(const string& s) { return L1(s) && L2(s); }

bool concatenationFA(const string& s) {
    for (size_t i = 0; i <= s.length(); i++) {
        if (L1(s.substr(0, i)) && L2(s.substr(i))) return true;
    }
    return false;
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;
    cout << "Union: " << (unionFA(input) ? "Accepted" : "Rejected") << endl;
    cout << "Intersection: " << (intersectionFA(input) ? "Accepted" : "Rejected") << endl;
    cout << "Concatenation: " << (concatenationFA(input) ? "Accepted" : "Rejected") << endl;
    return 0;
}
