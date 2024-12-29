/** @file maze.h 
 * @brief Header file of maze.c, the main module
 */
#ifndef MAZE_H
#define MAZE_H

/** @brief Enumeration for the type of maze
 *  @param ISLAND 0
 *  @param ARBO 1
 */
enum mazeType {ISLAND, ARBO};

/** @brief Enumeration for the type of resolving of the maze
 *  @param SOLV 0
 *  @param VISIT 1
 */
enum mazeSolving {SOLV, VISIT};

/** @brief Enumeration for the type of cell
 *  @param CORRIDOR 0
 *  @param WALL 1
 *  @param BORDER 2
 *  @param ENTRY 3
 *  @param GENERATED_CORRIDOR 4
 *  @param UP 5
 *  @param DOWN 6
 *  @param LEFT 7
 *  @param RIGHT 8
 *  @param SMAX 9
 */
enum cell {CORRIDOR, WALL, BORDER, ENTRY, GENERATED_CORRIDOR, UP, DOWN, LEFT, RIGHT, SMAX};

/** @brief Declaration of the maze structure
 * @param height (int) the height of the maze
 * @param width (int) the width of the maze
 * @param cells (enum **cell) the 2D array of type
 */
typedef struct t_maze {
    int height;
    int width;
    enum cell **cells;
    enum mazeType maze_type;
}t_maze;

/** @brief Declaration of the instance structure
 *  @param m (struct t_maze) maze structure of the instance
 *  @param maze_solving (enum mazeSolving) type of resolution of this instance
 */
typedef struct t_instance {
    struct t_maze m;
    enum mazeSolving maze_solving;
}t_instance;


/** @brief Function to allocate memory to the maze and set all his cells to WALL
 *  @param m pointer to a struct t_maze type
 *  @return void
 */
void init_maze(struct t_maze *m);


/** @brief Function to free the memory allocated to the maze by the malloc function
 * @param m pointer to a struct t_maze type
 * @return void
 * */
void free_maze(struct t_maze *m);


/** @brief Function to ask maze's parameters to the user such as the height, width, type of maze
 *  @param inst pointer to a struct t_instance
 *  @return void
 */
void ask_user(struct t_instance *inst);
#endif