#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "12_3.h"

// 전역 변수 정의
int board[SIZE][SIZE];
int score = 0;

// 빈 칸에 랜덤하게 2 또는 4 생성
void add_random_tile() {
    int empty_cells[SIZE * SIZE][2];
    int count = 0;

    // 빈 칸 찾기
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                empty_cells[count][0] = i;
                empty_cells[count][1] = j;
                count++;
            }
        }
    }

    // 빈 칸이 있다면 랜덤한 위치에 2 또는 4 생성
    if (count > 0) {
        int r = rand() % count;
        int value = (rand() % 10 == 0) ? 4 : 2; // 10% 확률로 4
        int x = empty_cells[r][0];
        int y = empty_cells[r][1];
        board[x][y] = value;
    }
}

// 보드 초기화
void init_board() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = 0;

    add_random_tile();
    add_random_tile();
}

// 콘솔에 보드 출력
void print_board() {
    for (int i = 0; i < SIZE; i++) {
        printf("----------------------------- \n");
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                printf("|      ");
            else
                printf("|%6d", board[i][j]);
        }
        printf("|\n");
    }
    printf("----------------------------- \n");
}
