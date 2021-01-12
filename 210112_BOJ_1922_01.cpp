#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;
vector <pair<int, pair<int, int>>> v;
vector<int> pack;

void input() {
	cin >> N;
	cin >> M;
	
	pack.assign(N + 1, 0);
	for (int i = 1; i <= N; ++i)
		pack[i] = i;

	for (int i = 0; i < M; ++i) {
		pair<int, pair<int, int>> p;
		cin >> p.second.first >> p.second.second >> p.first;
		v.push_back(p);
	}

	sort(v.begin(), v.end());
}

bool isSamePack(int a, int b) {

	if (pack[a] == pack[b])
		return true;
	else
		return false;
}

void makeSamepack(int a, int b) {
	int Min = min(pack[a], pack[b]);
	int Max = max(pack[a], pack[b]);
	for (int i = 1; i <= N; ++i) {
		if (pack[i] == Max)
			pack[i] = Min;
	}
}

void findAnswer() { // 최소신장트리

	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < M; ++i) {

		int a = v[i].second.first;
		int b = v[i].second.second;
		
		if (isSamePack(a, b)) {
			continue;
		}

		sum += v[i].first;
		cnt++;
		makeSamepack(a, b);

		if (cnt == N - 1)
			break;
	}
	cout << sum << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	findAnswer();
	return 0;
}