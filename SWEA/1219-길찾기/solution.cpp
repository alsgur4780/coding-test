#include<iostream>
#include<cstdio>

using namespace std;


int dfs(int map[2][100], int num) {	// 재귀 함수
	if (num == 99) {	// 도착지에 도착한 경우 1을 반환
		return 1;
	}
	else {	// 도착지가 아닌 경우 계속 이동 (재귀)
		if (map[0][num] != 0) {	// 1번 배열 확인
			if (dfs(map, map[0][num])) {	// 재귀한 후 도착해서 1을 반환하면 1 반환
				return 1;
			}
		}
		if (map[1][num] != 0) {	// 2번 배열 확인
			if (dfs(map, map[1][num])) {	// 재귀한 후 도착해서 1을 반환하면 1 반환
				return 1;
			}
		}
	}
	return 0;	// 도착지에 도착 못한 경우 0을 반환
}

int main(int argc, char** argv)
{
	int test_case;
	//freopen("input.txt", "r", stdin);
	for (test_case = 1; test_case <= 10; test_case++)
	{
		int cnt;	// 입력 횟수
		int map[2][100] = { 0, };	// 입력을 저장할 배열 매번 0으로 초기화
		int test_num;	// 테스트 번호

		cin >> test_num;
		cin >> cnt;

		for (int i = 0; i < cnt; i++) {
			int a, b;
			cin >> a;
			cin >> b;
			if (map[0][a] == 0)	// 1번 배열이 빈 경우
				map[0][a] = b;
			else map[1][a] = b;	// 2번 배열이 빈 경우
		}
				
		printf("#%d %d\n", test_num, dfs(map, 0));	// 재귀에 넣고 출력 반환
	}
	return 0;
}
