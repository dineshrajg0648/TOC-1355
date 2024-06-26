#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, length;

    printf("Enter a string: ");
    scanf("%s", str);

    length = strlen(str);
    if (length < 2 || str[0] != 'a' || str[length - 1] != 'a') {
        printf("The string is not accepted by the DFA.\n");
        return 0;
    }

    for (i = 1; i < length - 1; i++) {
        if (str[i] != 'a' && str[i] != 'b') {
            printf("The string is not accepted by the DFA.\n");
            return 0;
        }
    }

    printf("The string is accepted by the DFA.\n");
    return 0;
}
