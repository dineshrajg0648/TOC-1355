#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// CFG recognition function
bool belongsToCFG(char* str) {
    int len = strlen(str);
    int i = 0;
    int j = len - 1;

    while (i <= j) {
        if (str[i] != str[j]) {
            return false; // Not symmetric
        }
        i++;
        j--;
    }

    return true; // Symmetric string
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

