#include<vector>
#include <cstdio>
#define NMAX 105

using namespace std;

int chk[NMAX][NMAX];

int dy[4] ={0,1,0,-1};
int dx[4] ={1,0,-1,0};

int qy[NMAX * NMAX], qx[NMAX * NMAX];
int head = 0, tail= 0;


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    int stop = 0;
    
    qy[0] = 0;
    qx[0] = 0;
    tail++;
    chk[0][0] = 1;
    
    while(head < tail){
        int ny = qy[head];
        int nx = qx[head];
        head++;
        
        for(int d = 0; d < 4; d++){
            int cy = ny + dy[d];
            int cx = nx + dx[d];
            
            if (0 <= cy && cy < n && 0 <= cx && cx < m){
                if(maps[cy][cx] == 1 && chk[cy][cx] == 0){
                    if(cy == n - 1 && cx == m - 1){
                        answer = chk[ny][nx] + 1;
                        return answer; 
                    }
                    else {
                        chk[cy][cx] = chk[ny][nx] + 1;
                        qy[tail] = cy;
                        qx[tail] = cx;
                        tail++;
                    }
                }
            }
        }
    }
    return -1;
}
