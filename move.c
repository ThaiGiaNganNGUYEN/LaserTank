#include <stdio.h>
#include <stdlib.h>
#include "move.h"
#include "map.h"
#include "direction.h"

void move_player(char **map, int row_size, int col_size, char action, int *player_row, int *player_col) {
	if (action == 'w' && *player_row > 0 && map[*player_row - 1][*player_col] == ' ') {
		if (map[*player_row][*player_col] != '^') {
			map[*player_row][*player_col] = '^';
		} else {
			map[*player_row][*player_col] = ' ';
			(*player_row)--;
			map[*player_row][*player_col] = '^';
		}
	}
	else if (action == 's' && *player_row < row_size - 1 && map[*player_row + 1][*player_col] == ' ') {
		if (map[*player_row][*player_col] != 'v') {
			map[*player_row][*player_col] = 'v';
		} else {
			map[*player_row][*player_col] = ' ';
			(*player_row)++;
			map[*player_row][*player_col] = 'v';
		}
	}
	else if (action == 'a' && *player_col > 0 && map[*player_row][*player_col - 1] == ' ') {
		if (map[*player_row][*player_col] != '<') {
			map[*player_row][*player_col] = '<';
		} else {
			map[*player_row][*player_col] = ' ';
			(*player_col)--;
			map[*player_row][*player_col] = '<';
		}
	}
	else if (action == 'd' && *player_col < col_size - 1 && map[*player_row][*player_col + 1] == ' ') {
		if (map[*player_row][*player_col] != '>') {
			map[*player_row][*player_col] = '>';
		} else {
			map[*player_row][*player_col] = ' ';
			(*player_col)++;
			map[*player_row][*player_col] = '>';
		}
	}
}
