#include <stdio.h>
#include <stdbool.h>

// NFA transition function
int transition(int state, char input) {
    switch (state) {
        case 0:
            if (input == 'b') return 1;
            break;
        case 1:
            if (input == 'a') return 2;
            break;
        case 2:
            // No further transitions allowed
            break;
    }
    return -1; // Invalid transition
}

// NFA simulation
bool simulateNFA(const char* str) {
    int currentState = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        currentState = transition(currentState, str[i]);
        if (currentState == -1) {
            return false; // Invalid transition
        }
    }
    return currentState == 2; // Accept if final state is 2
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulateNFA(input)) {
        printf("The string \"%s\" is accepted by the NFA.\n", input);
    } else {
        printf("The string \"%s\" is not accepted by the NFA.\n", input);
    }

    return 0;
}

