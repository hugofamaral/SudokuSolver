//
// Created by hugod on 12/01/20.
//
#include "library.h"

/***
 * iterates the whole board looking for cells that might have the same pair as possible solutions. Deleting that pair
 * from the other cells since those must go into those cells
 * @param board
 * @return
 */
bool naked_pairs(BOARD *board) {
    CELL *current = board->pfirst;
    CELL *pline = current;

    CELL *first_pair = NULL;
    CELL *second_pair = NULL;

    int updated = 0;

    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {

            if (current->n_hints == 2) {
                first_pair = current;

                second_pair = find_second_pair(board, first_pair);

                if (second_pair != NULL) {
                    int assigned = 0;
                    if (first_pair->first_line_box == second_pair->first_line_box &&
                        first_pair->first_col_box == second_pair->first_col_box) {
                        assigned++;
                        delete_same_in_other_cells_of_box(&board, first_pair, second_pair);
                    }
                    if (first_pair->main_diagonal == true && second_pair->main_diagonal == true) {
                        assigned++;
                        delete_same_in_other_cells_of_main_diagonal(&board, first_pair, second_pair);
                    }
                    if (first_pair->secondary_diagonal == true && second_pair->secondary_diagonal == true) {
                        assigned++;
                        delete_same_in_other_cells_of_secondary_diagonal(&board, first_pair, second_pair);
                    }
                    if (first_pair->line == second_pair->line) {
                        assigned++;
                        delete_same_in_other_cells_of_line(&board, first_pair, second_pair);
                    }
                    if (first_pair->col == second_pair->col) {
                        assigned++;
                        delete_same_in_other_cells_of_col(&board, first_pair, second_pair);
                    }

                    if (assigned > 0) {
                        first_pair->num = *(first_pair->hints);
                        second_pair->num = *(second_pair->hints + 1);

                        first_pair->n_hints = 0;
                        first_pair->hints = NULL;
                        second_pair->n_hints = 0;
                        second_pair->hints = NULL;
                        updated++;
                    }
                }
            }
            current = current->east;
        }
        pline = pline->south;
        current = pline;

    }
    if (updated != 0) return true;
    else return false;

}

/***
 * finds the pair inside the box and then deletes those hints from the other boxes
 * @param board
 * @param first_pair
 * @param second_pair
 */
void delete_same_in_other_cells_of_box(BOARD **board, CELL *first_pair, CELL *second_pair) {

    BOARD *pBoard = *board;
    CELL *current = first_pair;
    CELL *pline = current;

    int ci = current->first_col_box;
    int cf = current->last_col_box;
    int li = current->first_line_box;
    int lf = current->last_line_box;
    put_current_cel_in_place(&current, current->first_line_box, current->first_col_box);
    for (int i = li; i <= lf; i++) {
        for (int j = ci; j <= cf; j++) {
            if (current->n_hints != 0) {
                if (current->line != first_pair->line && current->col != first_pair->col) {
                    if (current->line != second_pair->line && current->col != second_pair->col) {

                        for (int k = 0; k < current->n_hints; k++) {

                            if (*(current->hints + k) == *(first_pair->hints) ||
                                *(current->hints + k) == *(first_pair->hints + 1)) {
                                delete_num_from_hints(&current, k);

                            }
                        }
                    }
                }
            }
            current = current->east;
        }
        pline = pline->south;
        current = pline;
    }

    *board = pBoard;
}

/***
 * finds the pair inside the main diagonal and then deletes those hints from the other boxes
 * @param board
 * @param first_pair
 * @param second_pair
 */
void delete_same_in_other_cells_of_main_diagonal(BOARD **board, CELL *first_pair, CELL *second_pair) {

    BOARD *pBoard = *board;
    CELL *current = first_pair;

    put_current_cel_in_place(&current, 0, 0);
    for (int i = 0; i <= pBoard->size; i++) {

        if (current->n_hints != 0) {


            if (current->line != first_pair->line && current->col != first_pair->col) {
                if (current->line != second_pair->line && current->col != second_pair->col) {

                    for (int k = 0; k < current->n_hints; k++) {

                        if (*(current->hints + k) == *(first_pair->hints) ||
                            *(current->hints + k) == *(first_pair->hints + 1)) {
                            delete_num_from_hints(&current, k);
                        }
                    }
                }
            }
        }
        current = current->south_east;
    }
    *board = pBoard;
}

