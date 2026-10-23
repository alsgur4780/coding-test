#include <cstdio>
#include <algorithm>
using namespace std;

int N;
long long num[2005];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lld", &num[i]);

    sort(num, num + N);

    int cnt = 0;
    for (int k = 0; k < N; k++) {          // k: 좋은 수인지 검사할 대상
        int i = 0, j = N - 1;               // 양 끝에서 시작
        while (i < j) {
            if (i == k) { i++; continue; }  // 자기 자신은 못 씀
            if (j == k) { j--; continue; }
            long long s = num[i] + num[j];
            if (s == num[k]) { cnt++; break; }  // 찾았으면 세고 다음 k로
            else if (s < num[k]) i++;           // 합이 작으면 작은 쪽을 키움
            else j--;                           // 합이 크면 큰 쪽을 줄임
        }
    }
    printf("%d", cnt);
    return 0;
}
