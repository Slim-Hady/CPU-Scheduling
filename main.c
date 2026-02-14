#include <stdio.h>
#include "./include/utils.h"
#include "./include/process.h"
#include "./include/schedulers.h"

int main() {
    process p[100];
    int n;

    readFile("input.txt", p, &n); 
    printf("Successfully read %d processes.\n", n);

    int quantum = 2; 
    rr(p, n, quantum);

    writeFile("output.txt", p, n);
    printf("Output file created.\n");
    
    return 0;
}