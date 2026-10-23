#include <stdio.h>

int head[32005], to[100005], nxt[100005], ecnt = 0;
int indeg[32005];
int heap[32005], hsize = 0;

void add_edge(int a, int b) {
    to[ecnt] = b; nxt[ecnt] = head[a]; head[a] = ecnt; ecnt++;
}

void push(int x) {
    int i = ++hsize;
    while (i > 1 && heap[i / 2] > x) { heap[i] = heap[i / 2]; i /= 2; }
    heap[i] = x;
}

int pop(void) {
    int top = heap[1], last = heap[hsize--];
    int i = 1;
    while (i * 2 <= hsize) {
        int c = i * 2;
        if (c + 1 <= hsize && heap[c + 1] < heap[c]) c++;
        if (last <= heap[c]) break;
        heap[i] = heap[c]; i = c;
    }
    heap[i] = last;
    return top;
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) head[i] = -1;
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(a, b);
        indeg[b]++;
    }

    for (int i = 1; i <= N; i++)
        if (indeg[i] == 0) push(i);

    while (hsize > 0) {
        int x = pop();
        printf("%d ", x);
        for (int e = head[x]; e != -1; e = nxt[e]) {
            int y = to[e];
            indeg[y]--;
            if (indeg[y] == 0) push(y);
        }
    }
    return 0;
}
