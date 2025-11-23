#define SIZE 4

extern int board[SIZE][SIZE];

// 함수 선언
void init_board();          // 보드 초기화
void print_board();         // 보드 출력
void add_random_tile();     // 빈 칸에 랜덤 숫자 추가

// 이동 함수
void move_left();
void move_right();
void move_up();
void move_down();

// 검사 함수
int is_2048();              // 2048 달성 여부 체크
int board_changed(int before[SIZE][SIZE]);  // 이동 여부 체크