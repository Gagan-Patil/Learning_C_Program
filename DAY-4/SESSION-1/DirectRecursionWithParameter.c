#include <stdio.h>

void printNumbers(int n) {
    if (n > 5) {
        return;
    }
    printf("%d\n", n);
    printNumbers(n + 1);
}

int main() {
    printNumbers(1);
    return 0;
}