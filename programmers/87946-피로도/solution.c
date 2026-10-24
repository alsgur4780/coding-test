#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int chk[10] = {0,};
int answer = -1;
    

int dfs(int** dungeons, int k, int cnt, int dungeons_rows){
    if (cnt > answer) answer = cnt;               // 지금까지 간 개수로 최댓값 갱신

    for (int i = 0; i < dungeons_rows; i++) {
        if (chk[i]) continue;                  // 이미 간 던전
        if (k < dungeons[i][0]) continue;                  // 최소 필요 피로도가 부족하면 못 감

        chk[i] = 1;                       // 들어감
        dfs(dungeons, k - dungeons[i][1], cnt + 1, dungeons_rows);            // 피로도 깎고 다음 던전 고르러
        chk[i] = 0;                       // 되돌리기 (다른 순서도 해보려고)
    }
    
}

// dungeons_rows는 2차원 배열 dungeons의 행 길이, dungeons_cols는 2차원 배열 dungeons의 열 길이입니다.
int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    dfs(dungeons, k, 0, dungeons_rows);
    
    return answer;
}
