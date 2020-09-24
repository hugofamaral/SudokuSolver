//
// Created by hugod on 22/09/2020.
//
#include "library.h"

/***
 * iterates over the whole board searching for single hints. If it finds one it will the update that cell to the hint
 * value.
 * @param board
 * @return
 */
bool single_candidate_in_cel(BOARD *board) {

    CELL *current = board->pfirst;
    CELL *pline = current;

    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (current->n_hints == 1) {
                current->num = *(current->hints);
                delete_same_in_other_cells_of_box_single(&board, current);
                if (current->main_diagonal)
                    delete_same_in_other_cells_of_main_diagonal_single(&board, current);
                if (current->secondary_diagonal)
                    delete_same_in_other_cells_of_secondary_diagonal_single(&board, current);
                delete_same_in_other_cells_of_line_single(&board, current);
                delete_same_in_other_cells_of_col_single(&board, current);
                current->n_hints = 0;
                free(current->hints);
                printf("Single solution on [%d,%d]->%d\n\n", current->line + 1, current->col + 1, current->num);
                return true;
            }
            current = current->east;
        }
        pline = pline->south;
        current = pline;
    }

    return false;
}

/***
 * iterates over the board and verifies if any of it's cells have a value that might not be present anywhere else
 * @param board
 * @return
 */
bool single_candidate_in_box_for_cel(BOARD *board) {

    CELL *current = board->pfirst;
    CELL *pline = current;
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (current->n_hints != 0) {
                for (int k = 0; k < current->n_hints; k++) {
                    if (!repeated_candidate_in_box(current, *(current->hints + k)) ||
                        !repeated_candidate_in_line(board, current, *(current->hints + k)) ||
                        !repeated_candidate_in_col(board, current, *(current->hints + k))) {
                        current->num = *(current->hints + k);
                        delete_same_in_other_cells_of_box_single(&board, current);
                        if (current->main_diagonal)
                            delete_same_in_other_cells_of_main_diagonal_single(&board, current);
                        if (current->secondary_diagonal)
                            delete_same_in_other_cells_of_secondary_diagonal_single(&board, current);
                        delete_same_in_other_cells_of_line_single(&board, current);
                        delete_same_in_other_cells_of_col_single(&board, current);
                        current->n_hints = 0;
                        free(current->hints);
                        printf("Hidden single solution on [%d,%d]->%d\n\n", current->line + 1, current->col + 1,
                               current->num);
                        return true;
                    }
                }
            }
            current = current->east;
        }
        pline = pline->south;
        current = pline;
    }
    return false;
}

/***
 * searches the other for a value that might be alone in the box. Making it the only solution for a cell
 * @param cel
 * @param number
 * @return
 */
bool repeated_candidate_in_box(CELL *cel, int number) {
    CELL *current = cel;
    put_current_cel_in_place(&current, current->first_line_box, current->first_col_box);
    CELL *pline = current;

    int ci = current->first_col_box;
    int cf = current->last_col_box;
    int li = current->first_line_box;
    int lf = current->last_line_box;

    for (int i = li; i <= lf; i++) {
        for (int j = ci; j <= cf; j++) {
            if (current->n_hints != 0 && (current->line != cel->line || current->col != cel->col))
                for (int k = 0; k < current->n_hints; k++) {
                    if (*(current->hints + k) == number)
                        return true;
                }
            current = current->east;
        }
        pline = pline->south;
        current = pline;
    }

    return false;
}

/***
 * searches the other for a value that might be alone in the line. Making it the only solution for a cell
 * @param cel
 * @param number
 * @return
 */
bool repeated_candidate_in_line(BOARD *board, CELL *cel, int number) {

    CELL *current = cel;
    int col = current->col;
    if (col != 0) {
        put_current_cel_in_place(&current, current->line, 0);
    }
    for (int i = 0; i < board->size; i++) {
        if (current->n_hints != 0 && current->col != cel->col)
            for (int k = 0; k < current->n_hints; k++) {
                if (*(current->hints + k) == number) return true;
            }
        current = current->east;
    }
    return false;
}

/***
 * searches the other for a value that might be alone in the column. Making it the only solution for a cell
 * @param cel
 * @param number
 * @return
 */
