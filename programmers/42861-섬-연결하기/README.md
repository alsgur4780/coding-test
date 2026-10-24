# [Lv.3] 섬 연결하기

- 링크: https://school.programmers.co.kr/learn/courses/30/lessons/42861
- 사이트 / 난이도: 프로그래머스 / Lv.3
- 유형: 그리디, MST (크루스칼)
- 푼 날짜: 2026-10-24

## 풀이 아이디어 (solution.cpp)
모든 섬을 최소 비용으로 잇는 문제 = 최소 신장 트리(MST). 크루스칼 방식으로 푼다.
1. 다리를 비용이 싼 순서로 정렬한다.
2. 싼 다리부터 보면서, 두 섬이 이미 같은 팀(이미 이어짐)이면 버리고, 아니면 짓고 두 팀을 합친다.

팀 관리는 섬마다 팀 번호(`team[]`)를 붙이는 방식으로 했다.
- 둘 다 팀 없음 → 새 팀 번호
- 한쪽만 팀 있음 → 그 팀에 넣기
- 서로 다른 팀 → 다리 짓고, 한 팀 전원의 번호를 다른 팀 번호로 바꿔서 합치기
- 같은 팀 → 버림

이게 유니온파인드가 하는 일과 같다. 유니온파인드는 팀 전원을 바꾸는 대신 대장 하나만 바꿔서 더 빠르다.

```cpp
int parent[105];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);   // 경로 압축
}
// for (i) parent[i] = i;
// a = find(c[0]), b = find(c[1]); if (a == b) continue; parent[a] = b; answer += c[2];
```

## 시간 / 공간 복잡도
- 정렬 O(E log E), 팀 합치기 한 번에 O(n) → O(E log E + E·n). n ≤ 100이라 충분.

## 헷갈렸던 점, 배운 점
- vector 정렬은 `sort(costs.begin(), costs.end(), cmp)`. `costs[0]`, `costs[n]`은 범위가 아니고, n은 섬 개수지 다리 개수가 아니다.
- 처음 버전은 "두 섬이 둘 다 팀이 있는데 서로 다른 팀"인 경우를 빠뜨려서 두 무리를 잇는 다리를 안 지었다 (랜덤 테스트 절반 이상 오답).
- `if / else if` 사슬이면 하나만 실행되므로 각 블록 끝의 `continue`는 필요 없다.
