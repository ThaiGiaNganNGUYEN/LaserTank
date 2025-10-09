#ifndef MAP_H
#define MAP_H
#include "mirror.h"

char **create_map(int row_size, int col_size, int player_row, int player_col, char player_direction, int enemy_row, int enemy_col, char enemy_direction);
void print_map(char **map, int row_size, int col_size);
void print_mirror(char **map, FILE *input_file, int row_size, int col_size);
void free_map(char **map, int row_size);

#endif
