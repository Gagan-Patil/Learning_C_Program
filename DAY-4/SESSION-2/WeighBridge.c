#include <stdio.h>
#include <stdlib.h>

struct Ticket {
    int num;
    char registration[100];
    double gross;
    double tare;
    double net;
};

void calculateNet(struct Ticket *t) {
    t->net = t->gross - t->tare;
}

// Added the missing Helper2 function to print ticket details
void Helper2(struct Ticket *t) {
    printf("\nTicket %d | Reg: %s | Gross: %.2lf | Tare: %.2lf | Net: %.2lf", 
           t->num, t->registration, t->gross, t->tare, t->net);
}

int main() {
    int n;
    printf("Enter the number of tickets: ");
    scanf("%d", &n);

    // Dynamically allocate memory based on 'n'
    struct Ticket *array = malloc(n * sizeof(struct Ticket));

    // Input loop
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for ticket %d (num, registration, gross, tare):\n", i + 1);
        scanf("%d", &array[i].num);
        scanf("%99s", array[i].registration); // Added width limit to prevent overflow
        scanf("%lf", &array[i].gross);
        scanf("%lf", &array[i].tare);
        calculateNet(&array[i]);
    }
    
    double total = 0;
    int maxIndex = 0;
    
    // Calculate total and find the ticket with the maximum net weight
    for (int i = 0; i < n; i++) {
        double netW = array[i].net;
        total += netW;

        if (netW > array[maxIndex].net) {
            maxIndex = i;
        }
    }
    
    printf("\n--- SUMMARY ---\n");
    printf("Total net weight: %.2lf\n", total);
    printf("Ticket with maximum net weight:\n");
    printf("Number: %d\n", array[maxIndex].num);
    printf("Registration: %s\n", array[maxIndex].registration);
    printf("Net Weight: %.2lf\n", array[maxIndex].net);

    printf("\n--- WEIGHBRIDGE BOOK ---");
    
    // Print all tickets using Helper2
    for (int i = 0; i < n; i++) {
        Helper2(&array[i]);
    }
    
    printf("\n\nTotal Weight: %.2lf", total);
    printf("\nTicket Number with Maximum weight: %d\n", array[maxIndex].num);
    
    free(array); // Free dynamically allocated memory
    return 0;
}