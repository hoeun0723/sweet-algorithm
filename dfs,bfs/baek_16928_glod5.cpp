#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int N, M;
int visited[101];
int map[101];
int x,y;
int u,v;

void game(int start, int c) {
    queue<pair<int, int>> q;
    q.push(make_pair(start, c));
    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for(int i=1;i<=6;i++){
            int m_now = now + i;
            if (m_now == 100) {
                cout << cnt + 1;
                return;
            }
            else if (m_now < 100) {
                while (map[m_now] != 0) {
                    m_now = map[m_now];
                }
                if (!visited[m_now]) {
                    q.push(make_pair(m_now, cnt + 1));
                    visited[m_now] = 1;
                }
            }
        }
    }

}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        map[x] = y;
    }
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        map[u] = v;
    }
    
    game(1, 0);
    
    

    return 0;
}
