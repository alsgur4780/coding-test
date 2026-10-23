#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

int chk[MAX][MAX] = {0,};

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int qy[MAX*MAX];
int qx[MAX*MAX];

// maps_len은 배열 maps의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* maps[], size_t maps_len) {
    int answer = 0;
    int M;

    int sy, sx, ly, lx, ey, ex;
    int laver = 0;

    for(int j = 0; j < maps_len; j++){
        for(int i = 0; maps[j][i] != '\0'; i++){
            if(maps[j][i] == 'S'){
                sy = j; sx = i;
            }
            else if(maps[j][i] == 'L'){
                ly = j; lx = i;
            }
            else if(maps[j][i] == 'E'){
                ey = j; ex = i;
            }
            M = i + 1;
        }
    }

    int head = 0;
    int tail = 0;

    qy[tail] = sy;
    qx[tail] = sx;
    tail++;

    chk[sy][sx] = 1;

    while (laver == 0 && head < tail){     // 레버 올리기전
        int ny = qy[head];
        int nx = qx[head];
        head++;

        for(int d = 0; d < 4; d++){
            int cy = ny + dy[d];
            int cx = nx + dx[d];

            if(0 <= cy && cy < maps_len && 0 <= cx && cx < M){
                if(maps[cy][cx] != 'X' && chk[cy][cx] == 0){
                    qy[tail] = cy;
                    qx[tail] = cx;
                    tail++;
                    chk[cy][cx] = chk[ny][nx] + 1;

                    if(cy == ly && cx == lx){
                        laver = 1;
                        answer += chk[cy][cx] - 1;
                        break;
                    }
                }
            }
        }
    }

    if(laver == 0)
        return -1;

    for(int j = 0; j < maps_len; j++){
        for(int i = 0; i < M; i++){
            chk[j][i] = 0;
        }
    }

    head = 0;
    tail = 0;

    qy[tail] = ly;
    qx[tail] = lx;
    tail++;

    chk[ly][lx] = 1;

    int find_end = 0;

    while (head < tail){    // 레버 올린후
        int ny = qy[head];
        int nx = qx[head];
        head++;

        for(int d = 0; d < 4; d++){
            int cy = ny + dy[d];
            int cx = nx + dx[d];

            if(0 <= cy && cy < maps_len && 0 <= cx && cx < M){
                if(maps[cy][cx] != 'X' && chk[cy][cx] == 0){
                    qy[tail] = cy;
                    qx[tail] = cx;
                    tail++;
                    chk[cy][cx] = chk[ny][nx] + 1;

                    if(cy == ey && cx == ex){
                        answer += chk[cy][cx] - 1;
                        find_end = 1;
                        break;
                    }
                }
            }
        }
    }

    if(find_end == 0)
        return -1;

    return answer;
}
