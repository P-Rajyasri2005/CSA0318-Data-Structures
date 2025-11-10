#include <stdio.h>

int main() {
    int num, rev = 0, rem;
    printf("Enter a 32-bit signed integer: ");
    scanf("%d", &num);
    while (num != 0) {
        rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }
    printf("Reversed Integer: %d\n", rev);
    return 0;
}
