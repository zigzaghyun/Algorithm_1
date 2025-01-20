#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown+yellow; //전체 격자
       for (int height = 1; height <= total / height; ++height) 
       {
           // height 약수
        if (total % height == 0) 
        {  
            int width = total / height; 

            // 노란색 격자가 맞는지 확인
            if ((width - 2) * (height - 2) == yellow) 
            {
                return {width, height};
            }
        }
    }
   
    return {};
}