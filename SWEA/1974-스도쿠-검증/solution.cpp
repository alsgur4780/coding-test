#include<iostream>
#include<cstdio>

using namespace std;
int map[9][9];

int chk_width() {
	for (int j = 0; j < 9; j++) {	// 가로줄 체크
		int chk[10] = { 0, };
		for (int i = 0; i < 9; i++) {
			if (chk[map[j][i]] == 0) {
				chk[map[j][i]] = 1;
			}
			else {
				return 0;
			}
		}
	}
	return 1;
}

int chk_length() {
	for (int i = 0; i < 9; i++) {	// 세로줄 체크
		int chk[10] = { 0, };
		for (int j = 0; j < 9; j++) {
			if (chk[map[j][i]] == 0) {
				chk[map[j][i]] = 1;
			}
			else {
				return 0;
			}
		}
	}
	return 1;
}

int chk_3x3() {
	for (int j = 0; j <= 6; j += 3) {
		for (int i = 0; i <= 6; i += 3) {
			int chk[10] = { 0, };
			for (int m = 0; m < 3; m++) {
				for (int n = 0; n < 3; n++) {
					if (chk[map[m + j][n + i]] == 0) {
						chk[map[m + j][n + i]] = 1;
					}
					else {
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int j = 0; j < 9; j++) {
			for (int i = 0; i < 9; i++) {
				cin >> map[j][i];
			}
		}

		printf("#%d ", test_case);
		if(chk_width() && chk_length() && chk_3x3())
			printf("%d\n", 1);
		else printf("%d\n", 0);
	}
	return 0;
}
