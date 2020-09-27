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
    int line, col;
    /// The cell is aware of all of it's neighbours
    struct cell *north;
    struct cell *north_east;
    struct cell *east;
    struct cell *south_east;
    struct cell *south;
    struct cell *south_west;
    struct cell *west;
} CELL;

typedef struct board {
    int size;
    CELL *pfirst;
    struct board *next;
} BOARD;

typedef struct linkedlist{
    BOARD * head;
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
int check_consistency(int **, int, int, int, int);

/**Aux functions for check_consistency*/
int no_repeated_number_in_line(int **, int, int, int);

int no_repeated_number_in_column(int **, int, int, int);

int no_repeated_number_in_box(int **, int, int, int, int);

int no_repeated_number_in_principal_diagonal(int **, int, int, int, int);

int no_repeated_number_in_secondary_diagonal(int **, int, int, int, int);

int check_if_num_possible(CELL *, BOARD *, int);

int no_repeated_num_in_line(CELL *, BOARD *, int);

int no_repeated_num_in_column(CELL *, BOARD *, int);

int no_repeated_num_in_box(CELL *, int);

int no_repeated_num_in_main_diagonal(CELL *, BOARD *, int);

int no_repeated_num_in_secondary_diagonal(CELL *, BOARD *, int);

void add_node_to_Boards(BOARDS *, BOARD *);

void put_current_cel_in_place(CELL **, int, int);

/***
 * generates random positions on the board which will later be converted into line and column so hints can be inserted before solving
 * @param range
 * @return
 */
int *generate_positions_in_board(int);

/***
 * gets the column from the relative position on the board
 * @param position
 * @param size
 * @return
 */
int get_column_from_position(int, int);

/***
 * gets the line from the relative position on the board
 * @param position
 * @param size
 * @param column
 * @return
 */
int get_line_from_position(int, int, int);


/***
 *
 * @param clues number of positions that will show as clues for solving
 * @param size
 * @return
 */
int **init_random_board(int, int);

/*** Aux functions for the init_random_board*/
int **create_dyn_board(int);

int box_if_almost_full(int **, int, int, int, int);

int column_is_almost_full(int **, int, int);

int line_is_almost_full(int **, int, int);

int number_of_numbers_allowed_in_this_position(int **, int, int, int, int *);

void print_board(int **, int);

/** function to read the boards from file*/
int ***read_boards_from_txt_and_load_memory(int **, char []);

/***
 *
 * @param handler
 * @param size
 * @return
 */
int **read_boards(FILE *, int);

/*******************BruteForce**********************/
/***
 * will attempt to solve the board by assigning a value to an empty cell while checking if it's possible.
 * If something goes wrong it will backtrack and start the process again
 * @return
 */
bool BruteForce(int **, int);

bool FindUnassignedLocation(int **, int *, int *);

bool bruteForce_linked(BOARD *, CELL *);

bool complete(BOARD *, CELL **);

/*******************R8**********************/
/* Section for file manipulation:
 * 1- save solutions to a text file
 * 2- save solutions to a bin file
*/
void save_solutions_txt(char [], int **, int);

void save_solutions_bin(char *, int **, int);

/*******************R9 onward**********************/
void init_linked_board(BOARD *);

BOARDS read_boards_from_txt_and_load_memory_linked(char []);

BOARD read_boards_from_txt_linked(char[]);

void fill_board_linked(BOARD *, int **);

void print_board_linked(BOARD *);

BOARDS *init_boards();

/******* strategy based board solving *******/

bool strategy_solving(BOARD *);

void find_mask(BOARD *);

void print_mask(BOARD *);

/******* hidden single strategy *******/

bool single_candidate_in_cel(BOARD *);

bool single_hidden_candidate_for_cel(BOARD *);

bool repeated_candidate_in_box(CELL *, int);

bool repeated_candidate_in_line(BOARD *, CELL *, int);

bool repeated_candidate_in_col(BOARD *, CELL *, int);

bool repeated_candidate_in_main_diag(BOARD *board, CELL *cel, int number);

bool repeated_candidate_in_second_diag(BOARD *board, CELL *cel, int number);

void delete_same_in_other_cells_of_box_single(BOARD **, CELL *);

void delete_same_in_other_cells_of_main_diagonal_single(BOARD **, CELL *);

void delete_same_in_other_cells_of_secondary_diagonal_single(BOARD **, CELL *);

void delete_same_in_other_cells_of_line_single(BOARD **, CELL *);

void delete_same_in_other_cells_of_col_single(BOARD **, CELL *);

/******* hidden pairs strategy *******/

bool naked_pairs(BOARD *);

bool naked_triples(BOARD *);

CELL *find_second_pair(BOARD *, CELL *);

CELL *find_second_triple(BOARD *, CELL *);

bool delete_same_in_other_cells_of_box(BOARD **, CELL *, CELL *,CELL *);

bool delete_same_in_other_cells_of_main_diagonal(BOARD **, CELL *, CELL *,CELL *);

bool delete_same_in_other_cells_of_secondary_diagonal(BOARD **, CELL *, CELL *,CELL *);

bool delete_same_in_other_cells_of_line(BOARD **, CELL *, CELL *,CELL *);

bool delete_same_in_other_cells_of_col(BOARD **, CELL *, CELL *,CELL *);

CELL * return_most_hints(CELL * first,CELL * second,CELL * third);

void delete_num_from_hints(CELL **, int);


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

void tests_R10();

void tests_R12();

void tests_R13();

#endif //SUDOKUSOLVERX_LIBRARY_H
