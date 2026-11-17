#include<iostream>
#include<cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{

		int test_num;
		cin >> test_num;

		int map[105][105] = { 0, };
		int start[105] = { 0, };
		int start_idx = 0;

		for (int j = 0; j < 100; j++) {
			for (int i = 0; i < 100; i++) {
				cin >> map[j][i];
				if (j == 0) {
					if (map[j][i] == 1) {
						start[start_idx] = i;
						start_idx++;
					}
				}
			}
		}
		int cnt_min = 10000;
		int cnt_idx;
		for (int i = 0; i < start_idx; i++) {
			int y = 0;
			int x_idx = i;
			int cnt = 0;
			while (y < 100) {
				y++;
				cnt++;
				if (0 <= start[x_idx] - 1 && start[x_idx] - 1 < 100 && map[y][start[x_idx] - 1] == 1) {
					cnt += (start[x_idx] - start[x_idx - 1]);
					x_idx--;
				}
				else if (0 <= start[x_idx] + 1 && start[x_idx] + 1 < 100 && map[y][start[x_idx] + 1] == 1) {
					cnt += (start[x_idx + 1] - start[x_idx]);
					x_idx++;
				}
			}
			if (cnt_min >= cnt) {
				cnt_min = cnt;
				cnt_idx = i;
			}
		}
		printf("#%d %d\n", test_num, start[cnt_idx]);

	}
	return 0;
}

