#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int arr[16][16];
vector<pair<int, int>> Base_Camp;

struct Man {
    int x;
    int y;
};
Man person[31];
int pos[16][16];

int dist[31][16][16];

struct Data {
    int id;
    int x;
    int y;
};
Data store[31];
int arrive[31];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

pair<int, int> bfs(int n) {
    int visited[16][16] = {0};

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[n][i][j] = 9999;
        }
    }

    queue<pair<pair<int, int>, int>> q;
    q.push({{store[n].x, store[n].y}, 0});
    dist[n][store[n].x][store[n].y] = 0;
    visited[store[n].x][store[n].y] = 1;

    int min_dist = 9999;
    int min_x = 9999;
    int min_y = 9999;

    while (!q.empty()) {
        int px = q.front().first.first;
        int py = q.front().first.second;
        int cur_dist = q.front().second;
        q.pop();

        if (arr[px][py] == 1) {
            if (dist[n][px][py] < min_dist) {
                min_dist = dist[n][px][py];
                min_x = px;
                min_y = py;
            } else if (dist[n][px][py] == min_dist) {
                if (px < min_x) {
                    min_x = px;
                    min_y = py;
                } else if (px == min_x) {
                    if (py < min_y) {
                        min_y = py;
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = px + dx[i];
            int ny = py + dy[i];

            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if (pos[nx][ny] == -1) continue;
            if (visited[nx][ny] == 1) continue;

            visited[nx][ny] = 1;
            dist[n][nx][ny] = cur_dist + 1;
            q.push({{nx, ny}, cur_dist + 1});
        }
    }

    return {min_x, min_y};
}

void move_person(int time) {
    for (int i = 1; i <= M; i++) {
        if (arrive[i] == true || i >= time) continue;

        pair<int, int> best = bfs(i);
        int min_dist = 9999, gx = -1, gy = -1;

        for (int j = 0; j < 4; j++) {
            int nx = person[i].x + dx[j];
            int ny = person[i].y + dy[j];
            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if (pos[nx][ny] == -1) continue;
            if (dist[i][nx][ny] < min_dist) {
                min_dist = dist[i][nx][ny];
                gx = nx;
                gy = ny;
            }
        }
        person[i].x = gx;
        person[i].y = gy;
    }
}

void check_store() {
    for (int i = 1; i <= M; i++) {
        if (arrive[i] == 1) continue;
        if (store[i].x == person[i].x && store[i].y == person[i].y) {
            pos[store[i].x][store[i].y] = -1;
            arrive[i] = 1;
        }
    }
}

void input_person(int time) {
    pair<int, int> best = bfs(time);
    person[time].x = best.first;
    person[time].y = best.second;
    pos[best.first][best.second] = -1;
}

bool game_finish() {
    for (int i = 1; i <= M; i++) {
        if (arrive[i] == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) Base_Camp.push_back({i, j});
        }
    }
    for (int i = 1; i <= M; i++) {
        store[i].id = i;
        cin >> store[i].x >> store[i].y;
    }

    int time = 1;
    while (true) {
        move_person(time);
        check_store();

        if (game_finish() == true) break;

        if (time <= M) {
            input_person(time);
        }
        time++;
    }
    cout << time;

    return 0;
}
