#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "direction.h"

char symbol(char direction) {
	switch (direction) {
		case 'n':
			return '^';
		case 's':
			return 'v';
		case 'w':
			return '<';
		case 'e':
			return '>';
		case 'f':
			return '/';
		case 'b':
			return '\\';
		default:
			return ' ';
	}
}
