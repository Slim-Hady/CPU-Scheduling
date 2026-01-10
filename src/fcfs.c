#include <stdio.h>
#include "../include/schedulers.h"
#include "../include/process.h"
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

void FCFS(process p[] , int n){
    sort(p , n);
    int curr_time = 0;
    for(int i =0 ; i < n ; i++){
        if(curr_time < p[i].arrival_time){
            curr_time = p[i].arrival_time;
        }
        p[i].start_time = curr_time;
        curr_time += p[i].burst_time;
        p[i].completion_time = curr_time;
        p[i].turnaround_time = p[i].completion_time- p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}
