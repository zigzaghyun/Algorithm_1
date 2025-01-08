#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0; // 경과 시간
    int current_weight = 0; // 다리 위 현재 무게
    queue<int> bridge; // 다리 위의 트럭들 무게 저장
    
    for (int i = 0; i < truck_weights.size(); ++i) {
        while (true) {
            // 다리 위의 트럭이 있는지 확인
            // 다리 위에 트럭이 가득 찬 경우
            if (bridge.size() == bridge_length) {  
                // 다리에서 첫 번째 트럭을 빼고
                current_weight = current_weight-bridge.front();  
                // 첫 번째 트럭을 다리에서 빼냄
                bridge.pop();  
            }

            // 다리 위에 트럭을 추가할 수 있는지 확인
            if (current_weight + truck_weights[i] <= weight) {
                // 트럭을 다리 위에 올림
                bridge.push(truck_weights[i]);  
                // 무게 추가
                current_weight =  current_weight +truck_weights[i];  
                break;
            } else {
                // 트럭이 올라갈 수 없으면, 0을 추가/ 시간 증가
                bridge.push(0);  
            }
            // 다리 위에 올리기 전에 시간 1초 증가
            time++;  
        }
        // 트럭 추가한 후 1초 증가
        time++;  
    }
    return time + bridge_length;  
}