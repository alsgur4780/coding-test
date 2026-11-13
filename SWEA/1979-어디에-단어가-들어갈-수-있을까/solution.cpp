#include<iostream>
#include<cstdio>
#define NMAX 20

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		cin >> N;
		cin >> K;
		int map[NMAX][NMAX] = { 0, };
		int count = 0;
		
		for (int j = 1; j <= N; j++) {
			for (int i = 1; i <= N; i++) {
				cin >> map[j][i];
			}
		}

		for (int j = 1; j <= N; j++) {
			for (int i = 1; i <= N; i++) {
				int cnt = 0;
				if (map[j][i] == 1 && map[j][i-1] == 0) {
					for (int k = 0; k < N; k++) {
						if (map[j][i + k] == 1) {
							cnt++;
						}
						else break;
					}
				}
				if (cnt == K) count++;
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int cnt = 0;
				if (map[j][i] == 1 && map[j - 1][i] == 0) {
					for (int k = 0; k < N; k++) {
						if (map[j + k][i] == 1) {
							cnt++;
						}
						else break;
					}
				}
				if (cnt == K) count++;
			}
		}

		printf("#%d %d\n", test_case, count);
	}
	return 0;
}