/***
 * finds the pair inside the secondary diagonal and then deletes those hints from the other boxes
 * @param board
 * @param first_pair
 * @param second_pair
 */
void delete_same_in_other_cells_of_secondary_diagonal(BOARD **board, CELL *first_pair, CELL *second_pair) {

    BOARD *pBoard = *board;
    CELL *current = first_pair;

    put_current_cel_in_place(&current, 0, pBoard->size - 1);
    for (int i = 0; i <= pBoard->size; i++) {

        if (current->n_hints != 0) {


            if (current->line != first_pair->line && current->col != first_pair->col) {
                if (current->line != second_pair->line && current->col != second_pair->col) {

                    for (int k = 0; k < current->n_hints; k++) {

                        if (*(current->hints + k) == *(first_pair->hints) ||
                            *(current->hints + k) == *(first_pair->hints + 1)) {
                            delete_num_from_hints(&current, k);

                        }
                    }
                }
            }
        }
        current = current->south_west;
    }
    *board = pBoard;
}

/***
 * finds the pair in the same line and then deletes those hints from the other boxes
 * @param board
 * @param first_pair
 * @param second_pair
 */
void delete_same_in_other_cells_of_line(BOARD **board, CELL *first_pair, CELL *second_pair) {

    BOARD *pBoard = *board;
    CELL *current = first_pair;

    put_current_cel_in_place(&current, current->line, 0);
    for (int i = 0; i <= pBoard->size - 1; i++) {

        if (current->n_hints != 0) {


            if (current->line != first_pair->line && current->col != first_pair->col) {
                if (current->line != second_pair->line && current->col != second_pair->col) {

                    for (int k = 0; k < current->n_hints; k++) {

                        if (*(current->hints + k) == *(first_pair->hints) ||
                            *(current->hints + k) == *(first_pair->hints + 1)) {
                            delete_num_from_hints(&current, k);

                        }
                    }
                }
            }
        }
        current = current->east;
    }
    *board = pBoard;
}

/***
 * finds the pair in the same column and then deletes those hints from the other boxes
 * @param board
 * @param first_pair
 * @param second_pair
 */
void delete_same_in_other_cells_of_col(BOARD **board, CELL *first_pair, CELL *second_pair) {

    BOARD *pBoard = *board;
    CELL *current = first_pair;

    put_current_cel_in_place(&current, 0, current->col);
    for (int i = 0; i <= pBoard->size - 1; i++) {

        if (current->n_hints != 0) {
            if (current->line != first_pair->line && current->col != first_pair->col) {
                if (current->line != second_pair->line && current->col != second_pair->col) {

                    for (int k = 0; k < current->n_hints; k++) {

                        if (*(current->hints + k) == *(first_pair->hints) ||
                            *(current->hints + k) == *(first_pair->hints + 1)) {
                            delete_num_from_hints(&current, k);

                        }
                    }
                }
            }
        }
        current = current->south;
    }
    *board = pBoard;
}

/***
 * after a pair is identified this function will try to find a matching pair
 * @param board
 * @param first_pair
 * @return
 */
CELL *find_second_pair(BOARD *board, CELL *first_pair) {

    CELL *current = first_pair->east;
    if (first_pair->line == board->size - 1 && first_pair->col == board->size - 1)
        return NULL; //If it's in the last pair and it hasn't found the pair yet there is no need to find anything
    if (current == NULL)
        current = first_pair->south;
    CELL *pline = current;


    for (int i = current->line; i < board->size; i++) {
        for (int j = current->col; j < board->size; j++) {

            if (current->n_hints == 2 && *(current->hints) == *(first_pair->hints) &&
                *(current->hints + 1) == *(first_pair->hints +
                                           1)) {
                return current;
            }
            current = current->east;
        }
        pline = pline->south;
        current = pline;
    }
    return NULL;
}

/***
 * removes the number of pairs from the cells that are not the solutions
 * @param pCel
 * @param position
 * @return
 */
void delete_num_from_hints(CELL **pCel, int value) {

    CELL *current = *pCel;
    current->n_hints = current->n_hints - 1;
    int *phints = malloc(sizeof(int) * (current->n_hints));

    int i = 0;

    for (int k = 0; k < current->n_hints; k++) {
        if (k == value) i++;
        *(phints + k) = *(current->hints + k + i);
    }

    current->hints = phints;

    *pCel = current;
}