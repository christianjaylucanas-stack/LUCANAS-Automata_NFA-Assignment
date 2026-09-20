#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

bool evaluateCustomDFA2(const string& s) {
    enum State { A, B, C };
    State currentState = A; 

    for (char c : s) {
        switch (currentState) {
            case A:
                if (c == '0') currentState = B;
                else if (c == '1') currentState = A;
                break;
            case B:
                if (c == '0') currentState = C;
                else if (c == '1') currentState = A;
                break;
            case C:
                currentState = C;
                break;
        }
    }
    return currentState == C; 
}

int main() {
    vector<string> test_strings = {"00", "101001", "0000", "0101", "1111", "0"};
    cout << "--- CUSTOM MINIMIZED DFA 2 ---" << endl;
    for (const string& text : test_strings) {
        cout << left << setw(10) << text << " -> " 
             << (evaluateCustomDFA2(text) ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}