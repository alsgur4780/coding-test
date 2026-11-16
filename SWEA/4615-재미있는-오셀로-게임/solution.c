#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NMAX 10


// 우측부터 시계방향으로 45도 씩
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };


int main(void)
{
	int test_case;
	int T;
	// freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		int map[NMAX][NMAX] = { 0, };	// 0 빈칸, 1 블랙, 2 화이트
		scanf("%d %d", &N, &M);
		int b = 0, w = 0;	// 블랙과 화이트 갯수 출력용

		// 초기 배치
		map[N / 2 - 1][N / 2 - 1] = 2;
		map[N / 2 - 1][N / 2] = 1;
		map[N / 2][N / 2 - 1] = 1;
		map[N / 2][N / 2] = 2;

		for (int k = 0; k < M; k++) {
			int x, y, z;	// 좌표와 돌 입력
			scanf("%d %d %d", &y, &x, &z);
			y--;	// 맵이 0부터 시작
			x--;
			map[y][x] = z;	// 좌표에 해당 돌 입력

			for (int d = 0; d < 8; d++) {	// 우측부터 시계방향으로 45도씩
				int cnt = 0;	// 사이에 상대 돌의 갯수
				int cy = y + dy[d];	// 주위의 돌 확인
				int cx = x + dx[d];
				int com;	// 상대돌 저장
				if (z == 1) com = 2;
				else if (z == 2) com = 1;

				if (0 <= cy && cy < N && 0 <= cx && cx < N && map[cy][cx] == com) {	// 맵 안이고 주위의 돌이 상대 돌인 경우
					int ny = y + dy[d];	// 상대 돌로 이동
					int nx = x + dx[d];

					while (0 <= ny && ny < N && 0 <= nx && nx < N && map[ny][nx] == com) {	// 맵 안이고 상대 돌일경우 계속 반복
						ny += dy[d];	// 계속 이동
						nx += dx[d];
						cnt++;	// 상대돌 갯수 카운트
					}
					if (0 <= ny && ny < N && 0 <= nx && nx < N && map[ny][nx] == z) {	// 맵 안이고 내 돌을 만난 경우
						for (int i = 0; i < cnt; i++) {	// 상대 돌 갯수만큼 반복
							ny -= dy[d];	// 이동
							nx -= dx[d];
							map[ny][nx] = z;	// 내 돌로 변경
						}
					}

				}
			}
		}
		// 돌 갯수 카운트
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (map[j][i] == 1)
					b++;
				else if (map[j][i] == 2)
					w++;
			}
		}
		printf("#%d %d %d\n", test_case, b, w);

	}
	return 0;
}
