#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), cmp);
    
    int team[105] = {0,};
    int team_num = 1;
    
    for(int i = 0; i < costs.size(); i++){
        int a = costs[i][0];
        int b = costs[i][1];
        int cost = costs[i][2];
       
        
        if(team[a] == 0 && team[b] == 0){
            answer += cost;
            team[a] = team_num;
            team[b] = team_num;
            team_num++;
        }
        else if (team[a] ==0) {
            team[a] = team[b];
            answer += cost;
        }
        else if (team[b]==0) {
            team[b] = team[a];
            answer += cost;
        }
        else if (team[a] != team[b]) {          // 서로 다른 팀 → 다리 짓고 합치기
            int old = team[b];
            for (int k = 0; k < n; k++)
                if (team[k] == old) team[k] = team[a];   // 팀b 전원을 팀a로
            answer += cost;
        }
        // 같은 팀이면 아무것도 안 함 (이미 이어져 있으니 버림)

    }
    
    
    
    return answer;
}
