//
// Created by hugo on 07/09/2020.
//
#include "library.h"

int **create_dyn_board(int size) {
    int i;
    int **matrix = malloc(size * sizeof(int *));
    for (i = 0; i < size; i++) {
        *(matrix + i) = (malloc(size * sizeof(int)));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = UNASSIGNED; // colocar posicao a 0
        }
    }
    return matrix;
}

int *generate_positions_in_board(int range) {
    time_t t;
    srand((unsigned) time(&t));
    int *final = malloc(sizeof(int) * range);

    for (int i = 1; i <= range; i++) {     // fill array
        final[i - 1] = i;
    }


    for (int i = 0; i < range; i++) {    // shuffle array
        int temp = final[i];
        int randomIndex = rand() % range;
        final[i] = final[randomIndex];
        final[randomIndex] = temp;
    }

    return final;
}

int get_column_from_position(int position, int size) {
    int column = position % size;
    if (column == 0) { return size - 1; }
    else return column - 1;
}

int get_line_from_position(int position, int size, int column) {
    return ((position + size - column) / size) - 1;
}

int **init_random_board(int clues, int size) {

    int **board = create_dyn_board(size);

    int *position = generate_positions_in_board(size * size);

    int smallest = 5000;
    int pline = 0, pcolumn = 0, valor = 0;

    for (int i = 0; i < clues; i++) {
        for (int n = 0; n < size * size; n++) {


            int column = get_column_from_position(position[n], size);
            int line = get_line_from_position(position[n], size, column);

            int number;

            if (box_if_almost_full(board, size, line, column, clues) == 0 &&
                line_is_almost_full(board, size, column) == 0 && column_is_almost_full(board, size, column) == 0) {
                int n_numbers_allowed = number_of_numbers_allowed_in_this_position(board, line, column, size, &number);

                if (n_numbers_allowed > 0 && n_numbers_allowed < smallest) {
                    smallest = n_numbers_allowed;
                    pline = line;
                    pcolumn = column;
                    valor = number;
                }
            }

        }
        board[pline][pcolumn] = valor;
        smallest = 5000, pline = 0, pcolumn = 0, valor = 0;
    }
    return board;
}

int box_if_almost_full(int **board, int size, int line, int column, int clues) {
    int n = (int) sqrt(size);
    int number_of_values = 0;
    int almost_full = 0;

    if (clues < (size * size) - (9 * size)) almost_full = 9;
    else if (clues < (size * size) - (8 * size)) almost_full = 8;
    else if (clues < (size * size) - (7 * size)) almost_full = 7;
    else if (clues < (size * size) - (6 * size)) almost_full = 6;
    else if (clues < (size * size) - (5 * size)) almost_full = 5;
    else if (clues < (size * size) - (4 * size)) almost_full = 4;
    else if (clues < (size * size) - (3 * size)) almost_full = 3;
    else if (clues < (size * size) - (2 * size)) almost_full = 2;
    else if (clues < (size * size) - (1 * size)) almost_full = 1;
    else return 0;

    int li = 0, lf = 0, ci = 0, cf = 0;
    li = line - (line % n);
    lf = li + (n - 1);
    ci = column - (column % n);
    cf = ci + (n - 1);

    for (int i = li; i <= lf; i++) {
        for (int j = ci; j <= cf; j++) {

            if (board[i][j] == 0) {
                number_of_values++;

            }
        }
    }
    if (number_of_values == almost_full) return 1;
    else return 0;
}

int line_is_almost_full(int **board, int size, int line) {
    int number_of_values = 0;
    for (int i = 0; i < size; i++) {
        if (board[line][i] == 0) {
            number_of_values++;
        }
    }
    if (number_of_values == 1) return 1;
    else return 0;
}

int column_is_almost_full(int **board, int size, int column) {
    int almost_full = 1;
    int number_of_values = 0;
    for (int i = 0; i < size; i++) {
        if (board[i][column] == 0) {
            number_of_values++;
        }
    }
    if (number_of_values == almost_full) return 1;
    else return 0;
}

int number_of_numbers_allowed_in_this_position(int **board, int line, int column, int size, int *value) {
    int *numbers_possible = generate_positions_in_board(size);

    int allowed = 0;

    for (int i = 0; i < size; i++) {
        if (check_consistency(board, size, line, column, *(numbers_possible + i)) == 1) {
            if (allowed == 0) *value = *(numbers_possible + i);
            allowed++;
        }
    }
    return allowed;

}

void print_board(int **board, int n) {
    int box_size = (int) sqrt(n);
    printf("\nBoard\n");
    for (int i = 0; i < n; ++i) {
        printf("|");
        for (int j = 0; j < n; ++j) {
            if ((board[i][j] / 10) < 1) {
                printf("%d|", board[i][j]);
            } else {
                printf("%d|", board[i][j]);
            }
        }
        printf("\n");
    }
}


/*******************R2**********************/

int ***read_boards_from_txt_and_load_memory(int **size, char string[]) {
    int number_of_boards;

    int i = 0;
    int size_board;
    FILE *handler = fopen(string, "r");

    fscanf(handler, "%d", &number_of_boards);

    *size = (int*)malloc(sizeof(int)*number_of_boards);

    //variable to save boards
    int ***memory = malloc(number_of_boards * sizeof(int **));

    while (i != number_of_boards) {
        fscanf(handler, "%d", &size_board);

        *(*(size) + i) = size_board;
        *(memory + i) = read_boards(handler, size_board);
        i++;
    }
    *(size + i) = '\0';

    fclose(handler);
    return memory;
}


int **read_boards(FILE *handler, int size) {
    int **board = create_dyn_board(size);

    for (int line = 0; line < size; line++) {
        for (int column = 0; column < size; column++) {
            int numb;

            fscanf(handler, "%d", &numb);
            *(*(board + line) + column) = numb;
        }
    }
    return board;
}

