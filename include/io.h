#ifndef IO_H
#define IO_H

#include "Stack.h"

void loadFromCSV(Stack* stack, const char* filename);
void saveToCSV(const Stack* stack, const char* filename);
void printRecords(const Stack* stack);

#endif