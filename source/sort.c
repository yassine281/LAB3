#include "Sort.h"

void insertionSort(Stack* stack, Comparator comparator) {
    for (size_t i = 1; i < stackSize(stack); i++) {
        Record key = getRecordAt(stack, i);
        size_t j = i;

        while (j > 0 && comparator(&getRecordAt(stack, j - 1), &key) > 0) {
            Record temp = getRecordAt(stack, j - 1);
            setRecordAt(stack, j, &temp);
            j--;
        }

        setRecordAt(stack, j, &key);
    }
}