bool repeated_candidate_in_col(BOARD *board, CELL *cel, int number) {

    CELL *current = cel;
    int line = current->line;
    if (line != 0) {
        put_current_cel_in_place(&current, 0, current->col);
    }
    for (int i = 0; i < board->size; i++) {
        if (current->n_hints != 0 && current->line != cel->line)
            for (int k = 0; k < current->n_hints; k++) {
                if (*(current->hints + k) == number) return true;
            }
        current = current->south;
    }
    return false;
}

/***
 * finds the number inside the main diagonal and then deletes those hints from the other boxes
 * @param board
 * @param first_pair
 * @param second_pair
 */
void delete_same_in_other_cells_of_box_single(BOARD **board, CELL *cell) {

    BOARD *pBoard = *board;
    CELL *current = cell;

    int ci = current->first_col_box;
    int cf = current->last_col_box;
    int li = current->first_line_box;
    int lf = current->last_line_box;
    put_current_cel_in_place(&current, current->first_line_box, current->first_col_box);
    CELL *pline = current;
    for (int i = li; i <= lf; i++) {
        for (int j = ci; j <= cf; j++) {
            if (current->n_hints != 0) {
                if (current->line != cell->line && current->col != cell->col) {
                    for (int k = 0; k < current->n_hints; k++) {

                        if (*(current->hints + k) == cell->num) {
                            delete_num_from_hints(&current, k);
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
 * finds the number inside the main diagonal and then deletes those hints from the other boxes
 * @param board
 * @param first_pair
 * @param second_pair
 */
void delete_same_in_other_cells_of_main_diagonal_single(BOARD **board, CELL *cell) {

    BOARD *pBoard = *board;
    CELL *current = cell;

    put_current_cel_in_place(&current, 0, 0);
    for (int i = 0; i < pBoard->size; i++) {
        if (current->n_hints != 0) {
            if (current->line != cell->line && current->col != cell->col) {
                for (int k = 0; k < current->n_hints; k++) {

                    if (*(current->hints + k) == cell->num) {
                        delete_num_from_hints(&current, k);
                    }
                }
            }
        }
        current = current->south_east;
    }
    *board = pBoard;
}

/***
 * finds the number inside the secondary diagonal and then deletes those hints from the other boxes
 * @param board
 * @param cell
 * @param second_pair
 */
void delete_same_in_other_cells_of_secondary_diagonal_single(BOARD **board, CELL *cell) {

    BOARD *pBoard = *board;
    CELL *current = cell;

    put_current_cel_in_place(&current, 0, pBoard->size - 1);
    for (int i = 0; i < pBoard->size; i++) {
        if (current->n_hints != 0) {
            if (current->line != cell->line && current->col != cell->col) {
                for (int k = 0; k < current->n_hints; k++) {
                    if (*(current->hints + k) == cell->num) {
                        delete_num_from_hints(&current, k);

                    }
                }
            }
        }
        current = current->south_west;
    }
    *board = pBoard;
}

/***
 * finds the number in the same line and then deletes those hints from the other boxes
 * @param board
 * @param cell
 * @param second_pair
 */
void delete_same_in_other_cells_of_line_single(BOARD **board, CELL *cell) {

    BOARD *pBoard = *board;
    CELL *current = cell;

    put_current_cel_in_place(&current, current->line, 0);
    for (int i = 0; i <= pBoard->size - 1; i++) {
        if (current->n_hints != 0) {
            if (current->line == cell->line && current->col != cell->col) {
                for (int k = 0; k < current->n_hints; k++) {

                    if (*(current->hints + k) == cell->num) {
                        delete_num_from_hints(&current, k);

                    }
                }
            }
        }
        current = current->east;
    }
    *board = pBoard;
}

/***
 * finds the number in the same column and then deletes those hints from the other boxes
 * @param board
 * @param cell
 * @param second_pair
 */
void delete_same_in_other_cells_of_col_single(BOARD **board, CELL *cell) {

    BOARD *pBoard = *board;
    CELL *current = cell;

    put_current_cel_in_place(&current, 0, current->col);
    for (int i = 0; i <= pBoard->size - 1; i++) {

        if (current->n_hints != 0) {


            if (current->line != cell->line && current->col == cell->col) {
                for (int k = 0; k < current->n_hints; k++) {

                    if (*(current->hints + k) == cell->num) {
                        delete_num_from_hints(&current, k);

                    }
                }
            }
        }
        current = current->south;
    }
    *board = pBoard;
}
