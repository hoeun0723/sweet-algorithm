#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int N, M;
char map[11][11];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int visited[10][10][10][10] = { 0, };


struct BALL {
    int rx, ry, bx, by, cnt;
};
BALL start;
queue<BALL>q;

int bfs() {
    q.push(start);
    visited[start.ry][start.ry][start.bx][start.by];

    int ans = -1;

    while (!q.empty()) {
        BALL curr = q.front(); q.pop();

        if (curr.cnt > 10)break;
        if (map[curr.ry][curr.rx] == 'O' && map[curr.by][curr.bx] != 'O') {
            ans = curr.cnt;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int n_ry = curr.ry;
            int n_rx = curr.rx;
            int n_by = curr.by;
            int n_bx = curr.bx;

            while (1) {
                if (map[n_ry][n_rx] != '#' && map[n_ry][n_rx] != 'O') {
                    n_ry += dy[i];
                    n_rx += dx[i];
                }
                else {
                    if(map[n_ry][n_rx] == '#') {
                    n_ry -= dy[i]; n_rx -= dx[i]; 
                    }
                    break;
                }
            }
            while (1) {
                if (map[n_by][n_bx] != '#' && map[n_by][n_bx] != 'O') {
                    n_by += dy[i];
                    n_bx += dx[i];
                }
                else {
                    if (map[n_by][n_bx] == '#') {
                        n_by -= dy[i]; n_bx -= dx[i];
                    }
                    break;
                }
            }
            if (n_ry == n_by && n_rx == n_bx) {
                if (map[n_ry][n_rx] != 'O') {
                    int r_dist = abs(n_ry - curr.ry) + abs(n_rx - curr.rx);
                    int b_dist = abs(n_by - curr.by) + abs(n_bx - curr.bx);

                    if (b_dist > r_dist) {
                        n_by -= dy[i];
                        n_bx -= dx[i];
                    }
                    else {
                        n_ry -= dy[i];
                        n_rx -= dx[i];
                    }
                }
            }
            if (visited[n_ry][n_rx][n_by][n_bx] == 0) {
                visited[n_ry][n_rx][n_by][n_bx] = 1;
                BALL next;
                next.ry = n_ry;
                next.rx = n_rx;
                next.by = n_by;
                next.bx = n_bx;
                next.cnt = curr.cnt + 1;

                q.push(next);

            }
        }
    }
    return ans;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
            cin >> map[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'R') {
                start.ry = i; start.rx = j;
            }
            if (map[i][j] == 'B') {
                start.by = i; start.bx = j;
            }
        }
    }
    start.cnt = 0;

    int ans = bfs();
    cout << ans << '\n';

    
    

    return 0;
}
