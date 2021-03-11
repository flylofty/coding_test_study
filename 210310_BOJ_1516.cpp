#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> E[501];
int time[501];
int res[501]{0};
int inCount[501]{0};

int init() {
	
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		
		cin >> time[i];
		
		int from;
		while (1) {

			cin >> from;

			if (from == -1)
				break;

			E[from].push_back(i);
			inCount[i]++;
		}
	}

	int Min = 1;
	for (int i = 2; i <= N; ++i) {
		if (inCount[Min] > inCount[i])
			Min = i;
	}

	return Min;
}

void TopologicalSort(int start) {

	res[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < E[x].size(); ++i) {
			int y = E[x][i];
			inCount[y]--;

			if (inCount[y] == 0)
				q.push(y);

			if (res[y] < time[x] + res[x])
				res[y] = time[x] + res[x];
		}
	}

	for (int i = 1; i <= N; ++i)
		cout << res[i] + time[i] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	TopologicalSort(init());
	return 0;
}