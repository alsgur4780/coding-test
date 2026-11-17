#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int test_case;
	int T;
	// freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	int cases[8][4] = {	// 지하터널 종류
		0,0,0,0,
		1,1,1,1,	// 우하좌상 순으로 1이면 연결
		0,1,0,1,
		1,0,1,0,
		1,0,0,1,
		1,1,0,0,
		0,1,1,0,
		0,0,1,1
	};
	// 우하좌상 순서
	int dy[4] = { 0,1,0,-1 };
	int dx[4] = { 1,0,-1,0 };

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int map[55][55] = { 0, };
		int chk[55][55] = { 0, };	// 방문 확인용, 이동거리저장(소요시간)
		int N, M, R, C, L;
		int cnt = 1;	// 초기값 포함 위치의 개수
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				scanf("%d", &map[j][i]);
			}
		}
		chk[R][C] = 1;	// 초기값 방문 저장
		// 큐
		int qy[2500] = { 0, };
		int qx[2500] = { 0, };
		int qz[2500] = { 0, };
		int head = 0, tail = 0;

		// 초기값 큐 푸시
		qy[0] = R;
		qx[0] = C;
		qz[0] = map[R][C];
		tail++;

		while (head < tail) {	// 반복
			int cy = qy[head];
			int cx = qx[head];
			int cz = qz[head];
			head++;

			for (int d = 0; d < 4; d++) {	// 4방향 확인
				if (cases[cz][d]) {	// 케이스 배열에서 연결된 경우
					int ny = cy + dy[d];
					int nx = cx + dx[d];
					if (0 <= ny && ny < N && 0 <= nx && nx < M && chk[ny][nx] == 0) {	// 맵 안에 있고, 방문하지 않은 곳 인 경우
						if (cases[map[ny][nx]][(d + 2) % 4] == 1) {	// 서로 연결된 경우 큐에 푸시
							qy[tail] = ny;
							qx[tail] = nx;
							qz[tail] = map[ny][nx];
							chk[ny][nx] = chk[cy][cx] + 1;	// 이동한 거리 저장 (소요시간)
							tail++;

							if (chk[ny][nx] <= L) {	// 소요 시간이 탈출 소요 시간보다 작거나 같은 경우
								cnt++;	// 탈주범이 있을 수 있는 장소 카운트 +1
								//printf("%d %d %d \n", ny, nx, chk[ny][nx]);
							}
							else if (chk[ny][nx] > L)	// 소요시간이 큰 경우
								head = 100000000;		// 반복 종료
						}
					}
				}
			}
		}

		printf("#%d %d\n", test_case, cnt);
	}
	return 0;
}
