# Automata and Theory of Computation: C-Style Comment DFA

This repository contains a Deterministic Finite Automaton (DFA) implementation designed to recognize C-style block comments (`/* ... */`) over the alphabet $\Sigma = \{a, *, /\}$, where `a` acts as a placeholder for any character that is not a star or a slash.

---

## 📌 Automata Design

### States
* **$q_0$**: Initial state (waiting for the opening `/`).
* **$q_1$**: Read opening `/`, waiting for `*`.
* **$q_2$**: Inside the comment body (last read symbol was not `*`).
* **$q_3$**: Inside the comment body, last read symbol was `*` (potential closing).
* **$q_4$**: **Accepting state** (comment successfully closed with `*/`).
* **$q_{\text{trap}}$**: Dead state (invalid sequence or extra characters after closing).

### Transition Table

| State | Input `a` | Input `*` | Input `/` |
| :--- | :--- | :--- | :--- |
| $\rightarrow q_0$ | $q_{\text{trap}}$ | $q_{\text{trap}}$ | $q_1$ |
| $q_1$ | $q_{\text{trap}}$ | $q_2$ | $q_{\text{trap}}$ |
| $q_2$ | $q_2$ | $q_3$ | $q_2$ |
| $q_3$ | $q_2$ | $q_3$ | **$q_4$** |
| $*q_4$ | $q_{\text{trap}}$ | $q_{\text{trap}}$ | $q_{\text{trap}}$ |
| $q_{\text{trap}}$ | $q_{\text{trap}}$ | $q_{\text{trap}}$ | $q_{\text{trap}}$ |

---

## 🚀 How to Run the Code

1. Make sure you have a C++ compiler installed (like `g++`).
2. Compile the source file:
   ```bash
   g++ main.cpp -o comment_checker