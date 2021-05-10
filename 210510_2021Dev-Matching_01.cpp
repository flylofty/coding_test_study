#include <iostream>

#include <string>
#include <vector>

using namespace std;

int findRank(int same, int unKnown) {

	int cnt = same + unKnown;
	return (cnt > 1) ? (7 - cnt) : 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer(2);

	bool winLottos[46]{ false };
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