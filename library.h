//
// Created by hugod on 07/09/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#ifndef SUDOKUSOLVERX_LIBRARY_H
#define SUDOKUSOLVERX_LIBRARY_H


// UNASSIGNED is used for empty cells in sudoku grid
#include <stdio.h>
#include <stdbool.h>

#define UNASSIGNED 0

// N is used for the size of Sudoku grid. Size will be NxN
#define N 9

int check_consistency(int **board, int size, int line, int column, int number);

/**Aux functions for check_consistency*/
int no_repeated_number_in_line(int **board, int size, int line, int valor);

int no_repeated_number_in_column(int **board, int size, int column, int valor);

int no_repeated_number_in_box(int **board, int size, int line, int column, int valor);

int no_repeated_number_in_principal_diagonal(int **board, int size, int line, int column, int valor);

int no_repeated_number_in_secondary_diagonal(int **board, int size, int line, int column, int valor);


/***
 * generate a random board with the given range
 * @param range
 * @return
 */
int *generate_positions_in_board(int range);

/***
 * gets the column from the relative position on the board
 * @param position
 * @param size
 * @return
 */
int get_column_from_position(int position, int size);

/***
 * gets the line from the relative position on the board
 * @param position
 * @param size
 * @param column
 * @return
 */
int get_line_from_position(int position, int size, int column);


/***
 *
 * @param clues number of positions that will show as clues for solving
 * @param size
 * @return
 */
int **init_random_board(int clues, int size);

/*** Aux functions for the init_random_board*/
int **create_dyn_board(int size);

int box_if_almost_full(int **board, int size, int line, int column, int clues);

int column_is_almost_full(int **board, int size, int column);

int line_is_almost_full(int **board, int size, int column);

int number_of_numbers_allowed_in_this_position(int **board, int line, int column, int size, int *value);

void print_board(int **board, int n);

/** function to read the boards from file*/
int ***read_boards_from_txt_and_load_memory(int **size, char string[]);

/***
 *
 * @param handler
 * @param size
 * @return
 */
int **read_boards(FILE *handler, int size);

/******* functional testing *******/

#define SIZE 9
#define CLUES 40

void tests(void);

void tests_R1();

void test_R1_a();

#endif //SUDOKUSOLVERX_LIBRARY_H
