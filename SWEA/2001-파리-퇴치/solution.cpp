#include<iostream>
#include <cstdio>
#define NMAX 20

using namespace std;

int num[NMAX][NMAX];

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
		int max = 0;;

		cin >> N;
		cin >> M;

		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				cin >> num[j][i];
			}
		}

		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				int tmp = chk(j, i, M);
				if (tmp > max) max = tmp;
			}
		}
		printf("#%d %d\n", test_case, max);
	}
	return 0;
}
