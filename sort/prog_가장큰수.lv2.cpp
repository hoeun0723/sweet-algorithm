#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const string &x,const string &y){
    return x+y>y+x;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> strings;
    for(int i=0;i<numbers.size();i++){
        strings.push_back(to_string(numbers[i]));
    }
    sort(strings.begin(),strings.end(),cmp);
    
    for(int i=0;i<numbers.size();i++){
        answer+=strings[i];
    }
    
    if(answer[0]=='0'){
        answer = '0';
    }
    
    
    return answer;
}