#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int coins[10001];
int dp[10001];
int N, K;




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> coins[i];
    }
    for (int i = 1; i <= K; i++) {
        dp[i] = 123456789;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = coins[i]; j <= K; j++) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    if (dp[K] == 123456789)cout << -1;
    else cout << dp[K];
    

    return 0;
}
