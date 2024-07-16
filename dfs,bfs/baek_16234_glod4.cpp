#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int N, L, R;
int A[51][51];
bool visited[51][51];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;
int sum = 0;

void clear() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    v.push_back(start);
    sum = A[start.first][start.second];

    while (!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = temp.first + dx[i];
            int ny = temp.second + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]) {
                int diff = abs(A[nx][ny] - A[temp.first][temp.second]);
                if (diff >= L && diff <= R) {
                    q.push({ nx, ny });
                    visited[nx][ny] = true;

                    v.push_back({ nx, ny });
                    sum += A[nx][ny];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int answer = 0;
    bool flag = true;

    while (flag) {
        flag = false;
        clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    v.clear();
                    sum = 0;
                    bfs({ i, j });

                    if (v.size() > 1) {
                        flag = true;
                        int new_population = sum / v.size();
                        for (auto& p : v) {
                            A[p.first][p.second] = new_population;
                        }
                    }
                }
            }
        }
        if (flag) {
            answer++;
        }
    }

    cout << answer;

    return 0;
}
