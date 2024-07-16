#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int M, N;
int arr[501][501];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int dp[501][501];

int dfs(int x, int y) {
    if (x == N - 1 && y == M - 1)return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
            if (arr[nx][ny] < arr[x][y]) {
                dp[x][y] = dp[x][y] + dfs(nx, ny);
            }
        }
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0);

    return 0;
}
