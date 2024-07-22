#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
int N, M;
int x1, y1, x2, y2;
int board[1206][1206]={0};
int board_num;



//이차원배열에서의 누적합을 알 수 있는 문제 !!
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board_num;
            board[i][j] = board[i - 1][j] + board[i][j - 1] + board_num - board[i - 1][j - 1];
        }
    }
    int result = 0;
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        result = board[x2][y2] - board[x1 - 1][y2] - board[x2][y1 - 1] + board[x1 - 1][y1 - 1];
        cout << result << '\n';

    }

    

    return 0;
}
