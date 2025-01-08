#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    //큐에 프로세스 정보 저장
    queue<pair<int,int>> q;//프로세스 저장 
    vector<int> priority_order; //저장 후 내림차순 정렬
    
    //프로세스 저장
    for(int i=0; i<priorities.size(); i++){
        q.push({priorities[i],i});
        priority_order.push_back(priorities[i]);
    }
     //저장 후 내림차순 정렬
    sort(priority_order.rbegin(), priority_order.rend());
    
    //실행기록
    int order =0;
    
    //큐 처리
    while (!q.empty()) {
        // 큐에서 맨 앞의 프로세스를 가져옴
        auto current = q.front(); 
        q.pop();
        
        // 현재 프로세스의 중요도가 가장 높은 중요도와 같은지 확인
        if (current.first == priority_order[order]) {
            order++; // 실행 순서 증가
            
            // 만약 현재 프로세스가 우리가 찾는 프로세스(location)라면 반환
            if (current.second == location) {
                return order;
            }
        } else {
            // 중요도가 낮다면 다시 큐의 뒤로 보냄
            q.push(current);
        }
    }
    // 정상적인 경우라면 여기까지 도달하지 않음
    return -1; 
}