#include <cstdio>

int N, K;
int dp[100005];     // dp[w] = 배낭 한도가 w일 때 최대 가치

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        int W, V;
        scanf("%d %d", &W, &V);
        for (int w = K; w >= W; w--) {      // 큰 가방부터 거꾸로
            if (dp[w - W] + V > dp[w])
                dp[w] = dp[w - W] + V;
        }
    }
    printf("%d", dp[K]);
    return 0;
}
