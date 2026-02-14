#include <stdio.h>
#include "./include/utils.h"
#include "./include/process.h"
#include "./include/schedulers.h"

int main() {
    process p[100];
    int n;
    int choice;

    readFile("input.txt", p, &n); 
    
    printf("\n--- CPU Scheduler ---\n");
    printf("1. FCFS\n");
    printf("2. SJF\n");
    printf("3. RR\n");
    printf("Choose algorithm: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            FCFS(p, n);
            break;
        case 2:
            sjf(p, n);
            break;
        case 3:
            {
                int quantum;
                printf("Enter Quantum: ");
                scanf("%d", &quantum);
                rr(p, n, quantum);
            }
            break;
        default:
            printf("Invalid Choice!\n");
            return 1;
    }

    writeFile("output.txt", p, n);
    printf("\nDone! Results saved to output.txt\n");
    
    return 0;
}