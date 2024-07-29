#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

long long answer = 0;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long N, K;
    cin >> N >> K;
    vector<pair<long long, long long>> v(N);
    vector<long long> vv(K);


    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < K; i++) cin >> vv[i];

    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());
    priority_queue<long long> pq;

    int j = 0;
    for (int i = 0; i < K; i++) {
        while (j < N && v[j].first <= vv[i])pq.push(v[j++].second);
        if (pq.size()) {
            answer += pq.top(); pq.pop();
        }
    }
   
    cout << answer << '\n';



    return 0;
}
