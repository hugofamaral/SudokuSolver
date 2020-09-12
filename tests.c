//
// Created by hugod on 09/09/2020.
//
#include "library.h"


void tests(void) {
    //tests_R1();
    tests_R4();
}

void tests_R1() {
    //test_R1_a();
    test_R1_b();
}

void test_R1_a() {
    int **board = init_random_board(CLUES, SIZE);
    print_board(board, SIZE);
}

int **test_R1_a_1() {
    return init_random_board(CLUES, SIZE);

}

void test_R1_b() {
    int *size;
    int i = 0;
    int ***boards = read_boards_from_txt_and_load_memory(&size,
                                                         "C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    while (*(size + i) != '\0') {
        print_board(*(boards + i), *(size + i));
        i++;
    }
}

int ***test_R1_b_1() {
    int *size;
    int i = 0;
    int ***board = read_boards_from_txt_and_load_memory(&size,
                                                        "C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    return board;
}

void tests_R4() {
    test_R4_a();
}

void test_R4_a() {
    int *size;
    int ***board = read_boards_from_txt_and_load_memory(&size,
                                                        "C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    print_board(*(board), SIZE);
    if (BruteForce(*(board)) == 1)
        print_board(*(board), SIZE);
}
