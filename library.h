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
#define linked_lists 1

typedef struct cell {
    int first_line_box;
    int first_col_box;
    int last_line_box;
    int last_col_box;
    int main_diagonal; // indicates whether cell belongs to main diagonal or not (0-no;1-yes)
    int secondary_diagonal; // indicates whether cell belongs to main diagonal or not (0-no;1-yes)
    int num;
    int *hints; // possible numbers for a cell
    int n_hints;
    int line,col;
    /// The cell is aware of all of it's neighbours
    struct cell *north;
    struct cell *north_east;
    struct cell *east;
    struct cell *south_east;
    struct cell *south;
    struct cell *south_west;
    struct cell *west;
    struct cell *north_west;
} CELL;

typedef struct board {
    int size;
    CELL *pfirst;
    struct board *prev;
} BOARD;

typedef struct linkedBoards{
    BOARD * head;
    BOARD * tail;
    BOARD * current;
    int size;
}BOARDS;


/***
 * Consistency functions. Will check if the board is okay. If a number can be inserted in a cell or not
 * */

 /***
  *
  * @param board
  * @param size
  * @param line
  * @param column
  * @param number
  * @return
  */
int check_consistency(int **board, int size, int line, int column, int number);

/**Aux functions for check_consistency*/
int no_repeated_number_in_line(int **board, int size, int line, int valor);

int no_repeated_number_in_column(int **board, int size, int column, int valor);

int no_repeated_number_in_box(int **board, int size, int line, int column, int valor);

int no_repeated_number_in_principal_diagonal(int **board, int size, int line, int column, int valor);

int no_repeated_number_in_secondary_diagonal(int **board, int size, int line, int column, int valor);


/***
 * generates random possitions on the board which will later be converted into line and column so hints can be inserted before solving
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

/*******************BruteForce**********************/
/***
 * will attempt to solve the board by assigning a value to an empty cell while checking if it's possible.
 * If something goes wrong it will backtrack and start the process again
 * @return
 */
bool BruteForce(int **, int size);

bool FindUnassignedLocation(int **, int *, int *);

/*******************R8**********************/
/* Section for file manipulation:
 * 1- save solutions to a text file
 * 2- save solutions to a bin file
*/
void save_solutions_txt(char string[], int ** solution, int size);

void save_solutions_bin(char *string, int **solution, int size);

/*******************R9**********************/
void init_linked_board(BOARD *board);

BOARDS read_boards_from_txt_and_load_memory_linked(int **size, char string[]);

BOARD read_boards_from_txt_linked(int **, char[]);

void fill_board_linked(BOARD *, int **);

int add_node_to_Boards(BOARDS *boards, BOARD *board);

void print_board_linked(BOARD *tab);

BOARDS *init_Boards();
/******* functional testing *******/

#define SIZE 9
#define  CLUES 60

void tests(void);

void tests_R1();

void test_R1_a();

void test_R1_b();

void tests_R4();

void test_R4_a_1();

void test_R4_a_2();

void tests_R8();

void test_R8_1();

void test_R8_2();

void tests_R9();

#endif //SUDOKUSOLVERX_LIBRARY_H
