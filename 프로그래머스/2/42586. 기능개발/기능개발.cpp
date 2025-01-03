//너무 어렵...
//남은 일 수 필요. 작업 순서대로 배포됨.
//앞 작업보다 빨리 완료되더라고, 앞 작업이 완료될 때 함 께 배포됨
//남은일수를 저장하고, 순서대로 배포 처리됨


#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector <int> answer;
    queue <int> days; //작업 완료 일 수 저장
    
    
    //작업 완료 일 수 계산해서 큐에 넣기
    for(size_t i=0; i<progresses.size(); i++)
    {
        int remaining = 100 -progresses[i];
        //작업 완료에 필요한 일수
        int day = ceil((double)remaining/speeds[i]);
        days.push(day);
    }
    //배포 단위 계산
    //현재
    while(!days.empty())
    {
        int current = days.front();
        days.pop();
        //현재 배포되는 작업 수
        int count = 1;
    
        //같은 배포에 포함될 작업 수 계산
        while(!days.empty() && days.front() <=current)
        {
            count++;
            days.pop();
        }
        //배포된 작업 수
        answer.push_back(count);
    }
    
    return answer;
}