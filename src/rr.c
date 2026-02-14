#include <stdio.h>
#include <stdbool.h>
#include "../include/schedulers.h"
#include "../include/utils.h"

void rr(process p[] , int n , int quantum){
    sort(p , n);
    for(int i = 0; i < n;i++){
        p[i].remaining_time = p[i].burst_time;
    }
    int curr = 0;
    int completed = 0;
    while(completed != n){
        bool work = false;
        for(int i =0;i<n;i++){
            if(p[i].remaining_time > 0 && p[i].arrival_time <= curr){
                work = true;
                if(p[i].remaining_time > quantum){
                    p[i].remaining_time -= quantum;
                    curr += quantum;
                }
                else {
                    curr += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    completed++;
                    p[i].completion_time = curr;
                    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time; 
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                }
            }
        }
        if (work == false) {
        curr++; 
    }
    }
}
