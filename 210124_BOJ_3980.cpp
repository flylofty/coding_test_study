#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C = 0;
int Max = 0;
vector<vector<int>> v;

void findBest(vector<bool> position, int sum, int cnt) {

	if (cnt == 11 && Max < sum) {
		Max = sum;
		return;
	}

	for (int j = 0; j < 11; ++j) {
		
		if (position[j] || v[cnt][j] == 0) 
			continue;

		position[j] = true;
		findBest(position, sum + v[cnt][j], cnt + 1);
		position[j] = false;

	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> C;

	while (C--) {

		v.assign(11, vector<int>(11));

		for (int i = 0; i < 11; ++i) {
			for (int j = 0; j < 11; ++j) {
				cin >> v[i][j];
			}
		}

		Max = 0;
		vector<bool> position(11, false);
		findBest(position, 0, 0);

		cout << Max << "\n";
	}

	return 0;
}