/**@file util.h 
 * @brief Header file of util.c, tool box for the program
 */
#ifndef UTIL_H
#define UTIL_H

/** @brief Declaration of the stack structure
 *  @param x (int) coordinate of the cell
 *  @param y (int) coordinate of the cell
 *  @param next (struct *t_stack) pointer to the next element of the stack
 */
typedef struct t_stack{
    int x;
    int y;
    struct t_stack *next;
}t_stack;

/** @brief Declaration of the stack_top structure
 *  @param stack (struct *t_stack) first element of the stack
 */ 
typedef struct t_stack_top{
    struct t_stack *stack;
}t_stack_top;

/** @brief Function to stack an element of the stack
 *  @param top pointer to a struct t_stack_top type
 *  @param y (int) coordinate of the element
 *  @param x (int) coordinate of the element
 *  @return void
 */
void stack(struct t_stack_top *top, int y, int x);

/** @brief Function to unstack an element of the stack
 *  @param top pointer to a struct t_stack_top type
 *  @return void
 */


void unstack(struct t_stack_top *top);

/** @brief Function to generate a random nuber between a range of number
 *  @param min (int) min value
 *  @param max (int) max value
 *  @return int the number generated
 */
int random_number(int min, int max);

#endif