#include<stdbool.h>
bool isAnagram(char* s, char* t) {
    int counts[26] = {0};
    int i = 0;

    // Count frequencies of characters in both strings
    while (s[i] != '\0' && t[i] != '\0') {
        counts[s[i] - 'a']++;
        counts[t[i] - 'a']--;
        i++;
    }

    // If strings are of different lengths
    if (s[i] != '\0' || t[i] != '\0') {
        return false;
    }

    // Check if all counts are zero
    for (int j = 0; j < 26; j++) {
        if (counts[j] != 0) {
            return false;
        }
    }

    return true;
}