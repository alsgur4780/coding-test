#include<iostream>
#include<cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	for (test_case = 1; test_case <= 10; ++test_case)
	{

		int map[105][105] = { 0, };
		int test_num;
		cin >> test_num;

		for (int j = 0; j < 100; j++) {
			for (int i = 0; i < 100; i++) {
				cin >> map[j][i];
			}
		}
		int sum_max = 0;
		int sum = 0;

		for (int j = 0; j < 100; j++) {	// 가로로 더함
			sum = 0;
			for (int i = 0; i < 100; i++) {
				sum += map[j][i];
			}
			if (sum > sum_max)
				sum_max = sum;
		}

		for (int j = 0; j < 100; j++) {	// 세로로 더함
			sum = 0;
			for (int i = 0; i < 100; i++) {
				sum += map[i][j];
			}
			if (sum > sum_max)
				sum_max = sum;
		}
		sum = 0;
		for (int j = 0; j < 100; j++) {	// 우하대각선
			sum += map[j][j];
		}
		if (sum > sum_max)
			sum_max = sum;
		sum = 0;
		for (int j = 0; j < 100; j++) {	// 우상대각선
			sum += map[j][99 - j];
		}
		if (sum > sum_max)
			sum_max = sum;
		
		cout << "#" << test_num << " " << sum_max << "\n";
	}
	return 0;
}
