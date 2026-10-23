#include <vector>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int cnt = jobs.size();
    int used[505] = {0};   // 끝낸 작업 표시
    int time = 0, done = 0, total = 0;

    while (done < cnt) {
        int best = -1;
        for (int i = 0; i < cnt; i++) {   // 도착했고 아직 안 한 작업 중 1등
            if (used[i] || jobs[i][0] > time) continue;
            if (best == -1 || jobs[i][1] < jobs[best][1] ||
               (jobs[i][1] == jobs[best][1] && jobs[i][0] < jobs[best][0]))
                best = i;                 // 번호는 앞에서부터 보니까 자동으로 작은 쪽
        }
        if (best == -1) { time++; continue; }   // 할 일 없으면 1ms 흘려보내기
        time += jobs[best][1];                  // 고른 작업을 끝까지 실행
        total += time - jobs[best][0];
        used[best] = 1;
        done++;
    }
    return total / cnt;
}
