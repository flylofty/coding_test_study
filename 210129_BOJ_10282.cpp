#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
int T = 0;
int n, d, c;
vector<vector<pair<int, int>>> v;

void input() {

	v.assign(n + 1, vector<pair<int, int>>());
	for (int i = 0; i < d; ++i) {
		int n1, n2, seconds;
		cin >> n2 >> n1 >> seconds;
		v[n1].push_back({ seconds, n2 });
	}
}

// 다익스트라ㅠㅠ
void findAnswer() {
	
	vector<int> D(n + 1, 987654321);
	D[c] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, c});

	while (!pq.empty()) {
		
		int weight = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[x].size(); ++i) {
			int time = weight + v[x][i].first;
			int y = v[x][i].second;

			if (D[y] > time) {
				D[y] = time;
				pq.push({ time, y });
			}
		}
	}

	int cnt = 0;
	int Max = -1;;
	for (int i = 1; i < D.size(); ++i) {
		if (D[i] == INF) continue;

		if (D[i] >= 0)
			cnt++;

		if (D[i] > Max) {
			Max = D[i];
		}
	}

	cout << cnt << " " << Max << "\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;

	while (T--) {

		cin >> n >> d >> c;
		input();
		findAnswer();
	}

	return 0;
}

// DFS 망...ㅠㅠ
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int T = 0;
//int n, d, c;
//vector<vector<pair<int, int>>> v;
//vector<bool> visit;
//vector<int> D;
//int hacked = 0;
//int seconds = 0;
//
//// DFS
//void findAnswer(int start, int sum) {
//
//	if (visit[start] == true) {
//		if (D[start] > sum)
//			D[start] = sum;
//		return;
//	}
//	else {
//		visit[start] = true;
//		hacked++;
//	}
//
//	if (D[start] > sum)
//		D[start] = sum;
//
//	for (int i = 0; i < v[start].size(); ++i) {
//
//		findAnswer( v[start][i].second, v[start][i].first + sum );
//	}
//}
//
//void input() {
//
//	v.assign(n + 1, vector<pair<int, int>>());
//	visit.assign(n + 1, false);
//	D.assign(n + 1, 987654321);
//	D[c] = 0;
//
//	for (int i = 0; i < d; ++i) {
//		int n1; pair<int, int> p;
//		cin >> p.second >> n1 >> p.first;
//		v[n1].push_back(p);
//	}
//
//	for (int i = 1; i < v.size(); ++i) {
//		if (v[i].empty()) continue;
//		sort(v[i].begin(), v[i].end());
//	}
//
//	hacked = 0;
//	seconds = 0;
//}
//
//int main() {
//
//	ios::sync_with_stdio(false);
//	cin.tie(NULL), cout.tie(NULL);
//	cin >> T;
//
//	while (T--) {
//
//		cin >> n >> d >> c;
//		input();
//		findAnswer(c, 0);
//
//		cout << hacked << " " << seconds << "\n";
//	}
//
//	return 0;
//}