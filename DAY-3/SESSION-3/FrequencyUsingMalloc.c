#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums = 1202105;
    int temp = nums;
    
    int *freq = (int *)calloc(10, sizeof(int));
    
    if (temp == 0) {
        freq[0] = 1;
    }
    
    while (temp > 0) {
        int digit = temp % 10;
        freq[digit]++;
        temp = temp / 10;
    }
    
    printf("Number: %d\n", nums);
    printf("Digit frequencies:\n");
    for (int i = 0; i < 10; i++) {
        if (freq[i] > 0) {
            printf("Digit %d: %d times\n", i, freq[i]);
        }
    }
    
    free(freq);
    
    return 0;
}