#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int des = 0;
bool isFinished = false;

void findAnswer(int start, vector<bool> check, vector<int> answer) {

	if (isFinished)
		return;

	if (answer.size() == des) {
		for (int i = 0; i < des; ++i)
			cout << answer[i] << " ";
		cout << "\n";
		isFinished = true;
	}

	string temp;
	for (int i = start + 1; i < start + 3 && i < s.size(); ++i) {
		temp += s[i];
		int num = stoi(temp);

		if (num > des)
			continue;

		if (!check[num]) {
			vector<int> v = answer;
			v.push_back(num);
			check[num] = true;
			findAnswer(i, check, v);
			check[num] = false;
			v.pop_back();
		}

	}
}

int main() {

	cin >> s;

	vector<bool> check;

	if (s.size() <= 9) {
		des = s.size();
		check.assign(des + 1, false);
	}
	else {
		des = 9 + (s.size() - 9) / 2;
		check.assign(des + 1, false);
	}
	check[0] = true;

	vector<int> answer;

	findAnswer(-1, check, answer);

	return 0;
}