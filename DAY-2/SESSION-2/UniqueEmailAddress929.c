#include <string.h>

int numUniqueEmails(char** emails, int emailsSize) {
    char processed[100][101];
    int uniqueCount = 0;
    
    for (int i = 0; i < emailsSize; i++) {
        char* email = emails[i];
        int j = 0;
        int k = 0;
        
        while (email[k] != '@' && email[k] != '+') {
            if (email[k] != '.') {
                processed[uniqueCount][j++] = email[k];
            }
            k++;
        }
        
        while (email[k] != '@') {
            k++;
        }
        
        while (email[k] != '\0') {
            processed[uniqueCount][j++] = email[k];
            k++;
        }
        processed[uniqueCount][j] = '\0';
        
        int isUnique = 1;
        for (int p = 0; p < uniqueCount; p++) {
            if (strcmp(processed[p], processed[uniqueCount]) == 0) {
                isUnique = 0;
                break;
            }
        }
        
        if (isUnique) {
            uniqueCount++;
        }
    }
    
    return uniqueCount;
}