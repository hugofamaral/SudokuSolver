//
// Created by hugod on 28/09/2020.
//

#include "library.h"

bool pointing_pairs(BOARD *board) {
    CELL *first_hint = board->pfirst;
    CELL *pline = first_hint;
    CELL *second_hint = NULL;

    int updated = 0;
    for (int i = first_hint->line; i < board->size; i++) {
        for (int j = first_hint->col; j < board->size; j++) {
            if (first_hint->n_hints > 0) {
                for (int k = 0; k < first_hint->n_hints; k++) {
                    second_hint = find_hint_in_line_box(first_hint, *(first_hint->hints + k));
                    if (second_hint != NULL && !present_in_box(first_hint, second_hint, *(first_hint->hints + k))) {
                        if (delete_pointing_in_other_cells_of_line(&board, first_hint, second_hint,
                                                                   *(first_hint->hints + k))) {
                            printf("Pointing pair in line -[%d][%d]-[%d][%d]-> %d\n\n", first_hint->line,
                                   first_hint->col,
                                   second_hint->line, second_hint->col, *(first_hint->hints + k));
                            updated = 1;
                        }
                    }
                    second_hint = find_hint_in_col_box(first_hint, *(first_hint->hints + k));
                    if (second_hint != NULL && !present_in_box(first_hint, second_hint, *(first_hint->hints + k))) {
                        if (delete_pointing_in_other_cells_of_col(&board, first_hint, second_hint,
                                                                  *(first_hint->hints + k))) {
                            printf("Pointing pair in col -[%d][%d]-[%d][%d]-> %d\n\n", first_hint->line,
                                   first_hint->col,
                                   second_hint->line, second_hint->col, *(first_hint->hints));
                            updated = 1;
                        }
                    }
                }
            }
            first_hint = first_hint->east;
        }
        pline = pline->south;
        first_hint = pline;
    }
    if (updated != 0) {
        return true;
    } else return false;
}

CELL *find_hint_in_line_box(CELL *first_hint, int hint) {
    CELL *current = first_hint;
    put_current_cel_in_place(&current, first_hint->first_line_box, first_hint->first_col_box);

    if (first_hint->line == first_hint->last_line_box)
        return NULL; //If it's in the last position of the box and it hasn't found the second hint yet there is no need to find anything

    int li = current->first_line_box;
    int lf = current->last_line_box;

    for (int i = li; i <= lf; i++) {
        if (current->n_hints > 0) {
            for (int k = 0; k < current->n_hints; k++) {
                if (first_hint->line == current->line && first_hint->col != current->col &&
                    hint == *(current->hints + k))
                    return current;
            }
        }
        current = current->east;
    }

    return NULL;
}

CELL *find_hint_in_col_box(CELL *first_hint, int hint) {
    CELL *current = first_hint;
    put_current_cel_in_place(&current, first_hint->first_line_box, first_hint->first_col_box);


    if (first_hint->col == first_hint->last_col_box)
        return NULL; //If it's in the last position of the box and it hasn't found the second hint yet there is no need to find anything

    int ci = current->first_col_box;
    int cf = current->last_col_box;

    for (int j = ci; j <= cf; j++) {
        if (current->n_hints > 0) {
            for (int k = 0; k < current->n_hints; k++) {
                if (first_hint->col == current->col && first_hint->line != current->line &&
                    hint == *(current->hints + k))
                    return current;
            }
        }
        current = current->south;
    }
    return NULL;
}

bool present_in_box(CELL *first_hint, CELL *second_hint, int hint) {
    CELL *current = first_hint;
    put_current_cel_in_place(&current, first_hint->first_line_box, first_hint->first_col_box);
    CELL *pline = current;
    int ci = current->first_col_box;
    int cf = current->last_col_box;
    int li = current->first_line_box;
    int lf = current->last_line_box;

    for (int i = li; i <= lf; i++) {
        for (int j = ci; j <= cf; j++) {
            if (current->n_hints > 0) {
                for (int k = 0; k < current->n_hints; k++) {
                    if ((first_hint->line != current->line && second_hint->line != current->line &&
                         hint == *(current->hints + k)) ||
                        (first_hint->col != current->col && second_hint->col != current->col &&
                         hint == *(current->hints + k)))
                        return true;
                }
            }
            current = current->east;
        }
        pline = pline->south;
        current = pline;
    }
    return false;
}

bool delete_pointing_in_other_cells_of_line(BOARD **board, CELL *first_pair, CELL *second_pair, int hint) {

    BOARD *pBoard = *board;
    CELL *current = first_pair;
    bool deleted = false;

    put_current_cel_in_place(&current, current->line, 0);
    for (int i = 0; i <= pBoard->size - 1; i++) {
        if (current->n_hints != 0) {
            if ((current->line != first_pair->line || current->col != first_pair->col) &&
                (current->line != second_pair->line || current->col != second_pair->col)) {
                for (int k = 0; k < current->n_hints; k++) {
                    if (*(current->hints + k) == hint) {
                        delete_num_from_hints(&current, k);
                        deleted = true;
                    }
                }
            }
        }
        current = current->east;
    }
    *board = pBoard;
    return deleted;
}

/***
 * finds the pair in the same column and then deletes those hints from the other boxes
 * @param board
 * @param first_pair
 * @param second_pair
 */
bool delete_pointing_in_other_cells_of_col(BOARD **board, CELL *first_pair, CELL *second_pair, int hint) {

    BOARD *pBoard = *board;
    CELL *current = first_pair;
    bool deleted = false;

    put_current_cel_in_place(&current, 0, current->col);
    for (int i = 0; i <= pBoard->size - 1; i++) {
        if (current->n_hints != 0) {
            if ((current->line != first_pair->line || current->col != first_pair->col) &&
                (current->line != second_pair->line || current->col != second_pair->col)) {
                for (int k = 0; k < current->n_hints; k++) {
                    if (*(current->hints + k) == hint) {
                        delete_num_from_hints(&current, k);
                        deleted = true;
                    }
                }
            }
        }
        current = current->south;
    }
    *board = pBoard;
    return deleted;
}