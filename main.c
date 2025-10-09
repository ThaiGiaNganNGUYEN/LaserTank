#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "map.h"
#include "direction.h"
#include "move.h"
#include "laser.h"
#include "copy.h"
#include "mirror.h"
#include "LinkedList.h"
#include "enemy.h"
#include "ucpSleep.h"
#include "menu.h"

#define UP '^'
#define DOWN 'v'
#define LEFT '<'
#define RIGHT '>'

int main(int argc, char *argv[]) {
	int lose = 0;
	int i;
	int row_size, col_size, player_row, player_col, enemy_row, enemy_col;
    	char player_direction, enemy_direction;
	FILE *input_file = NULL;
	char **map = NULL;
	char action;
	LinkedList *linkedlist = createLinkedList();
	if (argc != 2) {
        	printf("Usage: %s <input_file>\n", argv[0]);
        	return 1;
	}

    	input_file = fopen(argv[1], "r");
    	if (!input_file) {
        	printf("Error opening input file.\n");
        	return 1;
	}

    
    	fscanf(input_file, "%d %d", &row_size, &col_size);
    	fscanf(input_file, "%d %d %c", &player_row, &player_col, &player_direction);
	fscanf(input_file, "%d %d %c", &enemy_row, &enemy_col, &enemy_direction);
	rewind(input_file);
	
	map = create_map(row_size, col_size, player_row, player_col, player_direction, enemy_row, enemy_col, enemy_direction);
	print_mirror(map, input_file, row_size, col_size);
	print_map(map, row_size, col_size);

	if (row_size < 5 || row_size > 25 || col_size < 5 || col_size > 25) {
		printf("Invalid Map Size.");
		return 1;
	}
	if (player_row >= row_size || player_col >= col_size || enemy_row >= row_size || enemy_col >= col_size) {
		printf("Invalid Player/Enemy Position.");
		return 1;
	}

	while (map[enemy_row][enemy_col] != 'X' && map[player_row][player_col] != 'X') {
		system("clear");
		print_map(map, row_size, col_size);

		printf("w to go/face up\n");
		printf("s to go/face down\n");
		printf("a to go/face left\n");
		printf("d to go/face right\n");
		printf("f to shoot laser\n");
		printf("action: ");
		scanf(" %c", &action);

		if (action == 'f') {
			switch (map[player_row][player_col]) {
				case UP:
					shoot_laser(map, row_size, col_size, player_row - 1, player_col, UP, enemy_row, enemy_col, lose);
					break;
				case DOWN:
					shoot_laser(map, row_size, col_size, player_row + 1, player_col, DOWN, enemy_row, enemy_col, lose);
					break;
				case LEFT:
					shoot_laser(map, row_size, col_size, player_row, player_col - 1, LEFT, enemy_row, enemy_col, lose);
					break;
				case RIGHT:
					shoot_laser(map, row_size, col_size, player_row, player_col + 1, RIGHT, enemy_row, enemy_col, lose);
					break;
			}
		} else {
			move_player(map, row_size, col_size, action, &player_row, &player_col);
		}
		enemy_shoot(map, row_size, col_size, player_row, player_col, player_direction, enemy_row, enemy_col, enemy_direction, lose);
		copy_map(map, row_size, col_size, linkedlist);
	}
	if (map[enemy_row][enemy_col] == 'X') {
		system("clear");
		print_map(map, row_size, col_size);
		printf("You Win!\n");
	}
	
	if (map[player_row][player_col] == 'X') {
		system("clear");
		print_map(map, row_size, col_size);
		printf("You Lose!\n");
	}
	writeMapSequenceToFile(row_size, col_size, linkedlist);
	fclose(input_file);

	for (i = 0; i < row_size; i++) {
		free(map[i]);
	}
	free(map);
	return 0;
}
