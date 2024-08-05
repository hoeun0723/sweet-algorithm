#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int N, K;
int visited[1000001];
int map[1000001];
vector<int> path;

void bfs(int start, int c) {
    queue<pair<int, int>> q;
    q.push(make_pair(start, c));
    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        visited[now] = 1;
        q.pop();
        if (now == K) {
            int m_now = now;
            while (m_now != N) {
                path.push_back(m_now);
                m_now = map[m_now];
            }
            cout << cnt << '\n';
            break;
        }
        if (now - 1 >= 0 && now - 1 <= 200000 && visited[now - 1] == 0) {
            q.push(make_pair(now - 1, cnt + 1));
            visited[now - 1] = 1;
            map[now - 1] = now;
        }
        if (now + 1 >= 0 && now + 1 <= 200000 && visited[now + 1] == 0) {
            q.push(make_pair(now + 1, cnt + 1));
            visited[now + 1] = 1;
            map[now + 1] = now;
        }
        if (now*2 >= 0 && now * 2 <= 200000 && visited[now * 2] == 0) {
            q.push(make_pair(now * 2, cnt + 1));
            visited[now * 2] = 1;
            map[now * 2] = now;
        }
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    cin >> N >> K;
    bfs(N, 0);
    cout << N << ' ';
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }


    

    return 0;
}
