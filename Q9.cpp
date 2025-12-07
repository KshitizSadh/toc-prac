//Turing Machine for {a^n b^n c^n | n > 0}
#include <iostream>
#include <string>
using namespace std;

bool turingMachineAnBnCn(string tape) {
    if (tape.empty()) return false;
    
    int head = 0;
    
    while (true) {
        // Move to first unmarked 'a'
        head = 0;
        while (head < tape.length() && tape[head] == 'X') head++;
        
        if (head >= tape.length()) return false;
        if (tape[head] != 'a') break; // All a's marked, check completion
        
        tape[head] = 'X'; // Mark 'a'
        
        // Move to first unmarked 'b'
        while (head < tape.length() && (tape[head] == 'X' || tape[head] == 'Y')) head++;
        
        if (head >= tape.length() || tape[head] != 'b') return false;
        tape[head] = 'Y'; // Mark 'b'
        
        // Move to first unmarked 'c'
        while (head < tape.length() && (tape[head] == 'Y' || tape[head] == 'Z')) head++;
        
        if (head >= tape.length() || tape[head] != 'c') return false;
        tape[head] = 'Z'; // Mark 'c'
    }
    
    // Check if all symbols are marked
    for (char c : tape) {
        if (c != 'X' && c != 'Y' && c != 'Z') return false;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter string (a^n b^n c^n): ";
    cin >> input;
    cout << (turingMachineAnBnCn(input) ? "Accepted" : "Rejected") << endl;
    
    // Test cases
    cout << "\nTest Cases:" << endl;
    cout << "abc: " << (turingMachineAnBnCn("abc") ? "Accepted" : "Rejected") << endl;
    cout << "aabbcc: " << (turingMachineAnBnCn("aabbcc") ? "Accepted" : "Rejected") << endl;
    cout << "aaabbbccc: " << (turingMachineAnBnCn("aaabbbccc") ? "Accepted" : "Rejected") << endl;
    cout << "aabbc: " << (turingMachineAnBnCn("aabbc") ? "Accepted" : "Rejected") << endl;
    
    return 0;
}
