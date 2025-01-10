#include <string>
#include <vector>
#include <stack>
using namespace std;

//vector<int> solution(vector<int> prices) {
//    int n = prices.size();
//    vector<int> answer(n,0); //주가 저장
//    stack<int> st;
    
    //스택 주가>현재 주가 => 유지 시간 끝
//   for(int i=0; i<n;i++)
//    {
//        while(!st.empty() && prices[st.top()] > prices[i])
//        {
//            int idx = st.top();
//            answer[idx] = i - idx;     //유지시간 계산
//        }
        //현재 인덱스 스택에 추가
//        st.push(i);
//    }
    
//    while(!st.empty())
//    {
//        int idx = st.top();
//        st.pop();
//        answer[idx] = n-1-idx;
//    }
    
//    return answer;
//}
//10초 초과

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);

    for (int i = 0; i < n; i++) {
        int time = 0;
        for (int j = i + 1; j < n; j++) {
            time++;
            //주가가 떨어지면 멈춤
            if (prices[j] < prices[i]) break; 
        }
        answer[i] = time;
    }

    return answer;
}