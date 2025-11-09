#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "12_3.h"  // 함수 선언 포함

int main() {
    srand((unsigned int)time(NULL));  // 랜덤 시드 초기화

    init_board();    // 보드 초기화
    print_board();   // 초기 보드 출력

    printf("\n보드가 정상적으로 초기화되었습니다!\n");
    printf("아무 키나 누르면 종료됩니다.\n");
    getchar();  // 콘솔 종료 방지용
    return 0;
}
