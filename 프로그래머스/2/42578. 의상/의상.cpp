#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    //의상입었을 때 1
    int answer = 1;
    
    //종류별 입기 unordered_map
    unordered_map<string,int> a;
    
    //의상정보 저장 vector
    for(int i=0; i<clothes.size(); i++)
        a[clothes[i][clothes[i].size()-1]]++;
    
    //조합으로 입을 때
    for(auto x : a)
        answer = answer * (x.second + 1);
      
    //조합으로 입지 않을 때
    answer = answer-1;
    
    return answer;
}