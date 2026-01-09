#ifndef UTILS_H
#define UTILS_H
#include "process.h"

void readFile(const char* filename, process p[], int* n);
void writeFile(const char* filename, process p[], int* n);

#endif