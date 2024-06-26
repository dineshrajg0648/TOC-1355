#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// DFA transition function
int transition(int state, char input) {
    switch (state) {
        case 0:
            if (input == 'b') return 1;
            break;
        case 1:
            if (input == 'a') return 2;
            break;
        case 2:
            if (input == 'b') return 1;
            break;
    }
    return -1; // Invalid transition
}

int main() {
    char input[100];
    printf("Enter an input string: ");
    scanf("%s", input);

    int currentState = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        currentState = transition(currentState, input[i]);
        if (currentState == -1) {
            printf("Invalid input. Not in the language.\n");
            return 0;
        }
    }

    if (currentState == 2) {
        printf("Accepted! The input string is in the language.\n");
    } else {
        printf("Rejected! The input string is not in the language.\n");
    }

    return 0;
}

