#ifndef PROCESS_H
#define PROCESS_H

typedef struct 
{
    int processID;
    int arrival_time;
    int turnaround_time;
    int waiting_time;
    int burst_time;
    int start_time;
    int remaining_time;
} process;

#endif