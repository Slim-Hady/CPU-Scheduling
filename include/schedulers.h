#ifndef SCHEDLUERS_H
#define SCHEDLUERS_H
#include "process.h"

void FCFS(process p[] , int n);
void rr(process p[] , int n , int quantum);
void sjf(process p[] , int n);

#endif