#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"
#include "Sort.h"
#include "io.h"

int compareAsc(const Record* a, const Record* b) {
    return a->id - b->id;
}

int compareDesc(const Record* a, const Record* b) {
    return b->id - a->id;
}

int main(int argc, char* argv[]) {
    Stack stack;
    initStack(&stack);

    char* inputFile = NULL;
    char* outputFile = NULL;
    int mode = 0; 
    int sortType = 0; 
    int numRecords = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--generate") == 0 || strcmp(argv[i], "-g") == 0) {
            mode = 1;
            numRecords = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--sort") == 0 || strcmp(argv[i], "-s") == 0) {
            mode = 2;
        } else if (strcmp(argv[i], "--print") == 0 || strcmp(argv[i], "-p") == 0) {
            mode = 3;
        } else if (strncmp(argv[i], "--in=", 5) == 0) {
            inputFile = argv[i] + 5;
        } else if (strncmp(argv[i], "--out=", 6) == 0) {
            outputFile = argv[i] + 6;
        } else if (strncmp(argv[i], "--type=", 7) == 0) {
            sortType = strcmp(argv[i] + 7, "desc") == 0;
        }
    }

    if (mode == 1) {
        for (int i = 0; i < numRecords; i++) {
            Record record = {i, "Record", i * 1.1, i % 2 == 0};
            push(&stack, &record);
        }
        if (outputFile) saveToCSV(&stack, outputFile);
        else printRecords(&stack);
    } else if (mode == 2) {
        if (inputFile) loadFromCSV(&stack, inputFile);
        insertionSort(&stack, sortType ? compareDesc : compareAsc);
        if (outputFile) saveToCSV(&stack, outputFile);
        else printRecords(&stack);
    } else if (mode == 3) {
        if (inputFile) loadFromCSV(&stack, inputFile);
        printRecords(&stack);
    }

    freeStack(&stack);
    return 0;
}