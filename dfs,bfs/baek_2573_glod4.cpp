#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n,m;
int visited[301][301];
int adj[301][301];
int cnt[301][301];
int dx[4] = {1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool existIce() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] > 0)return true;
        }
    }
    return false;
}

void melted_count(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny <0 || nx >= n || ny >= m)continue;
        if (adj[nx][ny] <= 0)cnt[x][y]++;
    }
}

void melted() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            adj[i][j] = adj[i][j] - cnt[i][j];
        }
    }
}



void dfs(int x,int y) {
    int cnt = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
        if (adj[nx][ny] > 0 && visited[nx][ny] == 0) {
            visited[nx][ny] = 1;
            dfs(nx, ny);
        }
    }

}





int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
            if (adj[i][j] != 0)visited[i][j] = 1;
        }
    }

    int year = 0;
    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = 0;
                cnt[i][j] = 0;
            }
        }
        if (existIce() == false) {
            cout << "0";
            break;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (adj[i][j] > 0 && visited[i][j] == 0) {
                    visited[i][j] = 1;
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        if (cnt > 1) {
            cout << year;
            break;
        }
        year++;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (adj[i][j] > 0)melted_count(i, j);
            }
        }
        melted();
    }




    return 0;
}
