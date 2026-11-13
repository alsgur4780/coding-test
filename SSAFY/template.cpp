// SSAFY 적성진단 / SWEA 형식 기본 템플릿 (Visual Studio 2017 Express에서 그대로 컴파일됨)
//
// 1) MSVC(VS2017)에는 <bits/stdc++.h>가 없다 → 필요한 헤더를 직접 include
// 2) scanf 쓰면 VS가 "unsafe" 에러를 냄 → 맨 위 #define 한 줄로 해결
// 3) 입력: 첫 줄 T(테스트케이스 수), 출력: "#번호 답"
// 4) 로컬 테스트할 때만 freopen 주석 해제, 제출할 땐 꼭 다시 주석!

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int map_[20][20];   // 'map'은 std::map과 이름이 겹치니 피하기

int main() {
    // freopen("input.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        // ★ 테스트케이스마다 전역 변수/배열 초기화 잊지 말기
        memset(map_, 0, sizeof(map_));

        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &map_[i][j]);

        int answer = 0;
        // 풀이 작성

        printf("#%d %d\n", tc, answer);
    }
    return 0;
}
