#include <iostream>
#include <string>
using namespace std;

bool acceptsTwoOrThreeOnes(const string& str) {
    int count = 0;
    for (char c : str) {
        if (c == '1') count++;
        if (count > 3) return false;
    }
    return count == 2 || count == 3;
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;
    cout << (acceptsTwoOrThreeOnes(input) ? "Accepted" : "Rejected") << endl;
    return 0;
}

