#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// CFG recognition function
bool belongsToCFG(char* str) {
    int len = strlen(str);
    int i = 0;

    // Check if the string follows the rules
    if (len < 4 || str[0] != '1' || str[len - 1] != '1') {
        return false;
    }

    // Check the middle part (between the first and last '1')
    for (i = 1; i < len - 1; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false; // Invalid character
        }
    }

    return true; // String follows the CFG rules
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (belongsToCFG(input)) {
        printf("The string belongs to the CFG language.\n");
    } else {
        printf("The string does not belong to the CFG language.\n");
    }

    return 0;
}

