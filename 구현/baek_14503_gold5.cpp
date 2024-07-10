#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int N, M;
int r, c, d;
int map[50][50];
int visited;
int visited_map[50][50] = { 0, };
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void clean_robot() {
    for (int i = 0; i < 4; i++) {
        int change_dir = (d + 3 - i) % 4;
        int change_r = r + dx[change_dir];
        int change_c = c + dy[change_dir];

        if (change_r < 0 || change_c < 0 || change_r >= N || change_c >= M) {
            continue;
        }

        if (map[change_r][change_c] == 0 && visited_map[change_r][change_c] == 0) {
            visited_map[change_r][change_c] = 1;
            
            r = change_r;
            c = change_c;
            d = change_dir;
            visited++;
            clean_robot();
        }
    }

    int back = 0;
    if (d > 1)
        back = d - 2;
    else
        back = d + 2;
    int back_r = r + dx[back];
    int back_c = c + dy[back];

    if (back_r >= 0 || back_r <= N || back_c >= 0 || back_c <= M) {
        if (map[back_r][back_c] == 0) {
            r = back_r;
            c = back_c;
            clean_robot();
        }
        else {
            cout << visited << '\n';
            exit(0);
        }
    }


   

}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    visited_map[r][c] = 1;
    visited++;

    clean_robot();
   

    

    return 0;
}
