#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

void loadFromCSV(stack* stack, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Record record;
        char activeStr[10];
        sscanf(line, "%d,%49[^,],%lf,%9s", &record.id, record.name, &record.value, activeStr);
        record.isActive = strcmp(activeStr, "YES") == 0;
        push(stack, &record);
    }

    fclose(file);
}

void saveToCSV(const Stack* stack, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    size_t size = stackSize(stack);
    for (size_t i = 0; i < size; i++) {
        Record record = getRecordAt(stack, i);
        fprintf(file, "%d,%s,%.2f,%s\n", record.id, record.name, record.value, record.isActive ? "YES" : "NO");
    }

    fclose(file);
}

void printRecords(const Stack* stack) {
    printf("%-5s %-20s %-10s %-5s\n", "ID", "Name", "Value", "Active");
    size_t size = stackSize(stack);
    for (size_t i = 0; i < size; i++) {
        Record record = getRecordAt(stack, i);
        printf("%-5d %-20s %-10.2f %-5s\n", record.id, record.name, record.value, record.isActive ? "YES" : "NO");
    }
}