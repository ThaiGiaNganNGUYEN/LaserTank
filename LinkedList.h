#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct {
	int row_size;
	int col_size;
	char type;
} mirror;

typedef struct {
	int **copy;
} map;


typedef struct LinkedListNode{
	void *data;
	struct LinkedListNode *next;
} LinkedListNode;

typedef struct {
	LinkedListNode *head;
	int count;
} LinkedList;

typedef void(*listFunc)(void *data, int row_size);
typedef void(*listFun)(void *data);
LinkedList *createLinkedList(void);
void printResult(void *data);
void freeData(void *data, int row_size);
void freeData2(void *data);
void insertStart(LinkedList *list, void *entry);
void insertLast(LinkedList *list, void *entry);
void printLinkedList(LinkedList *list, listFunc funcPtr, int row_size);
void freeLinkedList(LinkedList *list, listFunc funcPtr, int row_size);
void freeLinkedList2(LinkedList *list, listFun funcPtr);

#endif


