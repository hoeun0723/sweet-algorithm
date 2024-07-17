#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int minDP[3] = { 0,0,0 }, maxDP[3] = { 0,0,0 }, input[3], num1, num2;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> maxDP[0] >> maxDP[1] >> maxDP[2];
    minDP[0] = maxDP[0];
    minDP[1] = maxDP[1];
    minDP[2] = maxDP[2];

    for (int i = 1; i < N; i++) {
        cin >> input[0] >> input[1] >> input[2];

        num1 = maxDP[0];
        num2 = maxDP[2];

        maxDP[0] = max(maxDP[0], maxDP[1]) + input[0];
        maxDP[2] = max(maxDP[1], maxDP[2]) + input[2];
        maxDP[1] = max(max(num1, maxDP[1]), num2) + input[1];

        num1 = minDP[0];
        num2 = minDP[2];
        minDP[0] = min(minDP[0], minDP[1]) + input[0];
        minDP[2] = min(minDP[1], minDP[2]) + input[2];
        minDP[1] = min(min(num1, minDP[1]), num2) + input[1];
    }

    cout << max(max(maxDP[0], maxDP[1]), maxDP[2]) << ' ';
    cout << min(min(minDP[0],minDP[1]), minDP[2]);
  

    return 0;
}
