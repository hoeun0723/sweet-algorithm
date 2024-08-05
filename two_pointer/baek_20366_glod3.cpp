#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int N;
int answer=0x3f3f3f3f;
int snowman[601];






int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)cin >> snowman[i];
    sort(snowman, snowman + N);
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 3; j < N; j++) {
            int elsa = snowman[i] + snowman[j];
            int left = i + 1;
            int right = j - 1;
            while (left <= right) {
                int anna = snowman[left] + snowman[right];
                answer = min(answer, abs(elsa - anna));
                if (elsa - anna <= 0)right--;
                else left++;
            }
        }
    }
    cout << answer;
   


    return 0;
}
