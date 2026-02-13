#include <stdio.h>
#include "../include/schedulers.h"
#include "../include/process.h"
#include "../include/utils.h"

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
