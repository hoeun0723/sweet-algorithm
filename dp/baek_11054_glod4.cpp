#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int N;
int arr[1001];
int dp_front[1001];
int dp_back[1001];
int answer;




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        dp_front[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (arr[j] < arr[i] && dp_front[i] < dp_front[j] + 1) {
                dp_front[i] = dp_front[j] + 1;
            }
        }
    }
    for (int i = N; i >= 1; i--) {
        dp_back[i] = 1;
        for (int j = N; j >= i; j--) {
            if (arr[i] > arr[j] && dp_back[j] + 1 > dp_back[i]) {
                dp_back[i] = dp_back[j] + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (answer < dp_front[i] + dp_back[i] - 1) answer = dp_front[i] + dp_back[i] - 1;
    }
    cout << answer << '\n';
  

    return 0;
}
