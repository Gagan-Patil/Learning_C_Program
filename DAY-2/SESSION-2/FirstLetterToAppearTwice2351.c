char repeatedCharacter(char* s) {
    int seen = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        int bit = s[i] - 'a';
        
        if (seen & (1 << bit)) {
            return s[i];
        }
        
        seen |= (1 << bit);
    }
    
    return '\0';
}