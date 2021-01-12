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

int find(int a) {

	if (pack[a] == a)
		return a;
	else 
		return pack[a] = find(pack[a]);
}

bool isSamePack(int a, int b) {

	a = find(a);
	b = find(b);

	if (a == b) 
		return false;

	pack[b] = a;

	return true;
}

void findAnswer() { // 최소신장트리

	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < M; ++i) {

		int a = v[i].second.first;
		int b = v[i].second.second;
		
		bool isNotSame = isSamePack(a, b);

		if (isNotSame) {
			sum += v[i].first;
			cnt++;
		}
		
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