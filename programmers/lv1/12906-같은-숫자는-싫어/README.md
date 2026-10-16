# 같은 숫자는 싫어

- 링크: https://school.programmers.co.kr/learn/courses/30/lessons/12906
- 사이트 / 난이도: 프로그래머스 / Lv.1
- 유형: 스택/큐, 구현
- 푼 날짜: 2026-10-16

## 풀이 아이디어
직전에 넣은 숫자(`num`)를 기억해 두고, 현재 숫자가 그것과 다를 때만 `answer`에 넣는다.
연속으로 같은 숫자만 지우면 되므로 바로 앞 값과만 비교하면 된다.

## 시간 / 공간 복잡도
- 시간: O(N), 배열을 한 번 순회
- 공간: O(N), 결과 배열

## 헷갈렸던 점, 배운 점
- `num` 변수 없이 `answer.back()`과 비교해도 같은 결과다.
- `std::unique`를 쓰면 한 줄로도 풀 수 있다: `arr.erase(unique(arr.begin(), arr.end()), arr.end());`
