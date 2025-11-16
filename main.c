#include <stdio.h>
#include "12_3.h"

int main() {
    init_board();

    while (1) {
        print_board();

        printf("\nW: Up, A: Left, S: Down, D: Right, Q: Quit\n");
        printf("입력 > ");

        char cmd;
        scanf(" %c", &cmd);

        if (cmd == 'q' || cmd == 'Q')
            break;

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
            printf("잘못된 입력입니다.\n");
            break;
        }
    }

    return 0;
}
