#ifndef LASER_H
#define LASER_H

void red_laser(char **map, int row_size, int col_size, int laserX, int laserY);
void shoot_laser(char **map, int row_size, int col_size, int laserX, int laserY, char laser, int enemy_row, int enemy_col, int lose);

#endif
