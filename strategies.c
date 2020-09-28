//
// Created by hugod on 21/09/2020.
//

#include "library.h"

bool strategy_solving(BOARD *board) {
    CELL *current = board->pfirst;
    int updates;
    find_mask(board);
    print_mask(board);
    while (!complete(board,
                     &current)) { //will continue searching for updates until none are found. which will then brute force the solution
        updates = 0;
        if (single_candidate_in_cel(board)) //if there is only one possibility for a box it will be automatically placed
        {
            updates = 1;
        }
        //hidden_single on a box
        if (updates == 0)
            if (single_hidden_candidate_for_cel(board)) {
                updates = 1;
            }
        if (updates == 0)
            if (naked_pairs(board)||naked_triples(board)) {
                updates = 1;
            }
        if(updates == 0)
            if(pointing_pairs(board)){
                updates = 1;
                print_mask(board);
            }
        if (complete(board, &current) == 1) return 1;
        if (updates == 0) {
            print_board_linked(board);
            printf("\nTrying to brute force it:\n");
            if (bruteForce_linked(board, current) == 1) return 1;
            else return 0;
        }

    }
    return 1;
}

