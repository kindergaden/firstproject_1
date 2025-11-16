#include <stdio.h>
#include <stdlib.h>
#include "12_3.h"

int board[SIZE][SIZE];

// 보드 초기화
void init_board() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = 0;

    // 테스트용 초기 배치
    board[0][0] = 2;
    board[0][1] = 2;
    board[1][0] = 4;
    board[1][1] = 4;
}

// 보드 출력
void print_board() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    printf("---- 2048 (WASD version) ----\n\n");
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

/* -------------------------------
   왼쪽 이동 (핵심 로직)
-------------------------------- */
void move_left() {
    for (int i = 0; i < SIZE; i++) {
        int temp[SIZE] = { 0 };
        int idx = 0;

        // 0 제거하고 왼쪽으로 압축
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 0)
                temp[idx++] = board[i][j];
        }

        // 같은 숫자 합치기
        for (int j = 0; j < SIZE - 1; j++) {
            if (temp[j] != 0 && temp[j] == temp[j + 1]) {
                temp[j] *= 2;
                temp[j + 1] = 0;
                j++; // 한 번 합친 타일은 건너뛰기
            }
        }

        // 다시 압축
        int result[SIZE] = { 0 };
        idx = 0;
        for (int j = 0; j < SIZE; j++)
            if (temp[j] != 0)
                result[idx++] = temp[j];

        // 보드에 적용
        for (int j = 0; j < SIZE; j++)
            board[i][j] = result[j];
    }
}

/* 오른쪽 이동 */
void move_right() {
    for (int i = 0; i < SIZE; i++) {
        int temp[SIZE] = { 0 };
        int idx = 0;

        // 0 제거하고 오른쪽으로 압축
        for (int j = SIZE - 1; j >= 0; j--) {
            if (board[i][j] != 0)
                temp[idx++] = board[i][j];
        }

        // 합치기
        for (int j = 0; j < SIZE - 1; j++) {
            if (temp[j] != 0 && temp[j] == temp[j + 1]) {
                temp[j] *= 2;
                temp[j + 1] = 0;
                j++;
            }
        }

        // 다시 압축
        int result[SIZE] = { 0 };
        idx = 0;
        for (int j = 0; j < SIZE; j++)
            if (temp[j] != 0)
                result[idx++] = temp[j];

        // 보드 오른쪽에 반영
        for (int j = 0; j < SIZE; j++)
            board[i][j] = 0;

        for (int j = 0; j < idx; j++)
            board[i][SIZE - 1 - j] = result[j];
    }
}

/* 위로 이동 */
void move_up() {
    for (int j = 0; j < SIZE; j++) {
        int temp[SIZE] = { 0 };
        int idx = 0;

        for (int i = 0; i < SIZE; i++) {
            if (board[i][j] != 0)
                temp[idx++] = board[i][j];
        }

        for (int i = 0; i < SIZE - 1; i++) {
            if (temp[i] != 0 && temp[i] == temp[i + 1]) {
                temp[i] *= 2;
                temp[i + 1] = 0;
                i++;
            }
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

/* 아래로 이동 */
void move_down() {
    for (int j = 0; j < SIZE; j++) {
        int temp[SIZE] = { 0 };
        int idx = 0;

        for (int i = SIZE - 1; i >= 0; i--) {
            if (board[i][j] != 0)
                temp[idx++] = board[i][j];
        }

        for (int i = 0; i < SIZE - 1; i++) {
            if (temp[i] != 0 && temp[i] == temp[i + 1]) {
                temp[i] *= 2;
                temp[i + 1] = 0;
                i++;
            }
        }

        int result[SIZE] = { 0 };
        idx = 0;
        for (int i = 0; i < SIZE; i++)
            if (temp[i] != 0)
                result[idx++] = temp[i];

        // 보드에 아래쪽으로 적용
        for (int i = 0; i < SIZE; i++)
            board[i][j] = 0;

        for (int i = 0; i < idx; i++)
            board[SIZE - 1 - i][j] = result[i];
    }
}
