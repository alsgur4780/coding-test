#include <string>
#include <vector>
#include <cstdio>
#include <queue>

#define MAX 10000 

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; // 경과시간
    int truck_cnt = truck_weights.size();   // 트럭 갯수
    int total_weight = 0;   // 현재 다리위 무게합
    queue<int> bridge_truck;    // 다리위 트럭
    int truck_time[MAX] = {0,}; // 트럭 이동 시간
    int cnt_ready = 0;  // 대기트럭 순번
    int cnt_bridge = 0; // 다리위 트럭 선두
    
    while (!bridge_truck.empty() || cnt_ready < truck_cnt) {    // 다리를 건너는 트럭과 대기 트럭이 하나라도 있는 경우
        answer++;   // 경과 시간 추가ㅣ
        
        for (int i = cnt_bridge; i < cnt_ready; i++){    // 다리위 트럭 한칸 씩 이동
            truck_time[i]++;
            if(truck_time[i] == bridge_length){ // 다리를 지난경우
                total_weight -= truck_weights[i];   // 다리위 무게합 제거
                cnt_bridge++;   // 선두 뒤로 넘김
                bridge_truck.pop(); // 다리위 트럭 큐 제거
            }
        }
        
        // 다리위 무게와 트럭개수가 충분한 경우
        if (cnt_ready < truck_cnt && (total_weight + truck_weights[cnt_ready] <= weight) && bridge_truck.size() < bridge_length){    
            bridge_truck.push(truck_weights[cnt_ready]);  // 다리위 트럭 큐에 추가
            total_weight += truck_weights[cnt_ready];    // 다리 위 무게 합 추가
            cnt_ready++;    // 대기 트럭 순번 +1
            
        } 
        
    }
    
    
    return answer;
}
