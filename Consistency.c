//
// Created by hugod on 07/09/2020.
//

#include "library.h"
int check_consistency(int **board, int size, int line, int column , int number ){
    if(board[line][column] == 0) {
        if (no_repeated_number_in_line(board, size, line, number) == 1 &&
            no_repeated_number_in_box(board, size, line, column, number) == 1 &&
            no_repeated_number_in_column(board, size, column, number) == 1 &&
            no_repeated_number_in_principal_diagonal(board, size, line, column, number) == 1 &&
            no_repeated_number_in_secondary_diagonal(board, size, line, column, number) == 1)
        {
            return 1;
        } else return 0;
    }else return 0;
}

int no_repeated_number_in_line(int **board, int size,int line, int value){

    for (int i = 0; i < size ; i++) {
        if(board[line][i] == value){
            return 0;
        }
    }
    return 1;
}

int no_repeated_number_in_column(int **board, int size,int column, int value){

    for (int i = 0; i < size ; i++) {
        if(board[i][column] == value){
            return 0;
        }
    }
    return 1;
}

int no_repeated_number_in_box(int **board, int size, int line, int column, int value){
    int n =(int)sqrt(size);

    int li , lf , ci, cf;
    li = line - (line % n);
    lf = li + (n - 1);
    ci = column - (column % n);
    cf = ci + (n - 1);

    for (int i = li; i <= lf ; i++) {
        for (int j = ci; j <= cf ; j++) {

            if(board[i][j] == value){
                return 0;
            }
        }
    }
    return 1;
}

int no_repeated_number_in_principal_diagonal(int **board,int size, int line, int column , int value){
    int j=0;
    if(line != column){ //cell doesn't belong to the main diagonal
        return 1;
    }else {
        for (int i = 0; i < size; i++) {

            if (board[i][j] == value) {
                return 0;
            }
            j++;
        }
        return 1;
    }
}

int no_repeated_number_in_secondary_diagonal(int **board ,int size, int line, int column, int value){
    int j= size -1;
    if(line != size-1-column || column != size-1-line){ // doesn't belong to secondary diagonal
        return 1;
    } else{

        for (int i = 0; i < size; i++) {
            if(board[i][j] == value) {
                return 0;
            }
            j--;
        }
        return 1;
    }
}

int check_if_num_possible(CELL *cell, BOARD *board, int num) {
    if (cell->num == 0) {
        if (no_repeated_num_in_line(cell, board, num) == 1 &&
            no_repeated_num_in_box(cell, num) == 1 &&
            no_repeated_num_in_column(cell, board, num) == 1 &&
            no_repeated_num_in_main_diagonal(cell, board, num) == 1 &&
            no_repeated_num_in_secondary_diagonal(cell, board, num) == 1) {
            return 1;
        } else return 0;
    } else return 0;
}


int no_repeated_num_in_line(CELL *ref, BOARD *board, int num) {

    CELL *current = ref;
    int col = current->col;
    if (col != 0) {
        put_current_cel_in_place(&current, current->line, 0);
    }

    for (int i = 0; i < board->size; i++) {
        if (current->num == num) {
            return 0;
        }
        current = current->east;
    }
    return 1;
}


int no_repeated_num_in_column(CELL *ref, BOARD *board, int num) {
    CELL *current = ref;
    int line = current->line;
    if (line != 0) {
        put_current_cel_in_place(&current, 0, current->col);
    }
    for (int i = 0; i < board->size; i++) {
        if (current->num == num) {
            return 0;
        }
        current = current->south;
    }
    return 1;
}


int no_repeated_num_in_box(CELL  *ref, int num) {
    CELL *current = ref;

    int ci = current->first_col_box;
    int cf = current->last_col_box;
    int li = current->first_line_box;
    int lf = current->last_line_box;

    if (current->line != current->first_line_box ||
        current->col != current->first_col_box) {
        put_current_cel_in_place(&current, current->first_line_box, current->first_col_box);
    }
    CELL *line = current;

    for (int i = li; i <= lf; i++) {
        for (int j = ci; j <= cf; j++) {

            if (current->num == num) {
                return 0;
            }
            current = current->east;
        }
        line = line->south;
        current = line;
    }
    return 1;
}


int no_repeated_num_in_main_diagonal(CELL *ref, BOARD *board, int num) {
    CELL *current = ref;

    if (current->main_diagonal == 0) {
        return 1;
    } else {
        current = board->pfirst;
        for (int i = 0; i < board->size; i++) {
            if (current->num == num) {
                return 0;
            }
            current = current->south_east;
        }
        return 1;
    }
}

int no_repeated_num_in_secondary_diagonal(CELL *ref, BOARD *board, int num) {
    CELL *current = ref;

    if (current->secondary_diagonal == 0) {
        return 1;
    } else {
        current = board->pfirst;
        put_current_cel_in_place(&current, 0, board->size - 1);
        for (int i = 0; i < board->size; i++) {
            if (current->num == num) {
                return 0;
            }
            current = current->south_west;
        }
        return 1;
    }
}

void put_current_cel_in_place(CELL **current, int line, int col){

    CELL *cel = *current;

    while(cel->line != line){
        if(line > cel->line){
            cel = cel->south;
        } else{
            cel = cel->north;
        }
    }
    while(cel->col != col){
        if(col > cel->col){
            cel = cel->east;
        }else {
            cel = cel->west;
        }
    }
    *current = cel;
}

