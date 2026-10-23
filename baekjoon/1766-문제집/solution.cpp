#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[32005];   // adj[A] = A 다음에 풀어야 하는 문제들
int indeg[32005];         // 먼저 풀어야 하는 문제 수

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);   // a → b
        indeg[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;   // 최소 힙
    for (int i = 1; i <= N; i++)
        if (indeg[i] == 0) pq.push(i);   // 바로 풀 수 있는 것

    while (!pq.empty()) {
        int x = pq.top(); pq.pop();      // 가장 쉬운 것 풀기
        printf("%d ", x);
        for (int y : adj[x]) {           // x 다음 문제들
            indeg[y]--;
            if (indeg[y] == 0) pq.push(y);
        }
    }
    return 0;
}
