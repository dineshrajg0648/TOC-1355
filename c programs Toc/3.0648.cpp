#include <stdio.h>
#include <stdbool.h>

bool isValid(const char *str) {
    int index = 0;
    int len = 0;

    // Calculate the length of the string
    while (str[len] != '\0') {
        len++;
    }

    // Step 1: Check for initial '0'
    if (str[index] != '0') {
        return false;
    }
    index++;

    // Step 2: Parse A
    while (index < len && (str[index] == '0' || str[index] == '1')) {
        index++;
    }

    // Step 3: Check for final '1'
    if (index < len && str[index] == '1') {
        index++;
    } else {
        return false;
    }

    // The entire string should be consumed for it to be valid
    return index == len;
}

int main() {
    const char *testStrings[] = {
        "01",
        "0011",
        "000111",
        "0101",
        "00001111",
        "",
        "001",
        "1100"
    };
    int numTests = sizeof(testStrings) / sizeof(testStrings[0]);

    for (int i = 0; i < numTests; i++) {
        printf("String: \"%s\" is %s\n", testStrings[i], isValid(testStrings[i]) ? "VALID" : "INVALID");
    }

    return 0;
}

