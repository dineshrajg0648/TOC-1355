#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the given string belongs to the CFG language
bool belongsToLanguage(const char* str) {
    int len = strlen(str);
    int i = 0;

    // Check if the string starts with 'A'
    if (str[i] == 'A') {
        i++;
    } else {
        return false;
    }

    // Check for 'a' in the middle
    while (i < len && str[i] == 'a') {
        i++;
    }
    if (i >= len || str[i] != 'A') {
        return false;
    }
    i++;

    // Check for 'a' again
    while (i < len && str[i] == 'a') {
        i++;
    }
    if (i >= len || str[i] != 'A') {
        return false;
    }
    i++;

    // Check if the remaining part is 'A'
    while (i < len && str[i] == 'A') {
        i++;
    }

    // If the entire string adheres to the CFG rules, it belongs to the language
    return i == len;
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

