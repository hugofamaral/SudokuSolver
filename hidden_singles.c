//
// Created by hugod on 22/09/2020.
//
#include "library.h"

/***
 * iterates over the whole board searching for single hints. If it finds one it will the update that cell to the hint
 * value.
 * @param tab
 * @return
 */
bool single_candidate_in_cel(BOARD *tab) {

    CELL *current = tab->pfirst;
    CELL *pline = current;

    for (int i = 0; i < tab->size; i++) {
        for (int j = 0; j < tab->size; j++) {
            if (current->n_hints == 1) {
                current->num = *(current->hints);
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
                    if (repeated_candidate_in_box(current, *(current->hints + k) == false)) {
                        current->num = *(current->hints + k);
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

            if (current->n_hints != 0)
                for (int k = 0; k < current->n_hints; k++) {
                    if (*(current->hints + k) == number) return true;
                }
            current = current->east;
        }
        pline = pline->south;
        current = pline;
    }

    return false;
}