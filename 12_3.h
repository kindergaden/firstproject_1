#define SIZE 4

// 전역 변수 선언
extern int board[SIZE][SIZE];

// 함수 선언
void init_board();          // 보드 초기화
void print_board();         // 보드 출력
void move_left();           // 왼쪽 이동
void move_right();          // 오른쪽 이동
void move_up();             // 위 이동
void move_down();           // 아래 이동
