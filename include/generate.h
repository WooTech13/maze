/**@file generate.h 
 * @brief Header file of generate.c, functions for the generation of the maze
 */
#ifndef GENERATE_H
#include "../include/maze.h"
#include "../include/util.h"
#define GENERATE_H

/** @brief Enumeration for the direction to dig
 *  @param NORTH 0
 *  @param SOUTH 1
 *  @param EAST 2
 *  @param WEST 3
 */
enum direction {NORTH, SOUTH, EAST, WEST};

int is_diggable(struct t_maze *m, int y, int x, enum direction dir);

/** @brief Function to allocate memory to the maze and set all his cells to WALL
 *  @param m pointer to a struct t_maze type
 *  @param y (int) coordinate of the cell
 *  @param x (int) coordinate of the cell
 *  @param top pointer to a struct t_stack_top type
 *  @return 1 if the cell is diggable, 0 otherwise
 */
int dig(struct t_maze *m, int y, int x, struct t_stack_top *top);

/** @brief Function to generate the border of the maze, the placement of the entry, the maze's type and dig if after
 *  @param inst pointer to a struct t_instance
 *  @return void
 */
void generate_maze(struct t_instance *inst);
#endif