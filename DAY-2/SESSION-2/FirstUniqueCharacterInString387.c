int firstUniqChar(char* s) {
    int counts[26] = {0};
    int i = 0;
    
    while (s[i] != '\0') {
        counts[s[i] - 'a']++;
        i++;
    }
    
    i = 0;
    while (s[i] != '\0') {
        if (counts[s[i] - 'a'] == 1) {
            return i;
        }
        i++;
    }
    
    return -1;
}