#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
int N;
map<string, int> hello_car_rate;
string str;
vector<int> bye_car_rate;
int cnt = 0;





int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    bye_car_rate.resize(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> str;
        hello_car_rate[str] = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> str;
        bye_car_rate[i] = hello_car_rate[str];

    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (bye_car_rate[i] > bye_car_rate[j]) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << '\n';




    return 0;
}
