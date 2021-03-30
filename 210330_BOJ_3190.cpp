#include <iostream>
#include <memory.h>
#include <vector>
#include <deque>

using namespace std;

int main() {

	int N;
	cin >> N;

	bool isApple[101][101];
	memset(isApple, false, sizeof(isApple));
	int x, y;
	int K;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> x >> y;
		isApple[x][y] = true;
	}

	char command;
	int L;
	cin >> L;
	vector<pair<int, char>> orders;
	for (int i = 0; i < L; ++i) {
		cin >> x >> command;
		orders.push_back({ x, command });
	}
	orders.push_back({0, 'N'});

	int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	int head = 1;
	x = y = 1;
	int oIndex = 0;
	deque<pair<int, int>> dq;
	dq.push_back({ 1, 1 });

	int seconds = 1;
	while (1) {

		int px = x + dir[head][0];
		int py = y + dir[head][1];

		if (px <= 0 || px > N || py <= 0 || py > N)
			break;

		bool isSnakeBody = false;
		for (auto it : dq) {
			if (it.first == px && it.second == py) {
				isSnakeBody = true;
				break;
			}
		}

		if (isSnakeBody)
			break;

		x = px, y = py;

		dq.push_front({ x, y });
		if (isApple[x][y]) {
			isApple[x][y] = false;
		}
		else {
			dq.pop_back();
		}

		if (seconds == orders[oIndex].first) {
			if (orders[oIndex].second == 'L') {
				head--;
				if (head < 0)
					head = 3;
				head = head % 4;
			}
			else {
				head = (head + 1) % 4;
			}
			oIndex++;
		}

		seconds++;
	}

	cout << seconds << "\n";
	return 0;
}