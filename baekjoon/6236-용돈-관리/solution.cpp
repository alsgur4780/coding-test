#include <cstdio>

int N, M;
int money[100005];

// K원씩 뽑을 때 인출 횟수
int count(int k) {
    int now_money = k;
    int cnt = 1;                            // 처음에 1번 뽑고 시작
    for (int i = 0; i < N; i++) {
        if (money[i] <= now_money) {        // 지갑 돈으로 충분
            now_money -= money[i];
        } else {                            // 모자라면 새로 뽑기
            cnt++;
            now_money = k - money[i];
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d", &N, &M);

    int lo = 0;     // 하루 금액 중 최댓값
    int hi = 0;     // 전체 합
    for (int i = 0; i < N; i++) {
        scanf("%d", &money[i]);
        hi += money[i];
        if (money[i] > lo) lo = money[i];
    }

    int ans = hi;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (count(mid) <= M) {              // 된다 → 더 작은 K 시도
            ans = mid;
            hi = mid - 1;
        } else {                            // 안 된다 → K 키우기
            lo = mid + 1;
        }
    }
    printf("%d", ans);
    return 0;
}
