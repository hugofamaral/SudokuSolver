//
// Created by hugod on 29/09/2020.
//

#include "library.h"

bool box_reduction(BOARD *board) {
    CELL *first_hint = board->pfirst;
    CELL *pline = first_hint;
    CELL *second_hint = NULL;

    int updated = 0;
    for (int i = first_hint->line; i < board->size; i++) {
        for (int j = first_hint->col; j < board->size; j++) {
            if (first_hint->n_hints > 0) {
                for (int k = 0; k < first_hint->n_hints; k++) {
                    second_hint = find_hint_in_line_box(first_hint, *(first_hint->hints + k));
                    if (second_hint != NULL &&
                        !repeated_candidate_in_line_outside_box(board, first_hint, *(first_hint->hints + k))) {
                        if (delete_in_other_cells_of_box(first_hint, second_hint, *(first_hint->hints + k))) {
                            printf("Box reduction in line -[%d][%d]-[%d][%d]-> %d\n\n", first_hint->line,
                                   first_hint->col,
                                   second_hint->line, second_hint->col, *(first_hint->hints + k));
                            updated = 1;
                        }
                    }
                    second_hint = find_hint_in_col_box(first_hint, *(first_hint->hints + k));
                    if (second_hint != NULL &&
                        !repeated_candidate_in_col_outside_box(board, first_hint, *(first_hint->hints + k))) {
                        if (delete_pointing_in_other_cells_of_col(board, first_hint, second_hint,
                                                                  *(first_hint->hints + k))) {
                            printf("Box reduction in col -[%d][%d]-[%d][%d]-> %d\n\n", first_hint->line,
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

bool repeated_candidate_in_line_outside_box(BOARD *board, CELL *first_hint, int hint) {
    CELL *current = first_hint;
    int col = current->col;
    if (col != 0) {
        put_current_cel_in_place(&current, current->line, 0);
    }
    for (int i = 0; i < board->size; i++) {
        if (current->n_hints != 0 && current->first_col_box != first_hint->first_col_box)
            for (int k = 0; k < current->n_hints; k++) {
                if (*(current->hints + k) == hint) return true;
            }
        current = current->east;
    }
    return false;
}

bool repeated_candidate_in_col_outside_box(BOARD *board, CELL *first_hint, int hint) {
    CELL *current = first_hint;
    int line = current->line;
    if (line != 0) {
        put_current_cel_in_place(&current, 0, current->col);
    }
    for (int i = 0; i < board->size; i++) {
        if (current->n_hints != 0 && current->first_line_box != first_hint->first_line_box)
            for (int k = 0; k < current->n_hints; k++) {
                if (*(current->hints + k) == hint) return true;
            }
        current = current->south;
    }
    return false;
}

bool delete_in_other_cells_of_box(CELL *first_hint, CELL *second_hint, int hint) {
    CELL *current = first_hint;
    put_current_cel_in_place(&current, current->first_line_box, current->first_col_box);
    CELL *pline = current;
    bool deleted = false;

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
                        delete_num_from_hints(&current, hint);
                    deleted = true;
                }
            }
            current = current->east;
        }
        pline = pline->south;
        current = pline;
    }
    return deleted;
}