//
// Created by hugod on 12/09/2020.
//
#include "library.h"

/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations in such a way to meet the requirements
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool BruteForce(int **grid,int size) {
    int row, col;

    // If there is no unassigned location, we are done
    if (!FindUnassignedLocation(grid, &row, &col))
        return 1; // success!
    for (int num = 1; num <= size; num++) {
        // if looks promising
        if (check_consistency(grid,size ,row, col, num)) {
            // make tentative assignment
            *(*(grid + row) + col) = num;
            //printf("Found one\n");
            // return, if success, yay!
            if (BruteForce(grid,size))
                return 1;

            // failure, unmake & try again
            //printf("Rollback\n");
            *(*(grid + row) + col) = UNASSIGNED;
        }
    }
    return 0; // this triggers backtracking
}

/* Searches the grid to find an entry that is still unassigned. If
   found, the reference parameters row, col will be set the location
   that is unassigned, and 1 is returned. If no unassigned entries
   remain, 0 is returned. */
bool FindUnassignedLocation(int **grid, int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++)
        for (*col = 0; *col < SIZE; (*col)++)
            if (*(*(grid + *row) + *col) == UNASSIGNED)
                return 1;
    return 0;
}