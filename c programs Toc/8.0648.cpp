#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the given string belongs to the CFG language
bool belongsToLanguage(const char* str) {
    int len = strlen(str);
    int i = 0;

    // Iterate through the string
    while (i < len) {
        if (str[i] == 'a') {
            // If 'a' is encountered, move to the next character
            i++;
        } else {
            // If any other character is encountered, the string does not belong to the language
            return false;
        }
    }

    // If the entire string consists of 'a's, it belongs to the language
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

