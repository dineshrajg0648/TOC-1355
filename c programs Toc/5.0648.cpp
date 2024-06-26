#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// CFG recognition function
bool belongsToCFG(char* str) {
    int len = strlen(str);
    int i = 0;

    // Check if the string follows the rules
    while (i < len) {
        if (str[i] == '0') {
            // If '0', look for matching '0' later in the string
            int j = i + 1;
            while (j < len && str[j] != '0') {
                j++;
            }
            if (j == len || !belongsToCFG(str + i + 1)) {
                return false;
            }
            i = j + 1;
        } else if (str[i] == '1') {
            // If '1', continue to the next character
            i++;
        } else {
            // Invalid character
            return false;
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

