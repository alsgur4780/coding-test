#include <iostream>
#include <cstdio>
#define NMAX 20

using namespace std;

int num[NMAX][NMAX];

// (y, x)를 왼쪽 위로 하는 M×M 영역의 파리 합
int chk(int y, int x, int M) {
	int sum = 0;
	for (int j = y; j < y + M; j++) {
		for (int i = x; i < x + M; i++) {
			sum += num[j][i];
		}
	}
	return sum;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		int max = 0;

		cin >> N;
		cin >> M;

		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				cin >> num[j][i];
			}
		}

		// 파리채가 격자 밖으로 나가지 않도록 시작 위치는 0 ~ N-M 까지만
		for (int j = 0; j <= N - M; j++) {
			for (int i = 0; i <= N - M; i++) {
				int tmp = chk(j, i, M);
				if (tmp > max) max = tmp;
			}
		}
		printf("#%d %d\n", test_case, max);
	}
	return 0;
}
