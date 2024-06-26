#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the given string belongs to the CFG language
bool belongsToLanguage(const char* str) {
    int len = strlen(str);
    int i = 0;

    // Check if the string consists of 'a's and 'b's only
    while (i < len) {
        if (str[i] == 'a' || str[i] == 'b') {
            i++;
        } else {
            return false;
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

