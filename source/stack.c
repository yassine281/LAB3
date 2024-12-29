#include <stdlib.h>
#include <string.h>
#include "Stack.h"

void initStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

void freeStack(Stack* stack) {
    while (stack->top != NULL) {
        StackNode* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    stack->size = 0;
}

size_t stackSize(const Stack* stack) {
    return stack->size;
}

void push(Stack* stack, const Record* record) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) return;

    newNode->data = *record;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

Record pop(Stack* stack) {
    if (!stack->top) return (Record){0}; 

    StackNode* temp = stack->top;
    Record record = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return record;
}

Record peek(const Stack* stack) {
    if (!stack->top) return (Record){0};
    return stack->top->data;
}

Record getRecordAt(const Stack* stack, size_t index) {
    if (index >= stack->size) return (Record){0};

    StackNode* current = stack->top;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void setRecordAt(Stack* stack, size_t index, const Record* record) {
    if (index >= stack->size) return;

    StackNode* current = stack->top;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = *record;
}