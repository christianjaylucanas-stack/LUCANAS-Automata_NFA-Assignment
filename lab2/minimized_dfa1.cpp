#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

bool evaluateDFA1(const string& s) {
    enum State { AB, CDE, F };
    State currentState = AB; 

    for (char c : s) {
        switch (currentState) {
            case AB:
                if (c == '0') currentState = AB;
                else if (c == '1') currentState = CDE;
                else currentState = F; 
                break;
            case CDE:
                if (c == '0') currentState = CDE;
                else if (c == '1') currentState = F;
                else currentState = F;
                break;
            case F:
                break;
        }
    }
    return currentState == CDE; 
}

int main() {
    vector<string> test_strings = {"00100", "1", "0000", "101", "11"};
    cout << "--- MINIMIZATION EXAMPLE 1 ---" << endl;
    for (const string& text : test_strings) {
        cout << left << setw(10) << text << " -> " 
             << (evaluateDFA1(text) ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}