#include<iostream>
#include<cstdio>

using namespace std;

int map[105][105]; // 맵 0 길, 1 벽, 2 출발점, 3 도착점
int chk[105][105]; // 지나온지 확인 0 안지나감, 1 지나감

int dy[4] = { 0,1,0,-1 }; // 우하좌상 순
int dx[4] = { 1,0,-1,0 };

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int j = 0; j < 100; j++) { // chk배열 초기화
			for (int i = 0; i < 100; i++) {
				chk[j][i] = 0;
			}
		}
		int test_num;
		int sy, sx, ey, ex; // 시작점, 도착점 좌표
		cin >> test_num;

		for (int j = 0; j < 100; j++) {
			for (int i = 0; i < 100; i++) {
				scanf_s(" %1d", &map[j][i]);
				if (map[j][i] == 2) {	// 시작점 좌표 저장
					sy = j; sx = i;
				}
				else if (map[j][i] == 3) {	// 도착점 좌표 저장
					ey = j; ex = i;
				}
			}
		}

		int qy[10000] = { 0, };	// y,x 큐
		int qx[10000] = { 0, };

		int head = 0, tail = 0;
		qy[tail] = sy;	// 시작값 큐에 저장
		qx[tail] = sx;
		tail++;
		int result = 0;	// 결과
		chk[sy][sx] = 1;	// 시작점 방문

		while (head < tail) {	// bfs 탐색
			int ny = qy[head];	// 큐 팝
			int nx = qx[head];
			head++;


			if (ny == ey && nx == ex) {	// 도착점에 도착한 경우 결과 1, 반복 중단
				result = 1;
				break;
			}

			for (int d = 0; d < 4; d++) {	// 우하좌상 순서로 탐색
				int cy = ny + dy[d];
				int cx = nx + dx[d];

				if (0 <= cy && cy < 100 && 0 <= cx && cx < 100) {	// 맵 안이고
					if (map[cy][cx] != 1 && chk[cy][cx] == 0) {	// 길이며 지나오지 않은 경우
						chk[cy][cx] = 1;	// 지나옴 저장
						qy[tail] = cy;	// 큐 푸시
						qx[tail] = cx;
						tail++;
					}
				}
			}
		}


		printf("#%d %d\n", test_num, result);
	}
	return 0;

}
