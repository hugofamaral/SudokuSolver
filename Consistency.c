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