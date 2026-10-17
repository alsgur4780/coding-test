// 더 쉬운 풀이: 다리를 길이 bridge_length짜리 큐로 보고 빈 칸은 0으로 채운다.
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    for (int i = 0; i < bridge_length; i++) bridge.push(0);   // 빈 다리

    int time = 0, total = 0, idx = 0;
    while (idx < truck_weights.size()) {
        time++;
        total -= bridge.front();     // 맨 앞 칸이 다리에서 내림
        bridge.pop();

        if (total + truck_weights[idx] <= weight) {   // 올릴 수 있으면 트럭
            bridge.push(truck_weights[idx]);
            total += truck_weights[idx];
            idx++;
        } else {
            bridge.push(0);          // 못 올리면 빈 칸
        }
    }
    return time + bridge_length;     // 마지막 트럭이 다 건너는 시간
}
