#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string board[50];
int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int N;

void swap(int i, int j, int x, int y) {
	char temp = board[i][j];
	board[i][j] = board[x][y];
	board[x][y] = temp;
}

void findMax() {

	int Max = 0;

	for (int i = 0; i < N; ++i) {

		for (int j = 0; j < N; ++j) {

			for (int k = 0; k < 4; ++k) {
				
				int x = i + dir[k][0];
				int y = j + dir[k][1];

				if (x < 0 || x >= N || y < 0 || y >= N)
					continue;

				swap(i, j, x, y);

				char candy = board[x][y];

				// 위로 찾기
				int cnt = 1;
				for (int a = x - 1; a >= 0; --a) {
					if (board[a][y] == candy)
						cnt++;
					else
						break;
				}

				// 아래로 찾기
				for (int a = x + 1; a < N; ++a) {
					if (board[a][y] == candy)
						cnt++;
					else
						break;
				}

				int cnt2 = 1;

				// 왼쪽으로 찾기
				for (int a = y - 1; a >= 0; --a) {
					if (board[x][a] == candy)
						cnt2++;
					else
						break;
				}

				// 오른쪽으로 찾기
				for (int a = y + 1; a < N; ++a) {
					if (board[x][a] == candy)
						cnt2++;
					else
						break;
				}

				Max = max({ Max, cnt, cnt2 });

				swap(i, j, x, y);
			}
		}
	}

	cout << Max;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> board[i];

	findMax();

	return 0;
}