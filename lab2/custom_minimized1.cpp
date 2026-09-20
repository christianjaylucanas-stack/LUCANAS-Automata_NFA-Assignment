#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

bool evaluateCustomDFA1(const string& s) {
    enum State { A, B, C };
    State currentState = A; 

    for (char c : s) {
        switch (currentState) {
            case A:
                if (c == '0' || c == '1') currentState = B;
                break;
            case B:
                if (c == '0') currentState = C;
                else if (c == '1') currentState = B;
                break;
            case C:
                currentState = C;
                break;
        }
    }
    return currentState == C; 
}

int main() {
    vector<string> test_strings = {"00", "10", "11110", "1", "1111", "0111"};
    cout << "--- CUSTOM MINIMIZED DFA 1 ---" << endl;
    for (const string& text : test_strings) {
        cout << left << setw(10) << text << " -> " 
             << (evaluateCustomDFA1(text) ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}