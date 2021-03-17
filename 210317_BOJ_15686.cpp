#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int INF = 987654321;
int N, M;
vector<pair<int, int>> h;
vector<pair<int, int>> c;
int Min = INF;

void input() {
	
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int info; cin >> info;
			if (info == 1) h.push_back({ i, j });
			else if (info == 2) c.push_back({ i, j });
		}
	}
}

void findAnswer(vector<int> t, int pre) {

	if (t.size() == M) {

		int total = 0;
		for (int i = 0; i < h.size(); ++i) {
			int a = h[i].first;
			int b = h[i].second;
			int shortest = INF;

			for (int j = 0; j < t.size(); ++j) {
				int x = c[t[j]].first;
				int y = c[t[j]].second;

				int d = abs(a - x) + abs(b - y);
				if (shortest > d)
					shortest = d;
			}
			total += shortest;
		}

		if (Min > total)
			Min = total;

		return;
	}

	for (int i = pre + 1; i < c.size(); ++i) {
		t.push_back(i);
		findAnswer(t, i);
		t.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	vector<int> t;
	findAnswer(t, -1);
	cout << Min << "\n";
	return 0;
}