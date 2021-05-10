#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool winLottos[46]{ false };

int findRank(int same, int unKnown) {

	int cnt = same + unKnown;
	if (cnt == 6) return 1;
	else if (cnt == 5) return 2;
	else if (cnt == 4) return 3;
	else if (cnt == 3) return 4;
	else if (cnt == 2) return 5;
	else return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer(2);

	for (int i = 0; i < win_nums.size(); ++i)
		winLottos[win_nums[i]] = true;

	int unKnown = 0;
	int same = 0;

	for (int i = 0; i < win_nums.size(); ++i) {

		if (lottos[i] == 0) {
			unKnown++;
		}
		else {
			if (winLottos[lottos[i]]) {
				same++;
			}
		}
	}

	answer[0] = findRank(same, unKnown);
	answer[1] = findRank(same, 0);

	return answer;
}

int main() {

	// 0 0 1(O) 25 31(O) 44 == > 2개 ~ 4개
	// 1 6 10 19 31 45

	//vector<int> lottos{ 44, 1, 0, 0, 31, 25 };
	//vector<int> win_nums{ 31, 10, 45, 1, 6, 19 };

	//vector<int> lottos{ 0, 0, 0, 0, 0, 0 };
	//vector<int> win_nums{ 38, 19, 20, 40, 15, 25 };

	vector<int> lottos{ 45, 4, 35, 20, 3, 9 };
	vector<int> win_nums{ 20, 9, 3, 45, 4, 35 };

	vector<int> res = solution(lottos, win_nums);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}

	return 0;
}