#include <stdio.h>
#include "./include/utils.h"
#include "./include/process.h"
#include "./include/schedulers.h"

int main() {
    process p[100];
    int n;

    readFile("input.txt", p, &n); 

    printf("Successfully read %d processes.\n", n);
    
    // FCFS(p ,n);  <-- شيلنا دي
    sjf(p, n);   // <-- وحطينا دي
    
    writeFile("output.txt", p, n);
    printf("Output file created (SJF Result).\n");
    
    return 0;
}