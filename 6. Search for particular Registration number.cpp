#include <stdio.h>

int main() {
    int reg[50], n, key, i, found = 0;
    printf("Enter number of registrations: ");
    scanf("%d", &n);

    printf("Enter registration numbers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &reg[i]);

    printf("Enter registration number to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (reg[i] == key) {
            printf("Registration number found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Registration number not found\n");

    return 0;
}
