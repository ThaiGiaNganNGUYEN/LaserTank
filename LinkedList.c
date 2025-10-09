#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "LinkedList.h"
#include "map.h"
#include "mirror.h"

LinkedList *createLinkedList(void) {
	LinkedList *linkedlist = NULL;
	linkedlist = (LinkedList *)malloc(sizeof(LinkedList));
	linkedlist->head = NULL;
	linkedlist->count = 0;

	return linkedlist;
}

void insertStart(LinkedList *list, void *entry) {
	LinkedListNode *newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
	newNode->data = entry;
	newNode->next = list->head;
	list->head = newNode;
	list->count++;
}

void insertLast(LinkedList *list, void *entry) {
	LinkedListNode *newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
	LinkedListNode *curr = list->head;
	newNode->next = NULL;
	newNode->data = entry;

	if (list->head == NULL) {
		list->head = newNode;
	} else {
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
	list->count++;
}

void printLinkedList(LinkedList *list, listFunc funcPtr, int row_size) {
	LinkedListNode *curr = list->head;
	while(curr != NULL) {
		(*funcPtr)(curr->data, row_size);
		curr = curr->next;
	}
	free(curr);
}

void freeLinkedList(LinkedList *list, listFunc funcPtr, int row_size) {
	LinkedListNode *curr = list->head;
	LinkedListNode *nextCurr = NULL;

	while (curr != NULL) {
		nextCurr = curr->next;
		(*funcPtr)(curr->data, row_size);
		free(curr);
		curr = nextCurr;
	}
	free(list);
}

void freeLinkedList2(LinkedList *list, listFun funcPtr) {
	LinkedListNode *curr = list->head;
	LinkedListNode *nextCurr = NULL;

	while (curr != NULL) {
		nextCurr = curr->next;
		(*funcPtr)(curr->data);
		free(curr);
		curr = nextCurr;
	}
	free(list);
}

void printResult(void *data) {
	printf("%d %d %c\n", ((mirror*)data)->row_size, ((mirror *)data)->col_size, ((mirror *)data)->type);
}

void freeData(void *data, int row_size) {
	int i;
	for (i = 0; i < row_size; i++) {
		free((((map *)data)->copy)[i]);
	}
	free(((map *)data)->copy);
}

void freeData2(void *data) {
	free(((mirror *)data));
}
