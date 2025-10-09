#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "mirror.h"
#include "direction.h"

char **create_map(int row_size, int col_size, int player_row, int player_col, char player_direction, int enemy_row, int enemy_col, char enemy_direction) {
	int i;
	int j;
	char **map = (char **)malloc(row_size * sizeof(char *));
	for (i = 0; i < row_size; i++) {
		map[i] = (char *)malloc(col_size * sizeof(char));
		for (j = 0; j < col_size; j++) {
			if (i == 0 || i == row_size - 1 || j == 0 || j == col_size - 1) {
				map[i][j] = '*';
			} else {
				map[i][j] = ' ';
			}
		}
	}
	
	map[player_row][player_col] = symbol(player_direction);
	map[enemy_row][enemy_col] = symbol(enemy_direction);

	return map;
}

void print_map(char **map, int row_size, int col_size) {
	int i;
	int j;
	for (i = 0; i < row_size; i++) {
		for (j = 0; j < col_size; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void print_mirror(char **map, FILE *input_file, int row_size, int col_size) {
    int mirror_row;
    int mirror_col;
    char mirror_type;

    fscanf(input_file, "%*[^\n]\n");
    fscanf(input_file, "%*[^\n]\n");
    fscanf(input_file, "%*[^\n]\n");

    while (fscanf(input_file, "%d %d %c", &mirror_row, &mirror_col, &mirror_type) != EOF) {
        if (mirror_row >= 0 && mirror_row < row_size && mirror_col >= 0 && mirror_col < col_size) {
            map[mirror_row][mirror_col] = symbol(mirror_type);
        } else {
            printf("Invalid mirror coordinates (%d, %d).\n", mirror_row, mirror_col);
        }
    }
}

void free_map(char **map, int row_size) {
	int i;
	for (i = 0; i < row_size; i++) {
		free(map[i]);
	}
	free(map);
}
