#include <iostream>
#include <string>

using namespace std;

int M, N;
string s[1000];
bool check[1000][1000];
int dx[4]{ -1, 0, 1, 0 };
int dy[4]{ 0, 1, 0, -1 };
bool isReached = false;

void DFS(int a, int b) {
	
	check[a][b] = true;

	if (a == M - 1)
		isReached = true;

	for (int i = 0; i < 4; ++i) {

		int x = a + dx[i];
		int y = b + dy[i];

		if (x < 0 || x >= M || y < 0 || y >= N)
			continue;

		if (s[x][y] == '0' && !check[x][y])
			DFS(x, y);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> M >> N;
	for (int i = 0; i < M; ++i)
		cin >> s[i];

	for (int i = 0; i < s[0].size(); ++i) {

		if (s[0][i] == '0' && !check[0][i]) {
			DFS(0, i);
		}
	}

	if (isReached)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}