#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    //스코빌 배열 삽입
    for(int num:scoville)
    {
        pq.push(num);
    }
    int count = 0;
    
    
    while(pq.size()>1)
    {
        //현재 가장 작은 음식의 스코빌 지수가 이미 K 이상인지 확인
        if(pq.top()>=K)
        {
            return count;
        }
        
        //작은 값 두개 섞기
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        //새로운 음식 스코빌 계산
        int new_scoville = first+(second*2);
        
        //새로운 스코빌 배열에 삽입
        pq.push(new_scoville);
        
        //섞은 횟수 증가
        count++;
        
      
        
        
    }
    
        //모든 음식가 k이상이 아니면
        return(pq.top()>=K)?count:-1;
  
}