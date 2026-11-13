#include <iostream>
#include <cstdio>
#define NMAX 15

using namespace std;

// 오른쪽 → 아래 → 왼쪽 → 위 (시계방향)
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		int x = 0, y = 0;
		int d = 0;

		int map[NMAX][NMAX] = { 0, };  // 케이스마다 새로 0으로 초기화

		for (int i = 1; i <= N * N; i++) {
			map[y][x] = i;
			int cy = y + dy[d];
			int cx = x + dx[d];
			// 다음 칸이 범위 안이고 비어 있으면 그대로 진행
			if (0 <= cy && cy < N && 0 <= cx && cx < N && map[cy][cx] == 0) {
				y = cy;
				x = cx;
			}
			// 벽이거나 이미 채운 칸이면 방향 전환
			else {
				d = (d + 1) % 4;
				y = y + dy[d];
				x = x + dx[d];
			}
		}

		printf("#%d\n", test_case);
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				printf("%d ", map[j][i]);
			}
			printf("\n");
		}
	}
	return 0;
}
