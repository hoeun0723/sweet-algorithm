#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, v;
int visited[1001];
int adj[1001][1001];
int a, b;

void reset() {
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
}


void dfs(int v) {
    visited[v] = 1;
    cout << v << ' ';
    for (int i = 1; i <= n;i++) {
        if (adj[v][i]==1 && visited[i] == 0) {
            dfs(i);
        }
    }

}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = 1;
    cout << v << ' ';
    while (q.size()) {
       v = q.front();
       q.pop();
       for (int i = 1; i <= n;i++) {
           if (adj[v][i] == 1 && visited[i] == 0) {
               q.push(i);
               visited[i] = 1;
               cout << i << ' ';
           }
        }
    }

}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> v;
    

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    reset();
    dfs(v);
    cout << '\n';
    reset();
    bfs(v);





    return 0;
}
