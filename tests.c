//
// Created by hugod on 09/09/2020.
//
#include "library.h"


void tests(void) {
    //tests_R1(); // board creation by random or by files
    //tests_R4(); // brute forcing boards
    //tests_R8(); // save solutions to files
    //tests_R9(); // read 1 board from file
    //tests_R10(); // read boards an load memory
    //tests_R12(); // brute force linked board
    tests_R13(); // solve board through strats
}

void tests_R1() {
    //test_R1_a(); // create random board
    test_R1_b(); // get boards from file
}

void test_R1_a() {
    int **board = init_random_board(CLUES, SIZE);
    print_board(board, SIZE);
}

void test_R1_b() {
    int *size;
    int i = 0;
    int ***boards = read_boards_from_txt_and_load_memory(&size,
                                                         "C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    while (*(size + i) != 0) {
        print_board(*(boards + i), *(size + i));
        i++;
    }
}

void tests_R4() {
    //test_R4_a_1();
    test_R4_a_2();
}

void test_R4_a_1() {
    int **board = init_random_board(CLUES, SIZE);
    if (BruteForce(board, SIZE)) {
        print_board(board, SIZE);
    } else {
        printf("\nUnsolvable ");
        print_board(board, SIZE);
    }
}

void test_R4_a_2() {
    int *size;
    int i = 0;
    int ***board = read_boards_from_txt_and_load_memory(&size,
                                                        "C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    while (*(size + i) != '\0') {
        if (BruteForce(*(board + i), *(size + i))) {
            print_board(*(board + i), *(size + i));
            i++;
        } else {
            printf("\nUnsolvable ");
            print_board(*(board + i), *(size + i));
            i++;
        }
    }
}

void tests_R8() {
    test_R8_1();
    test_R8_2();
}

void test_R8_1() {
    int *size;
    int i = 0;
    int ***board = read_boards_from_txt_and_load_memory(&size,
                                                        "C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    while (*(size + i) != '\0') {
        if (BruteForce(*(board + i), *(size + i))) {
            save_solutions_txt("C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\solutions.txt", *(board + i),
                               *(size + i));
            i++;
        } else {
            printf("\nUnsolvable ");
            print_board(*(board + i), *(size + i));
            i++;
        }
    }
}


void test_R8_2() {
    int *size;
    int i = 0;
    int ***board = read_boards_from_txt_and_load_memory(&size,
                                                        "C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    while (*(size + i) != '\0') {
        if (BruteForce(*(board + i), *(size + i))) {
            save_solutions_bin("C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\solutions.bin", *(board + i),
                               *(size + i));
            i++;
        } else {
            printf("\nUnsolvable ");
            print_board(*(board + i), *(size + i));
            i++;
        }
    }
}


void tests_R9() {
    BOARD board = read_boards_from_txt_linked("C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    print_board_linked(&board);
}

void tests_R10() {
    BOARDS boards = read_boards_from_txt_and_load_memory_linked(
            "C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    BOARD *board = boards.head;
    while (board != NULL) {
        if (strategy_solving(board)) {
            print_board_linked(board);
        } else {
            printf("\nUnsolvable ");
            print_board_linked(board);
        }
        board = board->next;
    }
}

void tests_R12() {
    BOARD board = read_boards_from_txt_linked("C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    if (bruteForce_linked(&board, board.pfirst)) {
        print_board_linked(&board);
    } else {
        printf("\nUnsolvable ");
        print_board_linked(&board);
    }
}

void tests_R13() {
    /*
    BOARD board = read_boards_from_txt_linked("C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    if (strategy_solving(&board))
        print_board_linked(&board);
    else {
        printf("\nUnsolvable ");
        print_board_linked(&board);
    }*/
    BOARDS boards = read_boards_from_txt_and_load_memory_linked(
            "C:\\Users\\hugod\\CLionProjects\\SudokuSolverX\\boards.txt");
    BOARD *board = boards.head;
    while (board != NULL) {
        print_board_linked(board);
        if (strategy_solving(board)) {
            print_board_linked(board);
        } else {
            printf("\nUnsolvable ");
            print_board_linked(board);
        }
        board = board->next;
    }
}