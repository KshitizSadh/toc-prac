//PDA for {a^n b^n | n > 0}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool acceptsAnBn(const string& str) {
    if (str.empty()) return false;
    
    stack<char> pda;
    int state = 0; // 0: initial, 1: reading a's, 2: reading b's, 3: accept
    
    for (char c : str) {
        if (state == 0 || state == 1) {
            if (c == 'a') {
                pda.push('a');
                state = 1;
            } else if (c == 'b' && !pda.empty()) {
                pda.pop();
                state = 2;
            } else {
                return false;
            }
        } else if (state == 2) {
            if (c == 'b' && !pda.empty()) {
                pda.pop();
            } else {
                return false;
            }
        }
    }
    
    return state == 2 && pda.empty();
}

int main() {
    string input;
    cout << "Enter string (a^n b^n): ";
    cin >> input;
    cout << (acceptsAnBn(input) ? "Accepted" : "Rejected") << endl;
    
    // Test cases
    cout << "\nTest Cases:" << endl;
    cout << "ab: " << (acceptsAnBn("ab") ? "Accepted" : "Rejected") << endl;
    cout << "aabb: " << (acceptsAnBn("aabb") ? "Accepted" : "Rejected") << endl;
    cout << "aaabbb: " << (acceptsAnBn("aaabbb") ? "Accepted" : "Rejected") << endl;
    cout << "aab: " << (acceptsAnBn("aab") ? "Accepted" : "Rejected") << endl;
    
    return 0;
}
