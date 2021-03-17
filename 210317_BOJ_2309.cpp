#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dwarfs(9);
bool check = false;

void findAnswer(vector<int> t, int pre) {

	if (check)
		return;

	if (t.size() == 7) {

		int sum = 0;
		for (int i = 0; i < 7; ++i)
			sum += dwarfs[t[i]];

		if (sum == 100) {
			for (int i = 0; i < 7; ++i)
				cout << dwarfs[t[i]] << "\n";
			check = true;
		}

		return;
	}

	for (int i = pre + 1; i < dwarfs.size(); ++i) {
		t.push_back(i);
		findAnswer(t, i);
		t.pop_back();
	}
}

int main() {

	for (int i = 0; i < 9; ++i) cin >> dwarfs[i];
	sort(dwarfs.begin(), dwarfs.end());
	vector<int> t;
	findAnswer(t, -1);

	return 0;
}