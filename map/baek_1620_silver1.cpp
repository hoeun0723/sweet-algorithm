#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
int N,M;
string str;
map<string, int> poketmon;
string name[100001];




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N>>M;
    
    for (int i = 1; i <= N; i++) {
        cin >> str;
        poketmon.insert({ str,i });
        name[i] = str;
    }
    for (int j = 1; j <= M; j++) {
        cin >> str;
        if (isdigit(str[0])) {
            cout << name[stoi(str)] << '\n';
        }
        else {
            cout << poketmon.find(str)->second << '\n';
        }

    }

    return 0;
}
