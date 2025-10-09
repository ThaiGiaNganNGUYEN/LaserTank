#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "copy.h"
#include "LinkedList.h"
#include "map.h"

void copy_map(char **Map, int row_size, int col_size, LinkedList *linkedlist) {
    char **copy = (char **)malloc(row_size * sizeof(char *));
	int i;
    for ( i = 0; i < row_size; i++) {
        copy[i] = (char *)malloc(col_size * sizeof(char));
        memcpy(copy[i], Map[i], col_size * sizeof(char));
    }
    insertLast(linkedlist, copy);
}


void writeMapSequenceToFile(int row_size,int col_size, LinkedList *linkedlist) {
    FILE *outputFile = fopen("output.txt", "w");
    if (!outputFile) {
        printf("Error opening output file.\n");
        return;
    }
    output(row_size, col_size, outputFile, linkedlist);
    fclose(outputFile);
}


void output(int row_size, int col_size, void *outPtr, LinkedList *linkedlist) {
    int i, j;
    char value;
    LinkedListNode *curr = linkedlist->head;

    while (curr != NULL) {
        char **map_copy = (char **)curr->data; 

        for (i = 0; i < row_size; i++) { 
            for (j = 0; j < col_size; j++) { 
                value = map_copy[i][j]; 
                fprintf(outPtr, "%c", value);
            }
            fprintf(outPtr, "\n");
        }
        fprintf(outPtr, "\n\n\n\n\n");
        curr = curr->next;
    }
}

