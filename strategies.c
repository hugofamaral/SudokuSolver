//
// Created by hugod on 21/09/2020.
//

#include "library.h"

bool strategy_solving(BOARD *board)
{
    CELL * current= board->pfirst;
    int updates= 0;
    find_mask(board);
    print_mask(board);
    while (!complete(board,&current)) { //will continue searching for updates until none are found. which will then brute force the solution
        single_candidate_in_cel(board); //if there is only one possibility for a box it will be automatically placed
        updates = 0;
        print_board_linked(board);
        //hidden_single on a box
        if(single_candidate_in_box_for_cel(board))
            updates = 1;
        if(complete(board, &current) == 1) return 1;
        if(updates == 0) {
            if (bruteForce_linked(board,current)== 1) return 1;
            else return 0;
        }

    }
    return 1;
}

