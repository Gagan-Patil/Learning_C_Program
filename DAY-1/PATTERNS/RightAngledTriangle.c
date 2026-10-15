#include <stdio.h>

int main() {
    int N = 4;
    // Loop starts at 1 and counts up to N
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}