#include <stdio.h>
#include <stdlib.h>
#include "laser.h"
#include "map.h"
#include "LinkedList.h"
#include "copy.h"
#include "direction.h"
#include "ucpSleep.h"

#define UP '^'
#define DOWN 'v'
#define LEFT '<'
#define RIGHT '>'

void red_laser(char **map, int row_size, int col_size, int laserX, int laserY) {
	int i;
	int j;
	for (i = 0; i < row_size; i++) {
		for (j = 0; j < col_size; j++) {
			if (i != laserX || j != laserY) {
				printf("%c", map[i][j]);
			} else {
				printf("\033[0;31m");
				printf("%c", map[i][j]);
				printf("\033[0m");
			}
		}
		printf("\n");
	}
}

void shoot_laser(char **map, int row_size, int col_size, int x, int y, char laser, int enemy_row, int enemy_col, int lose) {
	int step = (laser == UP || laser == LEFT) ? -1 : 1;
	char laser_direction = (laser == UP || laser == DOWN) ? '|' : '-';
	LinkedList *linkedlist = createLinkedList();

	while (x >= 0 && x < row_size && y >= 0 && y < col_size) {
		if (x == enemy_row && y == enemy_col) {
			map[x][y] = 'X';
			lose = 0;
			break;
		}
		else if (map[x][y] == '/' || map[x][y] == '\\') {
			if (map[x][y] == '/') {
				if (laser == UP) {
					laser = RIGHT;
					laser_direction = '-';
					step = 1;
					y = y + step;
				}
				else if (laser == DOWN) {
					laser = LEFT;
					laser_direction = '-';
					step = -1;
					y = y + step;
				}
				else if (laser == LEFT) {
					laser = DOWN;
					laser_direction = '|';
					step = 1;
					x = x + step;
				}
				else if (laser == RIGHT) {
					laser = UP;
					laser_direction ='|';
					step = -1;
					x = x + step;
				}
			}
			else if (map[x][y] == '\\') {
				if (laser == UP) {
					laser = LEFT;
					laser_direction = '-';
					step = -1;
					y = y + step;
				}
				else if (laser == DOWN) {
					laser = RIGHT;
					laser_direction = '-';
					step = 1;
					y = y + step;
				}
				else if (laser == LEFT) {
					laser = UP;
					laser_direction = '|';
					step = -1;
					x = x + step;
				}
				else if (laser == RIGHT) {
					laser = DOWN;
					laser_direction ='|';
					step = 1;
					x = x + step;
				}
			}
			continue;
		} else if (map[x][y] != ' ') {
			break;
		}
		map[x][y] = laser_direction;
		system("clear");
		red_laser(map, row_size, col_size, x, y);
		copy_map(map, row_size, col_size, linkedlist);
		ucpSleep(0.1);
		map[x][y] = ' ';
		x = (laser == UP || laser == DOWN) ? x + step : x;
		y = (laser == LEFT || laser == RIGHT) ? y + step : y;
	}
	copy_map(map, row_size, col_size, linkedlist);
}

