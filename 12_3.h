#define SIZE 4

// 전역 변수 선언
extern int board[SIZE][SIZE];
extern int score;

// 함수 선언부
void init_board();         // 보드 초기화
void print_board();        // 보드 출력
void add_random_tile();    // 랜덤 타일 생성
