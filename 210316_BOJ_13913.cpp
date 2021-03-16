#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int Max = 100000 + 1;
int from, to, cnt;
vector<int> v(Max, 0);
bool visit[Max]{ false };
queue<pair<int,int>> q;
int dir[3]{ 2, -1, 1 };
vector<int> res;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> from >> to;
	q.push({ from , 0 });

	while (!q.empty()) {

		int x = q.front().first;
		cnt = q.front().second;
		q.pop();

		if (x == to) 
			break;

		for (int i = 0; i < 3; ++i) {

			int n_x;

			if (i == 0) {
				n_x = x * dir[i];
			}
			else {
				n_x = x + dir[i];
			}

			if (0 > n_x || n_x > Max)
				continue;

			if (visit[n_x])
				continue;
			
			visit[n_x] = true;
			q.push({ n_x , cnt + 1 });
			v[n_x] = x;
		}
	}

	int index = to;
	res.push_back(to);

	while (index != from) {

		res.push_back(v[index]);
		index = v[index];
	}

	cout << cnt << "\n";
	for (int i = res.size() - 1; i >= 0; --i)
		cout << res[i] << " ";
	cout << "\n";

	return 0;
}