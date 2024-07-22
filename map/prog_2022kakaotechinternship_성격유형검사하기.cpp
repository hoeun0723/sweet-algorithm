#include <string>
#include <vector>
#include <map>

using namespace std;
int score[8] = {0,3,2,1,0,1,2,3};
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char,int> charScore;
    for(int i=0;i<survey.size();i++)
        charScore[survey[i][choices[i]/4]]+=score[choices[i]];
    
    answer += charScore['R']>=charScore['T']?'R':'T';
    answer += charScore['C']>=charScore['F']?'C':'F';
    answer += charScore['J']>=charScore['M']?'J':'M';
    answer += charScore['A']>=charScore['N']?'A':'N';
        
        
    return answer;
}