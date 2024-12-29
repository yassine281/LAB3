#ifndef DATA_H
#define DATA_H

#include <stdbool.h>

typedef struct {
    int id;
    char name[50];
    double value;
    bool isActive; // true: YES, false: NO
} Record;

typedef int (Comparator)(const Record, const Record*);

#endif