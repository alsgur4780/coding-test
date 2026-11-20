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
		int N;
		int cnt = 0;
		cin >> N;
		int hgt[1005] = { 0, };
		for (int j = 0; j < N; j++) {
			cin >> hgt[j];
			//if (hgt[j] != 0) hgt[j]++;
		}

		for (int j = 0; j < N; j++) {
			for (int i = 1; i <= hgt[j]; i++) {
				if (hgt[j - 2] < i && hgt[j - 1] < i && hgt[j + 1] < i && hgt[j + 2] < i)
					cnt++;
			}
		}
		cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;
}
