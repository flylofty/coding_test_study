#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cow(11);

int main() {

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int c, p; cin >> c >> p;
		cow[c].push_back(p);
	}

	int cnt = 0;
	for (int i = 1; i <= 10; ++i) {
		
		if (cow[i].size() <= 1)
			continue;

		int sum = 0;
		for (int j = 1; j < cow[i].size(); ++j) {
			if (cow[i][j - 1] != cow[i][j])
				sum++;
		}
		cnt += sum;
	}

	cout << cnt << "\n";

	return 0;
}