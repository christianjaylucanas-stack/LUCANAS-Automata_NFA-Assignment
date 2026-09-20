#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

bool evaluateDFA2(const string& s) {
    enum State { AC, B, D, E };
    State currentState = AC; 

    for (char c : s) {
        switch (currentState) {
            case AC:
                if (c == '0') currentState = B;
                else if (c == '1') currentState = AC; 
                break;
            case B:
                if (c == '0') currentState = B;
                else if (c == '1') currentState = D;
                break;
            case D:
                if (c == '0') currentState = B;
                else if (c == '1') currentState = E;
                break;
            case E:
                if (c == '0') currentState = B;
                else if (c == '1') currentState = AC; 
                break;
        }
    }
    return currentState == E;
}

int main() {
    vector<string> test_strings = {"0110", "011011", "011", "111", "0011"};
    cout << "--- MINIMIZATION EXAMPLE 2 ---" << endl;
    for (const string& text : test_strings) {
        cout << left << setw(10) << text << " -> " 
             << (evaluateDFA2(text) ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}