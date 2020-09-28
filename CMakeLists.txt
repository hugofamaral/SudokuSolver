cmake_minimum_required(VERSION 3.17)
project(SudokuSolverX C)

set(CMAKE_C_STANDARD 99)

add_executable(SudokuSolverX main.c library.h Helpers.c Consistency.c tests.c BruteForce.c FileManip.c strategies.c hidden_singles.c naked_pairs.c pointing_pairs.c)