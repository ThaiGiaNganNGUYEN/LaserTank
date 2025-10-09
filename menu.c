#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void menu(char action) {
	printf("w to go/face up\n");
	printf("s to go/face down\n");
	printf("a to go/face left\n");
	printf("d to go/face right\n");
	printf("f to shoot laser\n");
	printf("action: ");
	scanf(" %c", &action);
}
