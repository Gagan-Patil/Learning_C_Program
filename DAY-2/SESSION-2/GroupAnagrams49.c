#include <stdlib.h>
#include <string.h>

// 1. Define the custom struct
typedef struct {
    char* original;
    char* sorted;
} StringPair;

// 2. Define the helper function for sorting characters within a string
int compareChars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

// 3. Define the helper function for sorting the pairs array
int comparePairs(const void* a, const void* b) {
    return strcmp(((StringPair*)a)->sorted, ((StringPair*)b)->sorted);
}

// 4. The main function
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if (strsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    StringPair* pairs = (StringPair*)malloc(strsSize * sizeof(StringPair));
    for (int i = 0; i < strsSize; i++) {
        pairs[i].original = strs[i];
        pairs[i].sorted = strdup(strs[i]);
        qsort(pairs[i].sorted, strlen(pairs[i].sorted), sizeof(char), compareChars);
    }

    qsort(pairs, strsSize, sizeof(StringPair), comparePairs);

    char*** result = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    *returnSize = 0;

    int currentGroupSize = 0;
    int groupCapacity = 10;
    result[0] = (char**)malloc(groupCapacity * sizeof(char*));

    for (int i = 0; i < strsSize; i++) {
        if (i == 0 || strcmp(pairs[i].sorted, pairs[i - 1].sorted) == 0) {
            if (currentGroupSize == groupCapacity) {
                groupCapacity *= 2;
                result[*returnSize] = (char**)realloc(result[*returnSize], groupCapacity * sizeof(char*));
            }
            result[*returnSize][currentGroupSize++] = pairs[i].original;
        } else {
            (*returnColumnSizes)[*returnSize] = currentGroupSize;
            (*returnSize)++;
            
            currentGroupSize = 0;
            groupCapacity = 10;
            result[*returnSize] = (char**)malloc(groupCapacity * sizeof(char*));
            result[*returnSize][currentGroupSize++] = pairs[i].original;
        }
    }
    
    (*returnColumnSizes)[*returnSize] = currentGroupSize;
    (*returnSize)++;

    for (int i = 0; i < strsSize; i++) {
        free(pairs[i].sorted);
    }
    free(pairs);

    return result;
}