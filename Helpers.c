#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-msc51-cpp"
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
            matrix[i][j] = UNASSIGNED;
        }
    }
    return matrix;
}

/***
 * Using the current time as a randomizer to get positions on the board
 * @param range number of available cells on the board (ex.:9x9 = 81 possible positions)
 * @return
 */
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
    int pline = 0, pcolumn = 0, value = 0;

    for (int i = 0; i < clues; i++) {
        for (int n = 0; n < size * size; n++) {
            int column = get_column_from_position(position[n],
                                                  size); // positions are randomized through generate_positions_in_board
            int line = get_line_from_position(position[n], size,
                                              column); // positions are randomized through generate_positions_in_board
            int number;

            if (box_if_almost_full(board, size, line, column, clues) == 0 &&
                line_is_almost_full(board, size, column) == 0 && column_is_almost_full(board, size, column) == 0) {
                int n_numbers_allowed = number_of_numbers_allowed_in_this_position(board, line, column, size, &number);
                if (n_numbers_allowed > 0 && n_numbers_allowed < smallest) {
                    smallest = n_numbers_allowed;
                    pline = line;
                    pcolumn = column;
                    value = number;
                }
            }

        }
        board[pline][pcolumn] = value;
        smallest = 5000, pline = 0, pcolumn = 0, value = 0;
    }
    return board;
}

