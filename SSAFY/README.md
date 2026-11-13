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
링크를 열려면 SWEA 로그인이 필요해요. 하루 1~2문제, **80분 안에 2문제** 감각 유지. 실제 시험은 D2~D3 + 실버 수준이라는 후기가 많아서, 모의 역량테스트 문제(11/17~19)는 시간이 오래 걸려도 괜찮아요.

| 날짜 | 주제 | 문제 |
|---|---|---|
| 11/13(금) | 환경 세팅 + 입출력 | VS2017 설치·템플릿 빌드 확인 / [2001 파리 퇴치](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PzOCKAigDFAUq) (D2), [1954 달팽이 숫자](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PobmqAPoDFAUq) (D2) |
| 11/14(토) | 2차원 배열 구현 | [1961 숫자 배열 회전](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pq-OKAVYDFAUq) (D2), [1974 스도쿠 검증](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Psz16AYEDFAUq) (D2) |
| 11/15(일) | 배열 탐색 + 시뮬레이션 | [1979 어디에 단어가 들어갈 수 있을까](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PuPq6AaQDFAUq) (D2), [1210 Ladder1](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14ABYKADACFAYh) (D4) |
| 11/16(월) | BFS/DFS 기본 | [1226 미로1](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14vXUqAGMCFAYD) (D4), [1227 미로2](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14wL9KAGkCFAYD) (D4) |
| 11/17(화) | BFS 응용 + **사전 OT(신청했다면)** | [1953 탈주범 검거](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq) (모의 역량테스트) |
| 11/18(수) | DFS/백트래킹 | [1949 등산로 조성](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq) (모의 역량테스트) |
| 11/19(목) | 완전탐색 + 구현 | [2117 홈 방범 서비스](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V61LqAf8DFAWu) (모의 역량테스트) |
| 11/20(금) | **모의고사 80분** | 안 푼 D2 1개 + 위에서 틀렸던 문제 1개를 80분 재고 풀기 → 오답 복습, 장비 최종 점검. 여유 있으면 도전: [1767 프로세서 연결하기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf) |
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
