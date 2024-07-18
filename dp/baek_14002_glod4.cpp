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
vector<int> dp_num;
int length = 0;




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
            if (arr[j] < arr[i] && dp_front[i] <= dp_front[j]) {
                dp_front[i] = dp_front[j] + 1;
            }
            
        }
        length = max(length, dp_front[i]);
    }
    
   
    cout << length << '\n';
    for (int i = N; i >= 1; i--) {
        if (dp_front[i] == length) {
            dp_num.push_back( arr[i]);
            length--;
        }
    }
    for (int i = dp_num.size() - 1; i >= 0; i--) {
        cout << dp_num[i] << " ";
    }
  

    return 0;
}
