#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
int H, W;
int answer = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    cin >> H >> W;
    vector<int> v(W);
    for (int i = 0; i < W; i++)cin >> v[i];

    for (int i = 0; i < W; i++) {
        int left = 0;
        int right = 0;
        for (int j = 0; j < i; j++)left = max(left, v[j]);
        for (int j = W - 1; j > i; j--) right = max(right, v[j]);
        answer += max(0, min(left, right) - v[i]);
    }
    cout << answer << '\n';

    

    return 0;
}
