#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STATES 3
#define SYMBOLS 2

int main() {
    // Transition table for the DFA
    int transitionTable[STATES][SYMBOLS] = {
        // State 0: Initial state
        {1, -1}, // '0' -> State 1, '1' -> Invalid (-1)
        // State 1: After '0'
        {1, 2},  // '0' -> State 1, '1' -> State 2
        // State 2: Final state (accepting state)
        {-1, -1} // '0' -> Invalid (-1), '1' -> Invalid (-1)
    };

    char input[100];

    printf("Enter a string to check if it starts with '0' and ends with '1': ");
    scanf("%s", input);

    int currentState = 0; // Start from initial state
    int inputLength = strlen(input);
    
    // Process each character in the input string
    for (int i = 0; i < inputLength; i++) {
        char symbol = input[i];
        
        // Determine symbol index (0 for '0', 1 for '1')
        int symbolIndex = (symbol == '0') ? 0 : (symbol == '1') ? 1 : -1;
        
        // If symbolIndex is -1, invalid symbol, reject
        if (symbolIndex == -1) {
            printf("Rejected: Invalid symbol '%c' found in the string.\n", symbol);
            return 0;
        }
        
        // Determine next state based on current state and input symbol
        currentState = transitionTable[currentState][symbolIndex];
        
        // If transition leads to an invalid state, reject
        if (currentState == -1) {
            printf("Rejected: String does not start with '0' or does not end with '1'.\n");
            return 0;
        }
    }
    
    // Check final state to determine acceptance
    if (currentState == 2) {
        printf("Accepted: The string \"%s\" starts with '0' and ends with '1'.\n", input);
    } else {
        printf("Rejected: The string \"%s\" does not start with '0' or does not end with '1'.\n", input);
    }

    return 0;
}

