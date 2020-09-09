//
// Created by hugod on 09/09/2020.
//
#include "library.h"




void tests(void) {
    tests_R1();
}

void tests_R1() {
    test_R1_a();
}

void test_R1_a() {
    int **board = init_random_board(CLUES, SIZE);
    print_board(board, SIZE);
}
