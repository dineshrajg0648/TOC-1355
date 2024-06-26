#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Maximum number of states in the NFA
#define MAX_STATES 100

// Structure to represent a state
typedef struct {
    int id;
    bool isFinal;
    int epsilonTransitions[MAX_STATES]; // Array to store e-transitions
} State;

// Function to compute e-closure for a given state
void computeEpsilonClosure(State nfa[], int state, bool visited[]) {
    if (visited[state]) {
        return; // Already visited
    }

    visited[state] = true; // Mark the state as visited

    // Recursively compute e-closure for each e-transition
    for (int i = 0; nfa[state].epsilonTransitions[i] != -1; i++) {
        int nextState = nfa[state].epsilonTransitions[i];
        computeEpsilonClosure(nfa, nextState, visited);
    }
}

int main() {
    int numStates;
    printf("Enter the number of states in the NFA: ");
    scanf("%d", &numStates);

    State nfa[MAX_STATES];
    bool visited[MAX_STATES];

    // Initialize the NFA states
    for (int i = 0; i < numStates; i++) {
        nfa[i].id = i;
        nfa[i].isFinal = false;
        memset(nfa[i].epsilonTransitions, -1, sizeof(nfa[i].epsilonTransitions));
        visited[i] = false;
    }

    // Read e-transitions for each state
    for (int i = 0; i < numStates; i++) {
        printf("Enter e-transitions for state %d (comma-separated, -1 to end): ", i);
        int j = 0;
        while (true) {
            scanf("%d", &nfa[i].epsilonTransitions[j]);
            if (nfa[i].epsilonTransitions[j] == -1) {
                break;
            }
            j++;
        }
    }

    // Compute e-closure for each state
    for (int i = 0; i < numStates; i++) {
        memset(visited, false, sizeof(visited));
        computeEpsilonClosure(nfa, i, visited);

        printf("e-closure(%d): {", i);
        for (int j = 0; j < numStates; j++) {
            if (visited[j]) {
                printf(" %d", j);
            }
        }
        printf(" }\n");
    }

    return 0;
}

