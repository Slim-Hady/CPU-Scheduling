#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"
#include "../include/process.h"

void readFile(const char* filename, process p[], int* n){
    FILE *input = fopen(filename , "r");
    if(input == NULL) {
        printf("ERROR");
        exit(1);
    }
    int i =0 ;
    int sum = 0;
    while(fscanf(input, "%d %d %d", 
                 &p[i].processID,      
                 &p[i].arrival_time, 
                 &p[i].burst_time) != EOF) {

        p[i].start_time = 0;
        p[i].waiting_time = 0;
        p[i].turnaround_time = 0;
        p[i].completion_time= 0;
        p[i].remaining_time = p[i].burst_time;
        sum += p[i].arrival_time + p[i].waiting_time ;
        i++;
    }
    *n = i;
    fclose(input);
}

void writeFile(const char* filename, process p[], int n){
    FILE *output = fopen(filename , "w");
    if(output == NULL) {
        printf("ERROR");
        exit(1);
    }
    fprintf(output, "PID\tAT\tBT\tWT\tTAT\n");
    fprintf(output, "-------------------------------------\n");
    float total_waiting = 0;
    float total_turnaround = 0;
    for(int i = 0; i < n; i++) {
        fprintf(output, "%d\t%d\t%d\t%d\t%d\n", 
                p[i].processID, 
                p[i].arrival_time, 
                p[i].burst_time,
                p[i].waiting_time,
                p[i].turnaround_time);
        total_waiting += p[i].waiting_time;
        total_turnaround += p[i].turnaround_time;
    }
    fprintf(output, "-------------------------------------\n");
    fprintf(output, "Average Waiting Time = %.2f\n", total_waiting / n);
    fprintf(output, "Average Turnaround Time = %.2f\n", total_turnaround / n);
    fclose(output);
}
// this sorting by arrival time ( bubble sort)
void sort(process p [] , int n){
    process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}