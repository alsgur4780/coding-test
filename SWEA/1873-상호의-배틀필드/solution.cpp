#include<iostream>
#include<cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int H, W;
		cin >> H;
		cin >> W;
		char map[25][25] = { 0, };
		int dir;	// 전차 방향 (0우, 1하, 2좌, 3상)
		int y, x;	// 전차 위치

		for (int j = 0; j < H; j++) {
			for (int i = 0; i < W; i++) {
				cin >> map[j][i];
				if (map[j][i] == '>') {	// 전차의 방향과 위치 저장, 맵에서는 평지로 대체
					dir = 0;
					map[j][i] = '.';
					y = j;
					x = i;
				}
				else if (map[j][i] == 'v') {
					dir = 1;
					map[j][i] = '.';
					y = j;
					x = i;
				}
				else if (map[j][i] == '<') {
					dir = 2;
					map[j][i] = '.';
					y = j;
					x = i;
				}
				else if (map[j][i] == '^') {
					dir = 3;
					map[j][i] = '.';
					y = j;
					x = i;
				}
			}
		}

		int N;
		char sen[105] = { 0, };	// 문장을 저장할 배열

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> sen[i];
		}

		for (int i = 0; i < N; i++) {	// 문자열 크기만큼 반복
			if (sen[i] == 'U') {	// 각 뱡향에 따라 전차 방향 조정
				dir = 3;
				if (0 <= y - 1 && y - 1 < H && map[y - 1][x] == '.')	// 맵 안이고 평지일 경우 이동
					y--;
			}
			else if (sen[i] == 'D') {
				dir = 1;
				if (0 <= y + 1 && y + 1 < H && map[y + 1][x] == '.')
					y++;
			}
			else if (sen[i] == 'L') {
				dir = 2;
				if (0 <= x - 1 && x - 1 < W && map[y][x - 1] == '.')
					x--;
			}
			else if (sen[i] == 'R') {
				dir = 0;
				if (0 <= x + 1 && x + 1 < W && map[y][x + 1] == '.')
					x++;
			}
			else if (sen[i] == 'S') {	// 포탄 발사
				int ny = y;	// 현재 전차 위치 저장
				int nx = x;

				if (dir == 0) {	// 방향에 따라 포탄 이동
					while (1) {	// 무한 반복후 탈출
						nx++;
						if (nx == W)	// 맵 밖에 나간 경우
							break;
						else if (map[ny][nx] == '#')	// 강철 벽인 경우
							break;
						else if (map[ny][nx] == '*') {	// 벽돌 벽인 경우
							map[ny][nx] = '.';	// 벽 파괴 후 평지로 변경
							break;
						}
					}
				}
				else if (dir == 1) {
					while (1) {
						ny++;
						if (ny == H)
							break;
						else if (map[ny][nx] == '#')
							break;
						else if (map[ny][nx] == '*') {
							map[ny][nx] = '.';
							break;
						}
					}
				}
				else if (dir == 2) {
					while (1) {
						nx--;
						if (nx == -1)
							break;
						else if (map[ny][nx] == '#')
							break;
						else if (map[ny][nx] == '*') {
							map[ny][nx] = '.';
							break;
						}
					}
				}
				else if (dir == 3) {
					while (1) {
						ny--; 
						if (ny == -1)
							break;
						else if (map[ny][nx] == '#')
							break;
						else if (map[ny][nx] == '*') {
							map[ny][nx] = '.';
							break;
						}
					}
				}
			}
			//cout << y << x;
		}

		// 맵에 전차 출력
		if (dir == 0) map[y][x] = '>';
		else if (dir == 1) map[y][x] = 'v';
		else if (dir == 2) map[y][x] = '<';
		else if (dir == 3) map[y][x] = '^';

		cout << '#' << test_case << ' ';

		for (int j = 0; j < H; j++) {
			for (int i = 0; i < W; i++) {
				cout << map[j][i];
			}
			cout << '\n';
		}

	}
	return 0;
}
