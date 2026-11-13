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
		int case_num;
		cin >> case_num;
		int map[101][103] = { 0, };
		int now_idx;
		int start[103];
		int idx = -1;
		int now_y = 99;
		for (int j = 0; j < 100; j++) {
			for (int i = 1; i <= 100; i++) {
				cin >> map[j][i];
				if (j == 0 && map[j][i] == 1) {
					idx++;
					start[idx] = i;
				}
				if (j == 99 && map[j][i] == 2)
					for (int k = 0; k <= idx; k++)
						if (start[k] == i)
							now_idx = k;
			}
		}

		while (now_y > 0) {
			if (map[now_y][start[now_idx] - 1] == 1) {
				now_idx--;
			}
			else if (map[now_y][start[now_idx] + 1] == 1) {
				now_idx++;
			}
			now_y--;
		}
		
		printf("#%d %d\n", case_num, start[now_idx] - 1);
	}
	return 0;
}
