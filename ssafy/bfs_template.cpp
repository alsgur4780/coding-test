// SWEA 형식 + 격자 BFS 최단거리 템플릿 (VS2017 호환)
// 예: N×N 지도에서 0은 길, 1은 벽. (0,0) → (N-1,N-1) 최단 거리, 못 가면 -1

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N;
int board[100][100];
int dist[100][100];          // -1 = 아직 방문 안 함
int dr[4] = { -1, 1, 0, 0 }; // 상 하 좌 우
int dc[4] = { 0, 0, -1, 1 };

int bfs(int sr, int sc, int er, int ec) {
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    q.push({ sr, sc });
    dist[sr][sc] = 0;

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        if (r == er && c == ec) return dist[r][c];

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue; // 범위 밖
            if (board[nr][nc] == 1) continue;                     // 벽
            if (dist[nr][nc] != -1) continue;                     // 이미 방문
            dist[nr][nc] = dist[r][c] + 1;                        // 넣을 때 방문 표시!
            q.push({ nr, nc });
        }
    }
    return -1;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &board[i][j]);   // 한 줄이 "0110"처럼 붙어 있으면 %1d 사용

        printf("#%d %d\n", tc, bfs(0, 0, N - 1, N - 1));
    }
    return 0;
}
