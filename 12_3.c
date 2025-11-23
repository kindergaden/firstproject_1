#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "12_3.h"

int board[SIZE][SIZE];

static void copy_board(int dest[SIZE][SIZE], int src[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            dest[i][j] = src[i][j];
}

int board_changed(int before[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (before[i][j] != board[i][j])
                return 1;
    return 0;
}

int is_2048() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == 2048)
                return 1;
    return 0;
}

void add_random_tile() {
    int empty[SIZE * SIZE][2];
    int count = 0;

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == 0) {
                empty[count][0] = i;
                empty[count][1] = j;
                count++;
            }

    if (count == 0) return;

    int r = rand() % count;
    int x = empty[r][0];
    int y = empty[r][1];

    int value = (rand() % 10 == 0) ? 4 : 2;  // 10% È®·ü 4
    board[x][y] = value;
}

void init_board() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = 0;

    add_random_tile();
    add_random_tile();
}

void print_board() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    printf("---- 2048 (C Version) ----\n\n");

    for (int i = 0; i < SIZE; i++) {
        printf("+------+------+------+------+ \n");
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                printf("|      ");
            else
                printf("|%6d", board[i][j]);
        }
        printf("|\n");
    }
    printf("+------+------+------+------+ \n");
}

void move_left() {
    for (int i = 0; i < SIZE; i++) {
        int temp[SIZE] = { 0 };
        int idx = 0;

        for (int j = 0; j < SIZE; j++)
            if (board[i][j] != 0)
                temp[idx++] = board[i][j];

        for (int j = 0; j < SIZE - 1; j++)
            if (temp[j] != 0 && temp[j] == temp[j + 1]) {
                temp[j] *= 2;
                temp[j + 1] = 0;
                j++;
            }

        int result[SIZE] = { 0 };
        idx = 0;
        for (int j = 0; j < SIZE; j++)
            if (temp[j] != 0)
                result[idx++] = temp[j];

        for (int j = 0; j < SIZE; j++)
            board[i][j] = result[j];
    }
}

void move_right() {
    for (int i = 0; i < SIZE; i++) {
        int temp[SIZE] = { 0 };
        int idx = 0;

        for (int j = SIZE - 1; j >= 0; j--)
            if (board[i][j] != 0)
                temp[idx++] = board[i][j];

        for (int j = 0; j < SIZE - 1; j++)
            if (temp[j] != 0 && temp[j] == temp[j + 1]) {
                temp[j] *= 2;
                temp[j + 1] = 0;
                j++;
            }

        int result[SIZE] = { 0 };
        idx = 0;
        for (int j = 0; j < SIZE; j++)
            if (temp[j] != 0)
                result[idx++] = temp[j];

        for (int j = 0; j < SIZE; j++)
            board[i][j] = 0;

        for (int j = 0; j < idx; j++)
            board[i][SIZE - 1 - j] = result[j];
    }
}

void move_up() {
    for (int j = 0; j < SIZE; j++) {
        int temp[SIZE] = { 0 };
        int idx = 0;

        for (int i = 0; i < SIZE; i++)
            if (board[i][j] != 0)
                temp[idx++] = board[i][j];

        for (int i = 0; i < SIZE - 1; i++)
            if (temp[i] != 0 && temp[i] == temp[i + 1]) {
                temp[i] *= 2;
                temp[i + 1] = 0;
                i++;
            }

        int result[SIZE] = { 0 };
        idx = 0;
        for (int i = 0; i < SIZE; i++)
            if (temp[i] != 0)
                result[idx++] = temp[i];

        for (int i = 0; i < SIZE; i++)
            board[i][j] = result[i];
    }
}

void move_down() {
    for (int j = 0; j < SIZE; j++) {
        int temp[SIZE] = { 0 };
        int idx = 0;

        for (int i = SIZE - 1; i >= 0; i--)
            if (board[i][j] != 0)
                temp[idx++] = board[i][j];

        for (int i = 0; i < SIZE - 1; i++)
            if (temp[i] != 0 && temp[i] == temp[i + 1]) {
                temp[i] *= 2;
                temp[i + 1] = 0;
                i++;
            }

        int result[SIZE] = { 0 };
        idx = 0;
        for (int i = 0; i < SIZE; i++)
            if (temp[i] != 0)
                result[idx++] = temp[i];

        for (int i = 0; i < SIZE; i++)
            board[i][j] = 0;

        for (int i = 0; i < idx; i++)
            board[SIZE - 1 - i][j] = result[i];
    }
}
