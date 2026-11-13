# SSAFY 17기 SW적성진단 대비 (SW전공)

> 본 진단: **2026-11-21(토)** · 1차 13:30~14:50 / 2차 16:30~17:50 (**80분, 2문제**)
> 내 차수는 메일로 안내됨. 차수 변경 신청은 11/19 11:00까지.

## 시험 핵심 정리 (응시 매뉴얼 기준)
- 시스템이 **SWEA와 같은 화면**: 언어 선택 → 코드 창에 붙여넣기 → 컴파일 / TEST(직접 입력 넣어 실행) → 제출(횟수 제한 없음)
- **"Accept" = 제출이 정상 처리됐다는 뜻일 뿐, 정답이라는 뜻이 아님.** 1번이 기준을 넘어야 2번이 열림 → 1번을 정확하고 효율적으로!
- 입출력: 첫 줄 `T`, 테스트케이스마다 `#번호 답` 출력 (프로그래머스 `solution()` 형식 아님)
- 라이브러리: 시스템이 허용하는 범위에서 사용 가능 (STL `queue`, `sort` 등)
- C/C++ 권장 IDE: **Visual Studio 2017 Express** (VSCode, IntelliJ 사용 금지)

## VS2017에서 주의할 점
- `#include <bits/stdc++.h>` **안 됨** → `<cstdio> <cstring> <algorithm> <vector> <queue>` 직접 include
- `scanf` 쓰면 에러 → 파일 맨 위에 `#define _CRT_SECURE_NO_WARNINGS`
- 변수 이름 `map`은 `std::map`과 겹침 → `board`, `map_` 등으로
- 로컬에서 `freopen("input.txt", "r", stdin);` 썼으면 **제출 전에 주석 처리**
- 테스트케이스마다 전역 배열·변수 **초기화** (`memset`)

템플릿: [template.cpp](template.cpp) (기본) · [bfs_template.cpp](bfs_template.cpp) (격자 BFS 최단거리)

## 9일 연습 계획 (전부 SWEA)
링크를 열려면 SWEA 로그인이 필요해요.

**난이도 기준:** 공식 안내는 "SWEA **D2~D3** 연습문제 참고". 합격 후기도 대부분 D1~D3로 준비했고, 2번은 "D3~D4 체감"이라는 후기가 있음.
→ **D3가 중심**, D4는 BFS/DFS/시뮬레이션 기본 문제(문제해결 기본 시리즈)만. 모의 SW 역량테스트(A형)는 선택.

| 날짜 | 주제 | 문제 |
|---|---|---|
| 11/13(금) ✅ | 2차원 배열 기초 | [2001 파리 퇴치](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PzOCKAigDFAUq), [1954 달팽이 숫자](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PobmqAPoDFAUq), [1961 숫자 배열 회전](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pq-OKAVYDFAUq), [1974 스도쿠 검증](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Psz16AYEDFAUq), [1979 어디에 단어가 들어갈 수 있을까](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PuPq6AaQDFAUq) |
| 11/14(토) | 시뮬레이션 | [1210 Ladder1](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14ABYKADACFAYh) (D4 기본), [4615 재미있는 오셀로 게임](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWQmA4uK8ygDFAXj) (D3) |
| 11/15(일) | 문자열 + DFS 기본 | [1215 회문1](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14QpAaAAwCFAYi) (D3), [1219 길찾기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14geLqABQCFAYD) (D4 기본) |
| 11/16(월) | BFS 최단거리 | [1226 미로1](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14vXUqAGMCFAYD), [1227 미로2](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14wL9KAGkCFAYD) (D4 기본) |
| 11/17(화) | **80분 모의 1회** + 사전 OT | SWEA에서 난이도 D3 필터로 안 푼 문제 2개 골라 80분 재고 풀기 |
| 11/18(수) | 오답 복습 | 지금까지 틀렸던 문제 다시 풀기 (2001 범위, 1961 출력, 1974 체크 배열) |
| 11/19(목) | **80분 모의 2회** / 도전 | D3 2문제 80분. 여유 있으면 [1953 탈주범 검거](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq) (모의 역량, 선택) |
| 11/20(금) | 가볍게 + 장비 점검 | D2~D3 1~2문제, VS2017·휴대폰 거치·랜선 최종 점검 |
| 11/21(토) | 본 진단 | 오전엔 템플릿만 한 번 손으로 써 보기 |

## 시험 당일 체크리스트
- [ ] 신분증(실물), 빈 A4 2장, 필기구 1개 — 책상엔 이것만
- [ ] Windows PC + Chrome, **유선 랜**, 모니터 1개, 충전기 연결
- [ ] VS2017 빌드 테스트 완료
- [ ] 휴대폰: Chrome 앱 최신 버전, 세로 거치(얼굴·모니터·양손 보이게), 충전기, 알림·재난문자 끄기
- [ ] 이어폰·스마트워치·모자 X, 방에 혼자 (반려동물도 X)
- [ ] 시험 10분 전 접속, 화장실 미리 (시험 중 불가)
- [ ] 퇴실은 40분 이후 + 감독관 확인 후에만

## 풀 때 전략
1. 문제 2개 다 읽기 → 입력 크기 보고 시간복잡도 감 잡기
2. A4에 예제 손으로 따라가 보기 (구현 문제는 이게 제일 중요)
3. 1번 먼저 완벽하게 → TEST로 예제 + 경계값(최소/최대 크기) 확인 → 제출
4. 2번은 부분이라도 돌아가는 코드부터 → 시간 남으면 최적화
