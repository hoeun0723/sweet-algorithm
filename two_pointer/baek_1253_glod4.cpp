#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int N;
int A[2001];
int tmp = 0;
int answer = 0;






int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);

    if (N < 3) {
        cout << 0;
        return 0;
    }

    
   for(int i=0;i<N;i++){
       int left = 0;
       int right = N - 1;
       while (left < right) {
           int tmp = A[left] + A[right];
           if (tmp < A[i]) {
               left++;
           }
           else if (tmp > A[i]) {
               right--;
           }
           else {
               if (left == i)left++;
               else if (right == i)right--;
               else {
                   answer++;
                   break;
               }
           }
      }
    }
   cout << answer;

   


    return 0;
}
