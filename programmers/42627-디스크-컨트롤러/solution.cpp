#include <string>
#include <vector>

using namespace std;

#define MAX 1005

int q_num[505];    // 작업 번호
int q_start[MAX];  // 작업의 요청 시각
int q_time[MAX];   // 작업의 소요 시간

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int cnt = jobs.size();  // 작업 갯수
    int time = 0;   // 시간
    int q_cnt = 0;
    int done = 0;
    int now_num = -1;   // 현재 작업 번호, -1이면 비었음(작업안함)
    int now_time;       // 현재 작업 남은 시간
    int now_start;      // 현재 작업 요청 시각

    while (done < cnt) {
        for (int i = 0; i < cnt; i++) {   // 현재 시간에 투입가능한 작업
            if (time == jobs[i][0]) {
                q_num[q_cnt] = i;
                q_start[q_cnt] = jobs[i][0];
                q_time[q_cnt] = jobs[i][1];
                q_cnt++;
            }
        }

        if (q_cnt > 0 && now_num == -1) {
            int best = 0;

            for (int i = 1; i < q_cnt; i++) { // 큐안에서 우선순위 1등 골라내기
                if (q_time[i] != q_time[best]) {
                    if (q_time[i] < q_time[best])
                        best = i;
                }
                else if (q_start[i] != q_start[best]) {
                    if (q_start[i] < q_start[best])
                        best = i;
                }
                else if (q_num[i] != q_num[best]) {
                    if (q_num[i] < q_num[best])
                        best = i;
                }
            }
            now_num = q_num[best];
            now_time = q_time[best];
            now_start = q_start[best];
            q_cnt--;

            q_num[best] = q_num[q_cnt];
            q_start[best] = q_start[q_cnt];
            q_time[best] = q_time[q_cnt];
        }

        if (now_num != -1) {  // 작업이 진행중
            now_time--;
            if (now_time == 0) { // 작업이 끝남
                answer += (time + 1 - now_start);
                now_num = -1;
                done++;
            }
        }

        time++;
    }

    return answer / cnt;
}
