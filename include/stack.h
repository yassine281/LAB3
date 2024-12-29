#ifndef STACK_H
#define STACK_H

#include "Data.h"

typedef struct StackNode {
    Record data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
    size_t size;
} Stack;


void initStack(Stack* stack);
void freeStack(Stack* stack);

size_t stackSize(const Stack* stack);
void push(Stack* stack, const Record* record);
Record pop(Stack* stack);
Record peek(const Stack* stack);
Record getRecordAt(const Stack* stack, size_t index);
void setRecordAt(Stack* stack, size_t index, const Record* record);

#endif