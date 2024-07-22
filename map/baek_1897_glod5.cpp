#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;
int dir_cnt;
string teacher;
string str;
map<string, int> bigoo;

string findLogestWord(string teacher, const set<string>& dic) {
    bigoo[teacher] = teacher.length();
    int maxLength = teacher.length();
    string longestWord = teacher;

    set<string> currentWords;
    currentWords.insert(teacher);



    while (!currentWords.empty()) {
        set<string> nextWords;
        for (const string& word : currentWords) {
            for (char c = 'a'; c <= 'z'; ++c) {
                for (int i = 0; i <= word.length(); ++i) {
                    string newWord = word.substr(0, i) + c + word.substr(i);

                    if (dic.count(newWord) && bigoo.count(word) && bigoo[word] + 1 > bigoo[newWord]) {
                        bigoo[newWord] = bigoo[word] + 1;
                        nextWords.insert(newWord);
                        if (bigoo[newWord] > maxLength) {
                            maxLength = bigoo[newWord];
                            longestWord = newWord;
                        }
                    }
                }
            }
        }
        currentWords = nextWords;
    }
    return longestWord;
}





int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> dir_cnt >> teacher;


    set<string> dic;
    for (int i = 0; i < dir_cnt; ++i) {
        
        cin >> str;
        dic.insert(str);
    }
      
    string result = findLogestWord(teacher, dic);

    cout << result << '\n';




    return 0;
}
