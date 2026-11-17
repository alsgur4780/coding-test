#include<iostream>
#include<cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//freopen("input.txt", "r", stdin);
	for (test_case = 1; test_case <= T; ++test_case)
	{

		int map[105][105] = { 0, };
		int cnt = 0;
		int N;
		cin >> N;

		for (int j = 0; j < 100; j++) {
			for (int i = 0; i < 100; i++) {
				cin >> map[j][i];
			}
		}

		for (int i = 0; i < 100; i++) {
			int flag_N = 0, flag_S = 0;
			for (int j = 0; j < 100; j++) {
				if (map[j][i] == 1) {	// N를 만난 경우
					flag_N = 1;			// N 플래그 세움
				}
				if (flag_N == 1 && map[j][i] == 2) {	// S를 만났고 N플래그가 세워진 경우 >> 교착
					flag_S = 1;
					cnt++;
					flag_N = 0;
				}
			}
		}

		printf("#%d %d\n", test_case, cnt);
	}
	return 0;
}
