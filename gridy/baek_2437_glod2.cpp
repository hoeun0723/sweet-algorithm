#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int N;
int arr[10001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int answer = 1;
    for (int i = 0; i < N; i++) {
        if (arr[i] > answer) break;
        answer += arr[i];
    }

    cout << answer;

    return 0;
}
