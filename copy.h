#ifndef COPY_H
#define COPY_H
#include "LinkedList.h"

void copy_map(char **Map, int row_size, int col_size, LinkedList *linkedlist);
void writeMapSequenceToFile(int row_size, int col_size, LinkedList *linkedlist);
void output(int row_size, int col_size, void *outPtr, LinkedList *linkedlist);

#endif
