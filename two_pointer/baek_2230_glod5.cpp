#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int N, M;
int A[100001];
int min_answer = 2000000000;






int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int left = 0;
    int right = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A,A+N);
    
    while(left<N && right<N){
        int tmp = A[right] - A[left];
        if (tmp < M) {
            right++;
        }
        else {
            min_answer = min(min_answer, tmp);
            left++;
        }
       
    }
    cout << min_answer;



    return 0;
}
