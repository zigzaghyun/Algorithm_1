#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    //고유한 포켓몬 저장
    unordered_set<int> unique_pokemon(nums.begin(), nums.end());
    //선택할 수 있는 폰켓몬 종류 최대 개수 구하기
    size_t max_types = nums.size()/2;
    
    int answer = 0;
    return min(unique_pokemon.size(), max_types);
}