#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
set<pair<int, int>> avoid;
int cnt = 0;

void findIcecream(vector<int> t, int previous) {

	if (t.size() == 3) {

		for (int i = 0; i < 2; ++i) {
			for (int j = i + 1; j < 3; ++j) {
				
				auto it = avoid.find({t[i], t[j]});

				if (it != avoid.end())
					return;
			}
		}
		cnt++;
		return;
	}

	for (int i = previous + 1; i <= N; ++i) {
		t.push_back(i);
		findIcecream(t, i);
		t.pop_back();
	}
}

int main() {

	cin >> N >> M;
	
	for (int i = 0; i < M; ++i) {

		int a, b; cin >> a >> b;

		if (a > b)
			avoid.insert({ b, a });
		else
			avoid.insert({ a, b });
	}

	findIcecream({}, 0);
	cout << cnt << "\n";

	return 0;
}