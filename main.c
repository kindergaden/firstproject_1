#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "12_3.h"

int main() {
    srand((unsigned int)time(NULL));
    init_board();

    while (1) {
        print_board();

        printf("\nW:↑  A:←  S:↓  D:→   Q:Quit\n");
        printf("입력 > ");

        char cmd;
        scanf(" %c", &cmd);

        if (cmd == 'q' || cmd == 'Q')
            break;

        int before[SIZE][SIZE];
        // 이동 전 상태 복사
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                before[i][j] = board[i][j];

        switch (cmd) {
        case 'a': case 'A':
            move_left();
            break;

        case 'd': case 'D':
            move_right();
            break;

        case 'w': case 'W':
            move_up();
            break;

        case 's': case 'S':
            move_down();
            break;

        default:
            continue;
        }

        // 보드가 변화한 경우에만 새 타일 추가
        if (board_changed(before))
            add_random_tile();

        // 2048 달성 체크
        if (is_2048()) {
            print_board();
            printf("\n🎉 축하합니다! 2048을 만들었습니다!\n");
            break;
        }
    }

    return 0;
}
