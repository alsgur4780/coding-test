#include <iostream>
#include <cstdio>
#define NMAX 10
using namespace std;

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
		int map[NMAX][NMAX][4];  // [0] 원본, [1] 90도, [2] 180도, [3] 270도

		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				cin >> map[j][i][0];
			}
		}

		// 시계방향 90도 회전: 새 (j, i) = 이전 (N-1-i, j)
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				map[j][i][1] = map[N - i - 1][j][0];
			}
		}
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				map[j][i][2] = map[N - i - 1][j][1];
			}
		}
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				map[j][i][3] = map[N - i - 1][j][2];
			}
		}

		printf("#%d\n", test_case);
		for (int j = 0; j < N; j++) {
			for (int k = 1; k <= 3; k++) {  // 90도, 180도, 270도 순서로 한 줄에 출력
				for (int i = 0; i < N; i++) {
					printf("%d", map[j][i][k]);
				}
				printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
