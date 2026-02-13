#include <stdio.h>
#include <limits.h>
#include "../include/schedulers.h"
#include "../include/utils.h"


void sjf(process p[] , int n){
    sort(p,n);
    int curr_time = 0;
    int completed = 0;
    int completed_process[100] = {0};
    while(completed != n){
        int idx = -1;
        int min_burst = INT_MAX;
        for(int i=0;i<n;i++){
            if(p[i].arrival_time <= curr_time){
                if(completed_process[i] == 0)
                    if(p[i].burst_time < min_burst){
                        min_burst = p[i].burst_time;
                        idx = i;
                    }

            }
           
        }
         if(idx != -1){
            p[idx].start_time = curr_time;
            p[idx].completion_time = curr_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;

            completed_process[idx] = 1;
            completed++;
            curr_time = p[idx].completion_time;
            }
            else curr_time++;
    }
}