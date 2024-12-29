/**@file display.h 
 * @brief Header file of display.c, functions for the display of the maze
 */
#ifndef DISPLAY_H
#include "../include/maze.h"
#include "stdint.h"
#define DISPLAY_H

/** @brief Function to choose which dislay will be displayed on the CLI
 *  @param inst pointer to a struct t_instance
 *  @return void
 */
void display_maze(struct t_instance *inst);

/** @brief Function to display the maze with number of the cells in the CLI
 *  @param m pointer to a struct t_maze type
 *  @return void
 */
void display_binary(struct t_maze *m);

/** @brief Function to display the maze with black wall and empty corridor in the CLI
 *  @param m pointer to a struct t_maze type
 *  @return void
 */
void display_unresolved(struct t_maze *m);

/** @brief Function to display the maze with black wall and arrows pointing the entry's direction in the CLI
 *  @param m pointer to a struct t_maze type
 *  @return void
 */
void display_resolved(struct t_maze *m);

/**@brief tec_string_utf8:
*  encodes a unicode codepoint into a utf8 encoded string
*  @param codepoint (uint32_t) the codepoint to be encoded into utf8
*  @param str (char *) the string where the encoded codepoint will be written to
*  you need to ensure that str has at least 5 bytes
*  4 bytes is the max length of a utf8 encoding plus NULL character
*  @return int number of bytes written (excluding NULL character)
*/
int tec_string_utf8(uint32_t codepoint, char *str);

#endif