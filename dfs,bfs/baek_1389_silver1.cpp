#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int N, M;
vector<int> fnd[101];
int a, b;
int visited[101];
int rs[101][101];

void reset() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            rs[i][j] = 0;
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < fnd[x].size(); i++) {
            int index = fnd[x][i];
            if (visited[index] == 0) {
                visited[index] = 1;
                q.push(index);
                rs[index][start] = rs[x][start] + 1;
                rs[start][index] = rs[start][x] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        fnd[a].push_back(b);
        fnd[b].push_back(a);
    }

    reset();

    int minVal = 2000000000;  
    int result = 0;
    for (int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited)); 
        bfs(i);
    }

    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += rs[i][j];
        }
        if (minVal > sum) {
            minVal = sum;
            result = i;
        }
    }

    cout << result << '\n';

    return 0;
}
