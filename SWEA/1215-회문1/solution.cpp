#include<iostream>
#include<cstdio>

using namespace std;


char map[8][8];	// 글자를 입력 받을 배열

int chk_wid(int j, int i, int size) {	// 가로로 확인
	for (int k = 0; k < size / 2; k++) {	// 절반 나눠서 양쪽 확인
		if (0 <= i + k && i + k < 8 && 0 <= i + size - k - 1 && i + size - k - 1 < 8) {	// 맵 안에 있고
			if (map[j][i + k] != map[j][i + size - k - 1]) {	// 양쪽 값이 다르면 0 리턴
				return 0;
			}
		}
		else return 0;
	}
	return 1;	// 회문이면 1 리턴
}

int chk_len(int j, int i, int size) {	// 세로로 확인
	for (int k = 0; k < size / 2; k++) {	// 절반 나눠서 양쪽 확인
		if (0 <= j + k && j + k < 8 && 0 <= j + size - k - 1 && j + size - k - 1 < 8) {	// 맵 안에 있고
			if (map[j + k][i] != map[j + size - k - 1][i]) {	// 양쪽 값이 다르면 0 리턴
				return 0;
			}
		}
		else return 0;
	}
	return 1;	// 회문이면 1 리턴
}

int main(int argc, char** argv)
{
	int test_case;
	//freopen("input.txt", "r", stdin);
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int cnt = 0;	// 회문 갯수 카운트
		int size;	// 회문의 길이
		cin >> size;
		
		for (int j = 0; j < 8; j++) {
			char sen[9];	// 행의 문장 입력 받음
			cin >> sen;
			for (int i = 0; i < 8; i++) {
				map[j][i] = sen[i];	// 문장에서 각 원소 추출
			}
		}

		for (int j = 0; j < 8; j++) {	// 맵 전체를 돌면서 회문확인
			for (int i = 0; i < 8; i++) {
				if (chk_wid(j, i, size))	// 가로 확인
					cnt++;
				if (chk_len(j, i, size))	// 세로 확인
					cnt++;
			}
		}

		printf("#%d %d\n", test_case, cnt);
	}
	return 0;
}