int box_if_almost_full(int **board, int size, int line, int column, int clues) {
    int n = (int) sqrt(size);
    int number_of_values = 0;
    int almost_full = 0;

    for (int i = size; i >= 0; i--) {
        if (i == 0)
            return 0;
        if (clues < (size * size) - (i * size)) {
            almost_full = i;
            break;
        }
    }

    int li, lf, ci, cf;
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
        if (i % box_size == 0)printf("\n");
        printf("|");
        for (int j = 0; j < n; ++j) {
            if (j % box_size == 0)printf(" ");
            if ((board[i][j] / 10) < 1) {
                printf("%d  ", board[i][j]);
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("|\n");
    }
}


/*******************R2**********************/

int ***read_boards_from_txt_and_load_memory(int **size, char string[]) {
    int number_of_boards;

    int i = 0;
    int size_board;
    FILE *handler = fopen(string, "r");

    fscanf(handler, "%d", &number_of_boards);

    *size = (int *) malloc(sizeof(int) * number_of_boards);

    //variable to save boards
    int ***memory = malloc(number_of_boards * sizeof(int **));

    while (i != number_of_boards) {
        fscanf(handler, "%d", &size_board);

        *(*(size) + i) = size_board;
        *(memory + i) = read_boards(handler, size_board);
        i++;
    }
    *(size + i) = 0;

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

/*******************R9**********************/

void init_linked_board(BOARD *board) {

    int n = (int) sqrt(board->size);
    CELL *current = malloc(sizeof(CELL)), *prevLine, *prevCol;
    board->pfirst = current;
    prevCol = board->pfirst;
    prevLine = board->pfirst;

    for (int line = 0; line < board->size; ++line) {
        for (int col = 0; col < board->size; ++col) {


            if (line == 0 && col == 0) {
                current->main_diagonal = 1;
                current->secondary_diagonal = 0;
                current->num = 0;
                current->n_hints = 0;
                current->first_line_box = line - (line % n);
                current->first_col_box = col - (col % n);
                current->last_line_box = current->first_line_box + (n - 1);
                current->last_col_box = current->first_col_box + (n - 1);

                current->line = line;
                current->col = col;
                current->north = NULL;
                current->north_east = NULL;
                current->east = malloc(sizeof(CELL));
                current->south_east = malloc(sizeof(CELL));
                current->south = malloc(sizeof(CELL));
                current->south_west = NULL;
                current->west = NULL;
            }
            if (line == 0 && col != 0 && col != board->size - 1) {
                current->main_diagonal = 0;
                current->secondary_diagonal = 0;
                current->num = 0;
                current->n_hints = 0;
                current->first_line_box = line - (line % n);
                current->first_col_box = col - (col % n);
                current->last_line_box = current->first_line_box + (n - 1);
                current->last_col_box = current->first_col_box + (n - 1);
                current->line = line;
                current->col = col;
                current->north = NULL;
                current->north_east = NULL;
                current->east = malloc(sizeof(CELL));
                current->south_east = malloc(sizeof(CELL));
                current->south = prevCol->south_east;
                current->south_west = prevCol->south;
                current->west = prevCol;
            }
            if (line == 0 && col == board->size - 1) {
                current->main_diagonal = 0;
                current->secondary_diagonal = 1;
                current->num = 0;
                current->n_hints = 0;
                current->first_line_box = line - (line % n);
                current->first_col_box = col - (col % n);
                current->last_line_box = current->first_line_box + (n - 1);
                current->last_col_box = current->first_col_box + (n - 1);
                current->line = line;
                current->col = col;
                current->north = NULL;
                current->north_east = NULL;
                current->east = NULL;
                current->south_east = NULL;
                current->south = prevCol->south_east;
                current->south_west = prevCol->south;
                current->west = prevCol;
            }
            if (line != 0 && col == 0 && line != board->size - 1) {
                current->main_diagonal = 0;
                current->secondary_diagonal = 0;
                current->num = 0;
                current->n_hints = 0;
                current->first_line_box = line - (line % n);
                current->first_col_box = col - (col % n);
                current->last_line_box = current->first_line_box + (n - 1);
                current->last_col_box = current->first_col_box + (n - 1);
                current->line = line;
                current->col = col;
                current->north = prevLine;
                current->north_east = prevLine->east;
                current->east = prevLine->south_east;
                current->south_east = malloc(sizeof(CELL));
                current->south = malloc(sizeof(CELL));
                current->south_west = NULL;
                current->west = NULL;
            }
            if (line != 0 && col != 0 && col != board->size - 1) {
                if (line == col) {
                    current->main_diagonal = 1;
                } else { current->main_diagonal = 0; }

                if (line == board->size - 1 - col) {
                    current->secondary_diagonal = 1;
                } else { current->secondary_diagonal = 0; }

                current->num = 0;
                current->n_hints = 0;
                current->first_line_box = line - (line % n);
                current->first_col_box = col - (col % n);
                current->last_line_box = current->first_line_box + (n - 1);
                current->last_col_box = current->first_col_box + (n - 1);
                current->line = line;
                current->col = col;
                current->north = prevCol->north_east;
                current->north_east = prevCol->north_east->east;
                current->east = prevCol->north_east->south_east;
                current->south_east = malloc(sizeof(CELL));
                current->south = prevCol->south_east;
                current->south_west = prevCol->south;
                current->west = prevCol;
            }
            if (line != 0 && col != 0 && col == board->size - 1) {
                current->main_diagonal = 0;
                current->secondary_diagonal = 0;
                current->num = 0;
                current->n_hints = 0;
                current->first_line_box = line - (line % n);
                current->first_col_box = col - (col % n);
                current->last_line_box = current->first_line_box + (n - 1);
                current->last_col_box = current->first_col_box + (n - 1);
                current->line = line;
                current->col = col;
                current->north = prevCol->north_east;
                current->north_east = NULL;
                current->east = NULL;
                current->south_east = NULL;
                current->south = prevCol->south_east;
                current->south_west = prevCol->south;
                current->west = prevCol;
            }
            if (line == board->size - 1 && col == 0) {
                current->main_diagonal = 0;
                current->secondary_diagonal = 1;
                current->num = 0;
                current->n_hints = 0;
                current->first_line_box = line - (line % n);
                current->first_col_box = col - (col % n);
                current->last_line_box = current->first_line_box + (n - 1);
                current->last_col_box = current->first_col_box + (n - 1);
                current->line = line;
                current->col = col;
                current->north = prevLine;
                current->north_east = prevLine->east;
                current->east = prevLine->south_east;
                current->south_east = NULL;
                current->south = NULL;
                current->south_west = NULL;
                current->west = NULL;
            }
            if (line == board->size - 1 && col != 0 && col != board->size - 1) {
                current->main_diagonal = 0;
                current->secondary_diagonal = 0;
                current->num = 0;
                current->n_hints = 0;
                current->first_line_box = line - (line % n);
                current->first_col_box = col - (col % n);
                current->last_line_box = current->first_line_box + (n - 1);
                current->last_col_box = current->first_col_box + (n - 1);
                current->line = line;
                current->col = col;
                current->north = prevCol->north_east;
                current->north_east = prevCol->north_east->east;
                current->east = prevCol->north_east->south_east;
                current->south_east = NULL;
                current->south = NULL;
                current->south_west = NULL;
                current->west = prevCol;
            }
            if (line == board->size - 1 && col != 0 && col == board->size - 1) {
                current->main_diagonal = 1;
                current->secondary_diagonal = 0;
                current->num = 0;
                current->n_hints = 0;
                current->first_line_box = line - (line % n);
                current->first_col_box = col - (col % n);
                current->last_line_box = current->first_line_box + (n - 1);
                current->last_col_box = current->first_col_box + (n - 1);
                current->line = line;
                current->col = col;
                current->north = prevCol->north_east;
                current->north_east = NULL;
                current->east = NULL;
                current->south_east = NULL;
                current->south = NULL;
                current->south_west = NULL;
                current->west = prevCol;
            }
            prevCol = current;
            current = current->east;
        }
        if (line >= 1) {
            prevLine = prevLine->south;
        }

        current = prevLine->south;
    }

}

BOARD read_boards_from_txt_linked(char string[]) {
    int size_board;
    FILE *handler = fopen(string, "r");

    fscanf(handler, "%d");

    int **pointer_board;

    BOARD board = {0, NULL};
    fscanf(handler, "%d", &size_board);

    board.size = size_board;

    init_linked_board(&board);
    pointer_board = read_boards(handler, size_board);

    fill_board_linked(&board, pointer_board);
    free(pointer_board);

    fclose(handler);
    return board;
}

BOARDS read_boards_from_txt_and_load_memory_linked(char string[]) {
    int number_of_boards;
    int i = 0;
    int size_board;
    FILE *handler = fopen(string, "r");

    fscanf(handler, "%d", &number_of_boards);

    BOARDS *boards = init_boards();
    int **pointer_board;

    while (i != number_of_boards) {
        fscanf(handler, "%d", &size_board);

        BOARD *board = malloc(sizeof(BOARD));
        board->size = size_board;
        init_linked_board(board);
        pointer_board = read_boards(handler, size_board);

        fill_board_linked(board, pointer_board);
        add_node_to_Boards(boards, board);
        i++;
        free(pointer_board);
    }

    fclose(handler);
    return *boards;
}

void fill_board_linked(BOARD *board, int **pointer_board) {

    CELL *current, *pline;
    pline = board->pfirst;
    current = board->pfirst;
    for (int line = 0; line < board->size; ++line) {
        for (int col = 0; col < board->size; ++col) {
            current->num = *(*(pointer_board + line) + col);
            current = current->east;
        }
        pline = pline->south;
        current = pline;
    }

}

void print_board_linked(BOARD *board) {
    int n = (int) sqrt(board->size);

    if (board != NULL) {
        printf("Board:\n");
        CELL *current, *pline;
        pline = board->pfirst;
        current = board->pfirst;
        for (int line = 0; line < board->size; ++line) {
            if (line % n == 0)printf("\n");
            printf("|");
            for (int col = 0; col < board->size; ++col) {
                if (col % n == 0)printf(" ");
                if ((current->num / 10) < 1) {
                    printf("%d  ", current->num);
                } else {
                    printf("%d ", current->num);
                }
                current = current->east;

            }

            printf("|\n");
            pline = pline->south;
            current = pline;
        }
    } else {
        printf("No board!\n");
    }
}

void add_node_to_Boards(BOARDS *boards, BOARD *board) {

    if ((boards == NULL) || (board == NULL)) {
        return;
    }
    board->next = NULL;
    if (boards->size == 0) {
        boards->head = board;
        boards->head->next = NULL;
        boards->head->size = board->size;
        boards->head->pfirst = board->pfirst;
        boards->size++;
        return;
    }
    BOARD * current = boards->head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = board;
    current->next->size = board->size;
    current->next->pfirst = board->pfirst;
    boards->size++;
}

BOARDS *init_boards() {
    BOARDS *pLinkedlist = (BOARDS *) malloc(sizeof (BOARDS));
    if (pLinkedlist == NULL) {
        return NULL;
    }

    pLinkedlist->size = 0;
    pLinkedlist->head = NULL;
    pLinkedlist->head = NULL;

    return pLinkedlist;
}

void find_mask(BOARD *board) {
    if (board != NULL) {
        CELL *current, *pline;
        pline = board->pfirst;
        current = board->pfirst;

        for (int line = 0; line < board->size; ++line) {
            for (int col = 0; col < board->size; ++col) {
                if (current->n_hints != 0) {
                    free(current->hints);
                    current->n_hints = 0;
                }
                if (current->num == 0) {
                    for (int k = 1; k <= board->size; k++) {
                        if (check_if_num_possible(current, board, k) == 1) {
                            if (current->n_hints == 0) {
                                current->hints = (int *) malloc(sizeof(int));
                                *(current->hints) = k;
                                current->n_hints++;
                            } else {
                                current->hints = realloc((current->hints), sizeof(int) * (current->n_hints + 1));
                                *(current->hints +
                                  current->n_hints) = k;
                                current->n_hints++;
                            }

                        }
                    }
                }
                current = current->east;
            }
            pline = pline->south;
            current = pline;
        }
    }
}

void print_mask(BOARD *board) {
    CELL *current = board->pfirst;
    CELL *pline = board->pfirst;
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            printf("[%d,%d]-> ", current->line, current->col);
            if (current->num != 0) {
                printf("Number: %d ", current->num);
            } else {
                printf("Number of possibilities: %d: ", current->n_hints);

                for (int k = 0; k < current->n_hints; k++) {
                    printf("%d ", *(current->hints + k));

                }
            }
            printf("\n");
            current = current->east;
        }
        pline = pline->south;
        current = pline;
        printf("\n");
    }
}