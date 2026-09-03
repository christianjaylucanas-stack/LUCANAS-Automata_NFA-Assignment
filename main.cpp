
---

### **2. `main.cpp`**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Function to simulate the DFA for a C-style comment
bool isValidCComment(const string& s) {
    // Define the states of our DFA
    enum State { Q0, Q1, Q2, Q3, Q4, TRAP };
    State currentState = Q0;

    for (char c : s) {
        // Treat any character other than '*' or '/' as a general placeholder 'a'
        char symbol = (c == '*' || c == '/') ? c : 'a';

        switch (currentState) {
            case Q0:
                if (symbol == '/') currentState = Q1;
                else currentState = TRAP;
                break;
                
            case Q1:
                if (symbol == '*') currentState = Q2;
                else currentState = TRAP;
                break;
                
            case Q2:
                if (symbol == '*') currentState = Q3;
                else currentState = Q2; // 'a' or '/' keeps it inside the comment body
                break;
                
            case Q3:
                if (symbol == '/') currentState = Q4;       // Successfully closed with */
                else if (symbol == '*') currentState = Q3;  // Multiple consecutive stars
                else currentState = Q2;                // False alarm, back to comment body
                break;
                
            case Q4:
                // Any characters after the closing '*/' push the machine into a dead state
                currentState = TRAP;
                break;
                
            case TRAP:
                // Once in the trap state, remain there
                break;
        }
        
        // Early exit optimization if a dead state is reached
        if (currentState == TRAP) return false;
    }

    // The string is valid only if it terminates precisely in the accepting state (Q4)
    return currentState == Q4;
}

int main() {
    // Test cases derived from slide requirements
    vector<string> accepted = {"/*a*/", "/**/", "/***/", "/*aaa*aaa*/", "/*a/a*/"};
    vector<string> rejected = {"/**", "/**/a/*aa*/", "aaa/**/aa", "/*/", "/**a/", "//aaaa"};

    cout << "========================================" << endl;
    cout << "   C-STYLE COMMENT DFA VALIDATOR        " << endl;
    cout << "========================================" << endl;

    cout << "\n--- ACCEPTED STRINGS ---" << endl;
    for (const string& text : accepted) {
        cout << left << setw(15) << text << " -> " 
             << (isValidCComment(text) ? "Accepted" : "Rejected") << endl;
    }

    cout << "\n--- REJECTED STRINGS ---" << endl;
    for (const string& text : rejected) {
        cout << left << setw(15) << text << " -> " 
             << (isValidCComment(text) ? "Accepted" : "Rejected") << endl;
    }

    cout << "========================================" << endl;
    return 0;
}

```