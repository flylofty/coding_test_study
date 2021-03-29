#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
int N, Min = INF;
vector<int> p(10);
vector<int> e[10];
vector<bool> t(10, false);
queue <int> q;

bool isConnected(int& start) {

	int cnt = 0;
	vector<bool> check(N, false);
	q.push(start);
	check[start] = true;

	while (!q.empty()) {

		int x = q.front();
		q.pop();

		if (t[start] == t[x])
			cnt++;

		for (int i = 0; i < e[x].size(); ++i) {
			int y = e[x][i];

			if (!check[y] && t[x] == t[y]) {
				q.push(y);
				check[y] = true;
			}
		}
	}

	int realCnt = 0;
	for (int i = 0; i < N; ++i) {
		if (t[start] == t[i])
			realCnt++;
	}

	return cnt == realCnt;
}

void findAnswer(int cnt, int pre) {

	if (0 < cnt && cnt <= (N / 2)) {

		int firstFalse = 0;
		while (t[firstFalse])
			firstFalse++;

		int firstTrue = 0;
		while (!t[firstTrue])
			firstTrue++;

		if (isConnected(firstFalse) && isConnected(firstTrue)) {
			int a = 0, b = 0;
			for (int i = 0; i < N; ++i) {
				if (t[i])
					a += p[i];
				else
					b += p[i];
			}

			Min = min(Min, abs(a - b));
		}

		if (cnt == N / 2)
			return;
	}

	for (int i = pre + 1; i < N; ++i) {
		t[i] = true;
		findAnswer(cnt + 1, i);
		t[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> p[i];

	for (int i = 0; i < N; ++i) {
		int m; cin >> m;
		for (int j = 0; j < m; ++j) {
			int num; cin >> num;
			e[i].push_back(num - 1);
		}
	}

	findAnswer(0, -1);

	if (Min != INF)
		cout << Min << "\n";
	else
		cout << "-1\n";

	return 0;
}