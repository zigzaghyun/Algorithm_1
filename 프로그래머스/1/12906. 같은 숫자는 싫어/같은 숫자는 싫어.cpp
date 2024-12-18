#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer; //결과를 저장하는 벡터
    
    //비어있있으면 첫번째 원소 추가
    if(!arr.empty()){
        answer.push_back(arr[0]); //첫 번째 원소에 추가     
    }
    
    //연속되지 않은 원소 추가
    for(int i=1; i<arr.size(); i++){
        if(arr[i] != arr[i-1]){
            answer.push_back(arr[i]);
        }
    }


    return answer;
}


