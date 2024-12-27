#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
     std::sort(lost.begin(), lost.end());
    std::sort(reserve.begin(), reserve.end());
    
    // 여벌 체육복을 가진 학생이 도난당한 경우를 제거
    for (auto it = lost.begin(); it != lost.end();) {
        auto found = find(reserve.begin(), reserve.end(), *it);
        if (found != reserve.end()) {
            reserve.erase(found);
            it = lost.erase(it);
        } else {
            ++it;
        }
    }

    // 체육복 대여 처리
    for (auto it = reserve.begin(); it != reserve.end(); ++it) {
        auto prev = find(lost.begin(), lost.end(), *it - 1);
        auto next = find(lost.begin(), lost.end(), *it + 1);
        if (prev != lost.end()) {
            lost.erase(prev);
        } else if (next != lost.end()) {
            lost.erase(next);
        }
    }

    // 체육복을 가진 학생 수 계산
    return n - lost.size();
}


