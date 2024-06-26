#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the given string belongs to the CFG language
bool belongsToLanguage(const char* str) {
    int len = strlen(str);
    int i = 0;

    // Check if the string starts with 'a'
    if (str[i] == 'a') {
        i++;
    } else {
        return false;
    }

    // Check for 'b' in the middle
    while (i < len && str[i] == 'b') {
        i++;
    }
    if (i >= len || str[i] != 'a') {
        return false;
    }
    i++;

    // Check if the remaining part follows the rules for 'A'
    while (i < len) {
        if (str[i] == 'a') {
            i++;
        } else if (str[i] == 'b') {
            i++;
        } else {
            return false; // Invalid character
        }
    }

    // If the entire string adheres to the CFG rules, it belongs to the language
    return true;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (belongsToLanguage(input)) {
        printf("The string \"%s\" belongs to the CFG language.\n", input);
    } else {
        printf("The string \"%s\" does not belong to the CFG language.\n", input);
    }

    return 0;
}

