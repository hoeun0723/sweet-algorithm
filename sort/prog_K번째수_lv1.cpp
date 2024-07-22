#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
   
    
    for(auto item : commands){
         vector<int> slice;
        
        for(int i=item[0]-1;i<item[1];i++){
            
            slice.push_back(array[i]);
            
            
        }
        stable_sort(slice.begin(),slice.end());
        
       
        answer.push_back(slice[item[2]-1]);
       
        
        
        
        
    }
    
    
    return answer;
}