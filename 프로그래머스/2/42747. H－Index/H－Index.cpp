#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    //인용된 횟수 정렬
    sort(citations.rbegin(),citations.rend());
    
    int h_index=0;
    
    //h_index 
    for(int i=0; i<citations.size();i++)
    {
        //논문 인용이 i 이상인 경우
        if(citations[i] >= i+1)
        {
             h_index=i+1;
        }
        else
        {
            break;
        }
        
    }
  
    return h_index;
}