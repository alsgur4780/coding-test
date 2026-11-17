#include<iostream>
#include<cstdio>

using namespace std;

int chk_max(int dump[105]) {
	int max = 0;
	int max_idx;
	for (int i = 0; i < 100; i++) {
		if (dump[i] > max) {
			max = dump[i];
			max_idx = i;
		}
	}
	return max_idx;
}
int chk_min(int dump[105]) {
	int min = 1010;
	int min_idx;
	for (int i = 0; i < 100; i++) {
		if (dump[i] < min) {
			min = dump[i];
			min_idx = i;
		}
	}
	return min_idx;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int dump[105] = { 0, };
		int cnt;
		cin >> cnt;
		for (int i = 0; i < 100; i++) {
			cin >> dump[i];
		}

		int max_idx, min_idx;

		for (int i = 0; i < cnt; i++) {
			max_idx = chk_max(dump);
			min_idx = chk_min(dump);

			dump[max_idx]--;
			dump[min_idx]++;

		}
		max_idx = chk_max(dump);
		min_idx = chk_min(dump);

		cout << "#" << test_case << " " << dump[max_idx] - dump[min_idx] << "\n";
	}
	return 0;
}
