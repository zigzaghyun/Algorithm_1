#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
	int maxCount = 0;

	sort(dungeons.begin(), dungeons.end());
	do
	{
		int fatigue = k; // 현재 피로도
		int count = 0; // 탐험한 던전 수

		// 던전 순서대로 탐험
		for (const auto& dungeon : dungeons)
		{
			int minFatigue = dungeon[0];
			int cost = dungeon[1];

			// 탐험 가능 여부 
			if (fatigue >= minFatigue)
			{
				fatigue -= cost;
				count++;
			}
			else
			{
				break; // 탐험 불가능하면 중단
			}
		}

		// 최대 탐험 수 갱신
		maxCount = max(maxCount, count);
	}
	while (next_permutation(dungeons.begin(), dungeons.end()));

	return maxCount;
}
