#include<iostream>
#include<cstdio>

using namespace std;

int sum_low(int map[55][55], int y, int front, int back) {
	int sum = 0;
	for (int i = front; i <= back; i++) {
		sum += map[y][i];
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
		int N;
		int map[55][55] = { 0, };
		int sum = 0;

		cin >> N;
		
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				scanf("%1d", &map[j][i]);
			}
		}
		int front = N / 2;
		int back = N / 2;
		int dir = 1;

		for (int j = 0; j < N; j++) {
			if (dir == 1) {
				sum += sum_low(map, j, front, back);
				front--; back++;
			}
			else if (dir == 0) {
				sum += sum_low(map, j, front, back);
				front++; back--;
			}
			if (front == 0 && back == N - 1)
				dir = 0;
		}

		printf("#%d %d\n", test_case, sum);

	}
	return 0;
}
