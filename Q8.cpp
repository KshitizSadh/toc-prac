// PDA for {wXw^r | w ∈ {a,b}*, X is middle marker}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool acceptsPalindromeWithX(const string& str) {
    stack<char> pda;
    int state = 0; // 0: push phase, 1: pop phase
    
    for (char c : str) {
        if (state == 0) {
            if (c == 'X') {
                state = 1; // Switch to matching phase
            } else if (c == 'a' || c == 'b') {
                pda.push(c);
            } else {
                return false;
            }
        } else if (state == 1) {
            if (c == 'a' || c == 'b') {
                if (pda.empty() || pda.top() != c) {
                    return false;
                }
                pda.pop();
            } else {
                return false;
            }
        }
    }
    
    return state == 1 && pda.empty();
}

int main() {
    string input;
    cout << "Enter string (wXw^r format): ";
    cin >> input;
    cout << (acceptsPalindromeWithX(input) ? "Accepted" : "Rejected") << endl;
    
    // Test cases
    cout << "\nTest Cases:" << endl;
    cout << "aXa: " << (acceptsPalindromeWithX("aXa") ? "Accepted" : "Rejected") << endl;
    cout << "abXba: " << (acceptsPalindromeWithX("abXba") ? "Accepted" : "Rejected") << endl;
    cout << "abaXaba: " << (acceptsPalindromeWithX("abaXaba") ? "Accepted" : "Rejected") << endl;
    cout << "abXab: " << (acceptsPalindromeWithX("abXab") ? "Accepted" : "Rejected") << endl;
    cout << "X: " << (acceptsPalindromeWithX("X") ? "Accepted" : "Rejected") << endl;
    
    return 0;
}
