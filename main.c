#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main() {

    //client_random_board(9);
    client_read_boards_from_file();
    return 0;
}


void client_random_board(int size) {
    int **board = init_random_board(10, size);
    print_board(board, size);
}

void client_read_boards_from_file() {
    int *size;
    int i = 0;
    int ***boards = read_boards_from_txt_and_load_memory(&size,"C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    while (*(size + i) != '\0') {
        print_board(*(boards + i), *(size + i));
        i++;
    }
}

