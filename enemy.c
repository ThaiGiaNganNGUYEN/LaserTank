#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "enemy.h"
#include "laser.h"

#define UP '^'
#define DOWN 'v'
#define LEFT '<'
#define RIGHT '>'

void enemy_shoot(char **map, int row_size, int col_size, int player_row, int player_col, char player_direction, int enemy_row, int enemy_col, char enemy_direction, int lose) {
	if (player_row < enemy_row && player_col == enemy_col && map[enemy_row][enemy_col] == '^') {
		shoot_laser(map, row_size, col_size, enemy_row - 1, enemy_col, UP, player_row, player_col, lose);
		lose = 1;
	}
	else if (player_row > enemy_row && player_col == enemy_col && map[enemy_row][enemy_col] == 'v') {
		shoot_laser(map, row_size, col_size, enemy_row + 1, enemy_col, DOWN, player_row, player_col, lose);
		lose = 1;
	}
	else if (player_col < enemy_col && player_row == enemy_row && map[enemy_row][enemy_col] == '<') {
		shoot_laser(map, row_size, col_size, enemy_row, enemy_col - 1, LEFT, player_row, player_col, lose);
		lose = 1;
	}
	else if (player_col > enemy_col && player_row == enemy_row && map[enemy_row][enemy_col] == '>') {
		shoot_laser(map, row_size, col_size, enemy_row, enemy_col + 1, RIGHT, player_row, player_col, lose);
		lose = 1;
	}
}
